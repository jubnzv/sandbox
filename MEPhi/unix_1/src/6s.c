#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "6.h"

int main(int argc, char const *argv[])
{
    uint16_t M = 0, L = 0;
    uint16_t winner_num;
    pid_t r1_pids[R1_PROC_NUM] = {0};
    struct sigaction sa;
    int semid; // Set of ring0 semaphores
    bool first_init = false;

    int fd[2]; // socketpair between parent and children in ring1
    int fds_r1[R1_PROC_NUM][2]; // socketpair children in ring1

    // Definitions for MQ with ring0 parent
    int msgid;
    r1_mq_t mq_buf;

    // Parse CLI arguments
    if (sscanf(argv[1], "%hu", &L) != 1) {
        perror("sscanf");
        exit(-1);
    }
    if (sscanf(argv[2], "%hu", &M) != 1) {
        perror("sscanf");
        exit(-1);
    }

    // Initialize ring0 semaphores
    // FIXME: Use `ipcsrm' first
    if ((semid = semget(SEM_KEY_R1, R1_PROC_NUM, IPC_CREAT | OBJ_PERMS)) ==
        -1) {
        perror("semget");
        exit(-1);
    }
    // First process starts first
    if (sem_init_available(semid, 0)) {
        perror("sem_init_available");
        exit(-1);
    }
    for (uint16_t i = 1; i < R1_PROC_NUM; i++) {
        if (sem_init_in_use(semid, i)) {
            perror("sem_init_in_use");
            exit(-1);
        }
    }

    // Open MQ to communicate with ring0 parent
    if ((msgid = msgget(R1_MQ_KEY, OBJ_PERMS)) == -1) {
        perror("msgget");
        exit(-1);
    }

    // Set signals handler
    sa.sa_flags = 0;
    sa.sa_handler = sig_chld;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    // Initialize sockets between local parent and children
    if (socketpair(PF_LOCAL, SOCK_DGRAM, 0, fd) == -1) {
        perror("socketpair");
        exit(-1);
    }

    // Initialize sockets between ring1 children
    for (uint16_t i = 0; i < R1_PROC_NUM; i++) {
        if (socketpair(PF_LOCAL, SOCK_DGRAM, 0, fds_r1[i]) == -1) {
            perror("socketpair");
            exit(-1);
        }
    }

    for (uint16_t proc_num = 0; proc_num < R1_PROC_NUM; proc_num++) {
        switch (r1_pids[proc_num] = fork()) {
        case -1:
            perror("fork");
            exit(-1);
        case 0: {
            uint16_t score = 0; // Local score of this child
            uint16_t P = 0;
            int32_t Q = 0;
            int res;

            // Close parent fd
            close(fd[PARENT_SOCK_FD]);

            // dbg_r1("Started");

            for (;;) {
                // dbg_r1("Waiting ring1 sem");
                if (sem_reserve(semid, proc_num) == -1) {
                    perror("ring0 sem_reserve");
                    exit(-1);
                }
                // dbg_r1("Enter critical section");

                // R1 first process starts here and inherits M from parent
                if ((first_init == false) && (proc_num == 0)) {
                    first_init = true;
                    Q = M;
                } else {
                    // Otherwise we reading value from other R1 child
                    // dbg_r1("Waiting Q on socket");
                    if (read(fds_r1[proc_num][R1_R_SOCK_FD], &Q, sizeof(Q)) ==
                        -1) {
                        perror("read");
                        exit(-1);
                    }
                    // dbg_r1("Got Q=%d", Q);
                }

                // Decrease M
                if ((Q -= 1) <= 0)
                    score += 1;
                // dbg_r1("Q=%d score=%d/%d", Q, score, L);

                if (score >= L) {
                    // dbg_r1("I won");
                    if (write(fd[CHILD_SOCK_FD], &proc_num, sizeof(proc_num)) ==
                        -1) {
                        perror("write");
                        exit(-1);
                    }
                    exit(0);
                } else {
                    uint16_t next =
                        (proc_num == (R1_PROC_NUM - 1)) ? 0 : proc_num + 1;
                    if (write(fds_r1[next][R1_W_SOCK_FD], &Q, sizeof(Q)) ==
                        -1) {
                        perror("write");
                        exit(-1);
                    }
                    // dbg_r1("Take control to %d process", next);
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

    // dbg_6s("Waiting for winner process number");
    if (read(fd[PARENT_SOCK_FD], &winner_num, sizeof(winner_num)) == -1) {
        perror("read");
        exit(-1);
    }
    winner_num += 1; // R0 awaits process number from 1
    // dbg_6s("R1 winner: %d", winner_num);

    // Send proc_num to ring0 parent
    mq_buf.mtype = R1_MQ_MTYPE_P;
    mq_buf.value = winner_num;
    if (msgsnd(msgid, &mq_buf, sizeof(r1_mq_t) - sizeof(long), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    // Terminate all ring1 processes
    for (uint16_t i = 0; i < R1_PROC_NUM; i++) {
        if (r1_pids[i] != 0) {
            // dbg_main("Send SIGTERM to %ld", (long)r1_pids[i]);
            kill(r1_pids[i], SIGTERM);
        }
    }

    return 0;
}
