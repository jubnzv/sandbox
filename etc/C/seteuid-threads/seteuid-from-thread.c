#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define ROOT_UID 0
#define THREADS_NUM 10

void fn(void *args)
{
    (void)args;
    printf("%s:%d %d: start\n", __func__, __LINE__, pthread_self()); // prdbg
    int rc = seteuid(ROOT_UID);
    printf("rc=%d\n", rc);
    sleep(rand() % 3 + 1);
    printf("%s:%d %d: done\n", __func__, __LINE__, pthread_self()); // prdbg
}

int main(int argc, char const *argv[])
{
    pthread_t pid[THREADS_NUM];

    int i= 0;
    for (i = 0; i < THREADS_NUM; i++) {
        pthread_create(&pid[i], NULL, (void *)fn, NULL);
    }

    printf("%s:%d waiting\n", __func__, __LINE__); // prdbg
    sleep(5);
    for (i = 0; i < THREADS_NUM; i++) {
        pthread_join(pid[i], NULL);
    }

    return 0;
}

