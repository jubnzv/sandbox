/** Playing with sem_unlink / sem_open / sem_close */
#include <errno.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdio.h>

#include "sems.h"

int main(int argc, char const* argv[])
{
    int rc;
    int value = -1;
	sem_t *sem;

    // Open with pre-defined value
    rc = sem_unlink(SEM_NAME_CLOSE);
    if (rc == -1)
        if (errno != ENOENT) {
            perror("sem_unlink");
            return -1;
        }
	sem = sem_open(SEM_NAME_CLOSE, O_CREAT | O_EXCL, 0644, 20);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return -1;
    }

    rc = sem_getvalue(sem, &value);
    if (rc != 0) {
        perror("sem_getvalue");
        return -1;
    }
    printf("sem value: %d\n", value);

    printf("sem == NULL: %d\n", sem == NULL);
    printf("&sem: %x\n", sem);

    printf("Do sem close\n");

    rc = sem_close(sem);
    if (rc != 0) {
        perror("sem_close");
        return -1;
    }

    printf("sem == NULL: %d\n", sem == NULL);
    printf("&sem: %x\n", sem);

    // Should segfaulted here
    // rc = sem_getvalue(sem, &value);
    // if (rc != 0) {
    //     perror("sem_getvalue");
    //     return -1;
    // }
    // printf("sem value: %d\n", value);

    // Re-open again
    rc = sem_unlink(SEM_NAME_CLOSE);
    if (rc == -1)
        if (errno != ENOENT) {
            perror("sem_unlink");
            return -1;
        }
	sem = sem_open(SEM_NAME_CLOSE, O_CREAT | O_EXCL, 0644);
	// sem = sem_open(SEM_NAME_CLOSE, O_CREAT | O_EXCL, 0644, 20);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return -1;
    }

    value = -1;
    rc = sem_getvalue(sem, &value);
    if (rc != 0) {
        perror("sem_getvalue");
        return -1;
    }
    printf("sem value: %d\n", value);

    return 0;
}
