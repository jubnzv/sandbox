/**
 * Creates POSIX timers with signal notifications and delete them in handler.
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define TIMER_SIG SIGRTMAX

static timer_t timer;

static void handler(int sig, siginfo_t *si, void *uc)
{
    int rc;
    timer_t *timerptr;

    timerptr = (timer_t *)si->si_value.sival_ptr;
    printf(
        "%s: timerptr=%p timerid=%ld\n", __func__, timerptr, (long)*timerptr);

    rc = timer_delete(*timerptr);
    if (rc == -1)
        perror("timer_delete");
    else
        printf("timer_delete works\n");
}

static int create_timer(void)
{
    int rc;
    struct sigevent evp;
    struct itimerspec ts;

    evp.sigev_notify = SIGEV_SIGNAL;
    evp.sigev_signo = TIMER_SIG;
    evp.sigev_value.sival_ptr = &timer;

    rc = timer_create(CLOCK_REALTIME, &evp, &timer);
    if (rc == -1) {
        perror("timer_create");
        return -1;
    }

    ts.it_interval.tv_sec = 120;
    ts.it_interval.tv_nsec = 0;
    ts.it_value.tv_sec = 120;
    ts.it_value.tv_nsec = 0;

    printf("%s: timerptr=%p timerid=%ld\n", __func__, &timer, (long)timer);
    rc = timer_settime(timer, 0, &ts, NULL);
    if (rc == -1) {
        perror("timer_settime");
        return -1;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sa.sa_handler = (void *)handler;
    sigaction(TIMER_SIG, &sa, NULL);

    for (int i = 0; i < 10; i++) {
        create_timer();
    }

    pause();

    timer_delete(timer);

    return 0;
}
