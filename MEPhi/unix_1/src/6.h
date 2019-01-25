#pragma once

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

// clang-format off
// fprintf(stdout, "%s:%d" _PRNTMSG "\n", __func__, __LINE__, ##__VA_ARGS__)
#ifdef DEBUG_MODE
#define dbg(_PRNTMSG, ...)                     \
    fprintf(stdout, _PRNTMSG "\n", ##__VA_ARGS__)
#else
#define dbg(_PRNTMSG, ...) do {} while(0);
#endif // !DEBUG_MODE
#define dbg_main(_PRNTMSG, ...) dbg("[main] " _PRNTMSG, ##__VA_ARGS__);
#define dbg_r0(_PRNTMSG, ...) dbg("  [R0][pid=%ld][proc=%d] " _PRNTMSG, (long)getpid(), proc_num, ##__VA_ARGS__);
#define dbg_6s(_PRNTMSG, ...) dbg("    [R1][pid=%ld][main] " _PRNTMSG, (long)getpid(), ##__VA_ARGS__);
#define dbg_r1(_PRNTMSG, ...) dbg("      [R1][pid=%ld][ppid=%ld][proc=%d] " _PRNTMSG, (long)getpid(), (long)getppid(), proc_num, ##__VA_ARGS__);

#define   EXEC_R1       "./bin/6s"
#define   EXEC_R1_NAME  "6s"
#define   R1_PROC_NUM   3
#define   LISTENQ       1024

// Socketpair indexes between parent and child in ring1
#define PARENT_SOCK_FD      0
#define CHILD_SOCK_FD       1
// Socketpair indexes between children in ring1
#define R1_W_SOCK_FD        0
#define R1_R_SOCK_FD        1

// Shared memory to communicate in 0-th ring
typedef struct ring0_shm_s {
    int32_t value; // Value given from previous process or parent
} ring0_shm_t;

// Mq to communicate between 0-th and 1-th ring processes
typedef struct r1_mq_s {
    long mtype;
    uint16_t value;
} r1_mq_t;

// Message types for rings communication
#define R1_MQ_MTYPE_M       1
#define R1_MQ_MTYPE_P       2

#define OBJ_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
#define SHM_KEY 0x12DD
#define SEM_KEY_R0 0x1300
#define SEM_KEY_R1 0x1301

#define R1_MQ_KEY 0x12EE

// Used in calls to semctl()
// @see TLPI ch. 47
union semun {
    int                 val;
    struct semid_ds *   buf;
    unsigned short *    array;
#if defined(__linux__)
    struct seminfo *    __buf;
#endif
};
// clang-format on

// Modified semaphore functions from TLPI ch. 47
int sem_init_available(int semid, int semnum);
int sem_init_in_use(int semid, int semnum);
int sem_reserve(int, int);
int sem_release(int, int);

void sig_chld(int signo)
{
    (void)signo;
    pid_t pid;
    int stat;

    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0) ;
        // printf("[%ld]: child %ld terminated\n", (long)getpid(), (long)pid);
    return;
}

int sem_reserve(int semid, int semnum)
{
    int bsUseSemUndo = 0;
    int bsRetryOnEintr = 1;

    struct sembuf sops;

    sops.sem_num = semnum;
    sops.sem_op = -1;
    sops.sem_flg = bsUseSemUndo ? SEM_UNDO : 0;

    while (semop(semid, &sops, 1) == -1)
        if (errno != EINTR || !bsRetryOnEintr)
            return -1;

    return 0;
}

int sem_release(int semid, int semnum)
{
    int bsUseSemUndo = 0;

    struct sembuf sops;

    sops.sem_num = semnum;
    sops.sem_op = 1;
    sops.sem_flg = bsUseSemUndo ? SEM_UNDO : 0;

    return semop(semid, &sops, 1);
}

// Initialize semaphore to 1 (i.e., "available")
int sem_init_available(int semid, int semnum)
{
    union semun arg;

    arg.val = 1;
    return semctl(semid, semnum, SETVAL, arg);
}

// Initialize semaphore to 0 (i.e., "in use")
int sem_init_in_use(int semid, int semnum)
{
    union semun arg;

    arg.val = 0;
    return semctl(semid, semnum, SETVAL, arg);
}
