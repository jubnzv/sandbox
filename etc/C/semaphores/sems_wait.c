#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "sems.h"

// static sem_t *sem_p;
static sem_t sem;

void *tloop(void *arg) {
    (void)arg;
    int rc, sem_val;
    for (;;) {
        rc = sem_getvalue(&sem, &sem_val);
        if (rc == -1) {
            perror("sem_getvalue");
            exit(0);
        }
        printf("tid=%ld Value: %x\n", (long)pthread_self(), sem_val);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char const* argv[])
{
    int rc;
    pid_t child_pid;
    pthread_t tid;

    // sem_p = malloc(sizeof(sem_t));
    rc = sem_init(&sem, PTHREAD_PROCESS_PRIVATE, 10);
    if (rc == -1) {
        perror("sem_init");
        return -1;
    }
    printf("Create semaphore\n");

    rc = pthread_create(&tid, NULL, (void *)tloop, NULL);

    switch(child_pid = fork()) {
        case -1:
            perror("fork");
            return -1;
        case 0: {
            int sem_val = -1;
            struct timespec to;
            clock_gettime(CLOCK_REALTIME, &to);
            to.tv_sec += 10;

            // rc = sem_getvalue(sem, &sem_val);
            // if (rc == -1) {
            //     perror("sem_getvalue");
            //     exit(0);
            // }
            // printf("pid=%ld Value: %x\n", (long)getpid(), sem_val);

            sleep(2);

            // sem = sem_open(SEM_NAME_WAIT, 0, 0600, 0);
            // if (sem == SEM_FAILED) {
            //     perror("sem_open");
            //     return -1;
            // }
            //
            printf("pid=%ld Child waiting...\n", (long)getpid());
            // rc = sem_wait(sem);
            // rc = sem_timedwait(sem, &to);
            printf("pid=%ld rc = %d error: %s\n", (long)getpid(), rc, strerror(errno));
            fflush(stdout);
            exit(0);
    }
        default: {
            int sem_val = 0;
            sem_unlink(SEM_NAME_WAIT); /* Ignore error */
            // sem = sem_open(SEM_NAME_WAIT, O_CREAT | O_EXCL, 0644, 0);
            // if (sem == SEM_FAILED) {
            //     perror("sem_open");
            //     return -1;
            // }

            // rc = sem_post(sem);
            // if (rc == -1) {
            //     perror("sem_post");
            //     exit(0);
            // }
            // printf("Post sem\n");

            // rc = sem_wait(sem);
            // if (rc == -1) {
            //     perror("sem_post");
            //     exit(0);
            // }
            // printf("Wait sem\n");

            // rc = sem_getvalue(sem, &sem_val);
            // if (rc == -1) {
            //     perror("sem_getvalue");
            //     exit(0);
            // }
            printf("pid=%ld Value: %x\n", (long)getpid(), sem_val);

            sleep(4);

            printf("Unlink semaphore\n");
            rc = sem_unlink(SEM_NAME_WAIT);
            if (rc == -1) {
                perror("sem_unlink");
                exit(0);
            }
            printf("pid=%ld rc = %d error: %s\n", (long)getpid(), rc, strerror(errno));
        }
    }

    int status;
    rc = waitpid(child_pid, &status, 0);
    if (rc == -1) {
        perror("waitpid");
        return -1;
    }

    printf("status = %d\n", status);

    return 0;
}
