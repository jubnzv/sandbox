#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

void exit_handler(void)
{
    printf("%s\n", __func__);
    fflush(stdout);
}

void sigint_handler(void *arg)
{
    printf("%s\n", __func__);
    fflush(stdout);
    exit(19);
}

int main(int argc, char const* argv[])
{
    int rc;

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = sigint_handler;
    sigaction(SIGINT, &sa, NULL);

    rc = atexit(exit_handler);
    if (rc != 0) {
        perror("atexit");
        exit(EXIT_FAILURE);
    }

    sleep(1000);

    exit(EXIT_SUCCESS);
}
