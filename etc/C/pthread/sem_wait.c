#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

static int f1(void)
{
    sem_t *semd = sem_open("sem_test", O_CREAT | O_EXCL | O_RDWR, 0644, 1);
    if (semd == SEM_FAILED) {
        perror("sem_open");
        return -1;
    }
    printf("%s:%d sleep\n", __func__, __LINE__);
    sleep(2);
    printf("%s:%d post\n", __func__, __LINE__);
    sem_post(semd);
    printf("%s:%d sleep\n", __func__, __LINE__);
    sleep(2);
    printf("%s done\n", __func__);
    return 0;
}

static int f2(void)
{
    sem_t *semd = sem_open("sem_test", O_RDWR);
    if (semd == SEM_FAILED) {
        perror("sem_open");
        return -1;
    }
    printf("%s:%d wait\n", __func__, __LINE__);
    sem_wait(semd);
    printf("%s:%d wait\n", __func__, __LINE__);
    sem_wait(semd);
    printf("%s done\n", __func__);
    return 0;
}

int main(int argc, char const* argv[])
{
    int child_pid;

    sem_unlink("sem_test");

    switch (child_pid = fork()) {
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);
    case 0: {
        f1();
        exit(EXIT_SUCCESS);
    }
    default:
        usleep(2000); // meh
        f2();
        break;
    }

    return 0;
}
