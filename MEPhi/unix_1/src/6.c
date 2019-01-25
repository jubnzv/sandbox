#include <errno.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <unistd.h>

#include "6.h"

static void print_usage(const char *argv0)
{
    printf("Usage: %s N M L\n", argv0);
}

// ring0 processes functions
static int r0_play_P(uint16_t proc_num, uint16_t M, uint16_t L, uint16_t *P);

int main(int argc, char const *argv[])
{
    uint16_t N = 0, M = 0, L = 0;
    uint16_t winner_num;
    pid_t *r0_pids;
    struct sigaction sa;
    int fd[2]; // Socket pair: communication between parent and children
    bool first_init = false; // First process of ring0 get M from parent at init
    int shmid;               // ring0 shared memory
    int semid;               // Set of ring0 semaphores
    ring0_shm_t *shmp;

    if (argc != 4) {
        print_usage(argv[0]);
        exit(-1);
    }

    // Parse CLI arguments
    if (sscanf(argv[1], "%hu", &N) != 1) {
        print_usage(argv[0]);
        exit(-1);
    }
    if (sscanf(argv[2], "%hu", &M) != 1) {
        print_usage(argv[0]);
        exit(-1);
    }
    if (sscanf(argv[3], "%hu", &L) != 1) {
        print_usage(argv[0]);
        exit(-1);
    }

    // Initialize ring0 elements
    if ((r0_pids = malloc(N * sizeof(pid_t))) == NULL) {
        perror("malloc ring0 pids");
        exit(-1);
    }

    // Initialize sockets between parent and 0-th ring
    if (socketpair(PF_LOCAL, SOCK_STREAM, 0, fd) == -1) {
        perror("socketpair");
        exit(-1);
    }

    // Initialize ring0 semaphores
    // FIXME: Use `ipcsrm' first
    if ((semid = semget(SEM_KEY_R0, N, IPC_CREAT | OBJ_PERMS)) == -1) {
        perror("semget");
        exit(-1);
    }
    // First process starts first
    if (sem_init_available(semid, 0)) {
        perror("sem_init_available");
        exit(-1);
    }
    for (uint16_t i = 1; i < N; i++) {
        if (sem_init_in_use(semid, i)) {
            perror("sem_init_in_use");
            exit(-1);
        }
    }

    // Initialize shared memory between 0-th ring processes
    if ((shmid = shmget(SHM_KEY, sizeof(ring0_shm_t), IPC_CREAT | OBJ_PERMS)) ==
        -1) {
        perror("shmget");
        exit(-1);
    }
    if ((shmp = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat");
        exit(-1);
    }

    sa.sa_flags = 0;
    sa.sa_handler = sig_chld;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(-1);
    }

    for (uint16_t proc_num = 0; proc_num < N; proc_num++) {
        switch (r0_pids[proc_num] = fork()) {
        case -1:
            perror("fork");
            exit(-1);
        case 0: {
            uint16_t score = 0; // Local score of this process
            uint16_t P = 0;
            int32_t Q = 0;
            int res;

            // dbg_r0("Started");

            // Close the parent fd
            close(fd[PARENT_SOCK_FD]);

            // First child initilize shm's value from parent's M
            if ((proc_num == 0) && (first_init == false)) {
                shmp->value = M;
                first_init = true;
                // dbg_r0("First process was initialized");
            }

            for (;;) {
                dbg_r0("Waiting ring0 sem");
                if (sem_reserve(semid, proc_num) == -1) {
                    perror("ring0 sem_reserve");
                    exit(-1);
                }
                dbg_r0("Enter critical section");

                // Play P and evaluate score
                if (r0_play_P(proc_num, shmp->value, L, &P) == -1)
                    exit(-1);
                if ((Q = (shmp->value - P)) <= 0)
                    score += 1;
                else
                    shmp->value = Q;
                dbg_r0("Q=%d M=%d P=%d score=%d/%d", Q, shmp->value, P, score, L);

                if (score >= L) {
                    dbg_r0("I won");
                    if (write(fd[CHILD_SOCK_FD], &proc_num, sizeof(proc_num)) ==
                        -1) {
                        perror("write");
                        exit(-1);
                    }
                } else {
                    uint16_t next = (proc_num == (N - 1)) ? 0 : proc_num + 1;
                    dbg_r0("Take control to %d process", next);
                    if (sem_release(semid, next) == -1) {
                        perror("ring0 sem_release");
                        exit(-1);
                    }
                }
            }

            exit(0);
        }
        default: {
            break;
        }
        }
    }

    // Close the child fd
    close(fd[CHILD_SOCK_FD]);

    dbg_main("Waiting for winner process number");
    if (read(fd[PARENT_SOCK_FD], &winner_num, sizeof(winner_num)) == -1) {
        perror("read");
        exit(-1);
    }
    winner_num += 1; // From 1 in task
    printf("Winner: %d\n", winner_num);

    // Terminate all ring0 processes
    for (uint16_t i = 0; i < N; i++) {
        dbg_main("Send SIGTERM to %ld", (long)r0_pids[i]);
        kill(r0_pids[i], SIGTERM);
    }

    // Free ring0 resouces
    union semun dummy;
    for (uint16_t i = 0; i < N; i++) {
        if (semctl(semid, i, IPC_RMID, dummy)) {
            perror("semctl IPC_RMID");
            exit(-1);
        }
    }

    return 0;
}

static int r0_play_P(uint16_t proc_num, uint16_t M, uint16_t L, uint16_t *P)
{
    // Definition for MQ with ring1
    int msgid;
    r1_mq_t mq_buf;
    pid_t r1_pid;

    // Prepare mq to communicate with ring1
    while ((msgid = msgget(R1_MQ_KEY, IPC_CREAT | OBJ_PERMS)) == -1) {
        if (errno == EEXIST) {
            if ((msgid = msgget(R1_MQ_KEY, 0)) == -1) {
                perror("msgget retrieve old ID");
                return -1;
            }
            if (msgctl(msgid, IPC_RMID, NULL) == -1) {
                perror("msgctl rm");
                return -1;
            }
        } else {
            perror("msgget");
            return -1;
        }
    }

    // dbg_r0("Rise ring1 processes");
    switch (r1_pid = fork()) {
    case -1:
        perror("fork");
        exit(-1);
    case 0: {
        char argL[16], argM[16];
        snprintf(argL, sizeof(argL), "%hu", L);
        snprintf(argM, sizeof(argM), "%hu", M);
        if (execlp(EXEC_R1, EXEC_R1_NAME, argL, argM, NULL) == -1) {
            perror("exec");
            return -1;
        }
    }
    default:
        break;
    }

    // dbg_r0("Waiting for P from ring1");
    if (msgrcv(msgid, &mq_buf, sizeof(r1_mq_t) - sizeof(long), R1_MQ_MTYPE_P,
            0) == -1) {
        perror("msgrcv");
        return -1;
    }
    *P = mq_buf.value;
    // dbg_r0("ring1 returns P=%d", *P);

    return 0;
}

