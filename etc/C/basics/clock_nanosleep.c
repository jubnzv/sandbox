#include <errno.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct timespec req;
    clock_gettime(CLOCK_REALTIME, &req);
    req.tv_sec += 20;
    int s = clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &req, NULL);
    if (s != 0) {
        if (s = EINTR)
            printf("Interrupted with signal\n");
        else
            fprintf(stderr, "Error! %m\n");
    }
    return 0;
}
