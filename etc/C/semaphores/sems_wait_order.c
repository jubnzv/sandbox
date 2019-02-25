/* Execution order of waiting consumers */

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "sems.h"

#define TNUM 5

static sem_t *sem_p;
static pthread_t tids[TNUM];

static int *tloop(int *arg)
{
    int rc;
    int value = -1;

    printf("Thread %ld still waiting\n", (long)pthread_self());
    rc = sem_wait(sem_p);

    // if ((sem_getvalue(sem_p, &value)) == -1) {
    //     printf("sem_getvalue error!\n");
    //     exit(EXIT_FAILURE);
    // }
    // printf("%ld:%d sem_getvalue = %d\n", (long)pthread_self(), __LINE__, value);

    sem_post(sem_p);
    printf("Thread %ld just finish\n", (long)pthread_self());

    return NULL;
}

int main(int argc, char *argv[])
{
    int rc;
    int i;
    pid_t child_pid;

    sem_unlink(SEM_NAME);
    sem_p = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 0);
    if (sem_p == SEM_FAILED) {
        perror("sem_open");
        return -1;
    }

    setbuf(stdout, NULL);

    /* Initialize threads */
    for (i = 0; i < TNUM; i++) {
        rc = pthread_create(&tids[i], NULL, (void *)tloop, NULL);
    }

    sleep(5);
    sem_post(sem_p);

    for (i = 0; i < TNUM; i++) {
        printf("Waiting for %d\n", i);
        if (pthread_join(tids[i], NULL) != 0) {
            printf("pthread_join: %s\n", strerror(rc));
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
