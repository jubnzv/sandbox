#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#include "sems.h"

static sem_t *sem_p;

int main(int argc, char const* argv[])
{
    int rc;
    pid_t child_pid;

    sem_unlink(SEM_NAME_WAIT); /* Ignore error */
    sem_p = sem_open(SEM_NAME_WAIT, O_CREAT | O_EXCL, 0600, 0);
    if (sem_p == SEM_FAILED) {
        perror("sem_open");
        return -1;
    }

    switch(child_pid = fork()) {
        case -1:
            perror("fork");
            return -1;
        case 0: {
            int sem_val = -1;

            rc = sem_getvalue(sem_p, &sem_val);
            if (rc == -1) {
                perror("sem_getvalue");
                exit(0);
            }
            printf("pid=%ld Value: %x\n", (long)getpid(), sem_val);

            printf("pid=%ld Child waiting...\n", (long)getpid());
            /* Still waiting after unlink */
            rc = sem_wait(sem_p);
            printf("pid=%ld rc = %d\n", (long)getpid(), rc);
            fflush(stdout);
            exit(0);
    }
        default: {
            int sem_val = 0;

            rc = sem_getvalue(sem_p, &sem_val);
            if (rc == -1) {
                perror("sem_getvalue");
                exit(0);
            }
            printf("pid=%ld Value: %x\n", (long)getpid(), sem_val);

            sleep(4);

            rc = sem_getvalue(sem_p, &sem_val);
            if (rc == -1) {
                perror("sem_getvalue");
                exit(0);
            }
            printf("pid=%ld Value: %x\n", (long)getpid(), sem_val);

            printf("Unlink semaphore\n");
            rc = sem_unlink(SEM_NAME_WAIT);
            if (rc == -1) {
                perror("sem_unlink");
                exit(0);
            }
            printf("pid=%ld rc = %d\n", (long)getpid(), rc);
        }
    }

    int status;
    rc = waitpid(child_pid, &status, 0);
    if (rc == -1) {
        perror("waitpid");
        return -1;
    }

    return 0;
}
