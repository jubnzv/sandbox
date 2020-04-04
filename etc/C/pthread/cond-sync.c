#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Synchronize data access between threads
static pthread_cond_t SyncCond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t SyncMutex = PTHREAD_MUTEX_INITIALIZER;
bool NeedExecFlag = false;

#define SIZE 10
static int data[SIZE] = {0};

static int execute(void)
{
    if (!NeedExecFlag) {
        return -1;
    }

    if ((pthread_mutex_trylock(&SyncMutex)) != 0) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < SIZE; i++)
        data[i]++;
    NeedExecFlag = false;
    pthread_cond_signal(&SyncCond);
    pthread_mutex_unlock(&SyncMutex);
    return 0;
}

static inline void print_data()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d \n", data[i]++);
}

static void *consumer_thread(void *arg)
{
    for (;;) {
        NeedExecFlag = true;
        if (pthread_mutex_trylock(&SyncMutex) != 0) {
            pthread_cond_wait(&SyncCond, &SyncMutex);
        }
        sleep(1);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{

    pthread_t tid_consumer;
    pthread_create(&tid_consumer, NULL, consumer_thread, NULL);

    for (;;) {
        execute();
        sleep(2);
    }

    sleep(20);

    return 0;
}
