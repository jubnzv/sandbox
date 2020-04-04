#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <time.h>

#define SEM_NAME "testsem"
#define TO_WAIT_S 0
#define TO_WAIT_NS 0

int main(int argc, char const *argv[])
{
    sem_t *sem;

    sem_unlink(SEM_NAME);
    sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return -1;
    }

    struct timespec abs_to;
    if ((clock_gettime(CLOCK_REALTIME, &abs_to)) == -1) {
        perror("clock_gettime");
        return -1;
    }
    abs_to.tv_sec += TO_WAIT_S;
    abs_to.tv_nsec = 999999999;

    sleep(2);

    if ((sem_timedwait(sem, &abs_to)) == -1) {
        if (errno == ETIMEDOUT)
            fprintf(stderr, "Timed out.\n");
        else
            fprintf(stderr, "%m\n");
    } else {
        printf("OK\n");
    }

    sem_unlink(SEM_NAME);
    return 0;
}
