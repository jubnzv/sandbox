#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#include "sems.h"

int main(int argc, char *argv[])
{
    int rc;
	sem_t *sem;

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

	sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return -1;
    }

    return 0;
}
