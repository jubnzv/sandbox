#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static pthread_cond_t SyncCond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t SyncMutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char const *argv[])
{

    pthread_t tid_consumer;
    // pthread_mutex_lock(&SyncMutex);
    sleep(2);
    pthread_cond_wait(&SyncCond, &SyncMutex);
    // pthread_mutex_lock(&SyncMutex);

    for (;;) {
        sleep(2);
    }

    return 0;
}

