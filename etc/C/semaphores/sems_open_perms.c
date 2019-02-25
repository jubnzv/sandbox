#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "sems.h"

#define SIGSYNC SIGUSR1
static void *handler(int sig) {}

int main(int argc, char *argv[])
{
    int rc;
    sem_t *sem;
    pid_t child_pid;
    sigset_t empty_mask;

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = (void *)handler;
    sigaction(SIGSYNC, &sa, NULL);

    rc = sem_unlink(SEM_NAME);
    if (rc == -1) {
        if (errno == ENOENT) {
            printf("Not exitsts before.\n");
        } else {
            perror("sem_unlink");
            return -1;
        }
    }
    printf("Replaced.\n");

    switch (child_pid = fork()) {
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);
    case 0:
        sem = sem_open(SEM_NAME, O_RDWR);
        if (sem == SEM_FAILED) {
            perror("sem_open");
            return -1;
        }

        /* Waits for parent signal */
        sigemptyset(&empty_mask);
        if (sigsuspend(&empty_mask) == -1 && errno != EINTR) {
            perror("sigsuspend");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    default:
        sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 0);
        if (sem == SEM_FAILED) {
            perror("sem_open");
            return -1;
        }

        /* Awake child */
        if (kill(child_pid, SIGSYNC) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }
        break;
    }

    return 0;
}
