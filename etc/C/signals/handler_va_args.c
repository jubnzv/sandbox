/**
 * Free resources in signal handler with variable arguments number.
 * Looks weird, but can be used in some specific cases.
 */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#define SZ  4

int handler_va_args(int signo, ...) {
    va_list ap;
    static char *ptr = NULL;

    /* Save that value only after first call */
    if (ptr == NULL) {
        va_list arg;
        va_start(arg, signo);
        ptr = va_arg(arg, char *);
        va_end(arg);
        printf("%s: register: %p\n", __func__, ptr);
        printf("%s: %c %c %c %c\n", __func__, ptr[0], ptr[1], ptr[2], ptr[3]);
    } else {
        /* Clean up resources */
        printf("%s: free: %p\n", __func__, ptr);
        memcpy(ptr, "hjkl", sizeof(char) * SZ);
        printf("%s: %c %c %c %c\n", __func__, ptr[0], ptr[1], ptr[2], ptr[3]);
    }
}

int main(int argc, char const* argv[])
{
    char *res = malloc(sizeof(char) * SZ);
    memcpy(res, "abcd", sizeof(char) * SZ);
    printf("%s: %c %c %c %c\n", __func__, res[0], res[1], res[2], res[3]);

    printf("%s: res: %p\n", __func__, res);

    /* Setup handler */
    struct sigaction sa;
    sa.sa_flags = SA_ONESHOT;
    sa.sa_handler = (void *)handler_va_args;
    sigaction(SIGINT, &sa, NULL);

    /* Register resource to be free */
    handler_va_args(0, res);

    /* Waiting for SIGINT */
    getchar();

    sleep(1);
    printf("%s: %c %c %c %c\n", __func__, res[0], res[1], res[2], res[3]);

    return 0;
}
