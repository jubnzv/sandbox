/**
 * Basic operations with POSIX shared memory.
 * */

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_NAME "shm-basics"

/* Avoid race condition after fork */
#define SYNC_SIG SIGUSR1
static void handler(int sig) {}

int main(int argc, char const *argv[])
{
    int shm_fd;
    int *shm_val_p;
    pid_t child_pid;
    sigset_t empty_mask;
    struct sigaction sa;

    sa.sa_flags = SA_RESTART;
    sa.sa_handler = handler;
    sigaction(SYNC_SIG, &sa, NULL);

    shm_unlink(SHM_NAME); /* Ignore error */

    switch (child_pid = fork()) {
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);
    case 0:
        /* Waits for parent signal */
        sigemptyset(&empty_mask);
        if (sigsuspend(&empty_mask) == -1 && errno != EINTR) {
            perror("sigsuspend");
            exit(EXIT_FAILURE);
        }

        if ((shm_fd = shm_open(SHM_NAME, 0, 0644)) == -1) {
            perror("shm_open");
            exit(EXIT_FAILURE);
        }

        shm_val_p = mmap(NULL, sizeof(int), PROT_READ, MAP_SHARED, shm_fd, 0);
        if (shm_val_p == MAP_FAILED) {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        printf("%ld shm value: %d\n", (long)getpid(), *shm_val_p);

        exit(EXIT_SUCCESS);
    default:
        if ((shm_fd = shm_open(SHM_NAME, O_CREAT | O_EXCL | O_RDWR, 0644)) == -1) {
            perror("shm_open");
            exit(EXIT_FAILURE);
        }

        if ((ftruncate(shm_fd, sizeof(*shm_val_p))) == -1) {
            perror("ftruncate");
            exit(EXIT_FAILURE);
        }

        shm_val_p = mmap(NULL, sizeof(shm_val_p), PROT_READ | PROT_WRITE,
            MAP_SHARED, shm_fd, 0);
        if (shm_val_p == MAP_FAILED) {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        *shm_val_p = 19;
        printf("%ld shm value: %d\n", (long)getpid(), *shm_val_p);

        /* Awake child */
        if (kill(child_pid, SYNC_SIG) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }
        break;
    }

    int return_status;
    if (waitpid(child_pid, &return_status, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    shm_unlink(SHM_NAME);

    return 0;
}
