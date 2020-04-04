// Some experiments with process nice value and [sg]etpriority syscalls.
//
// Use top(1) to test it:
// top -c -p $(pgrep -d',' -f a.out)

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
    int rc;
    int prio;

    if (setuid(0) < 0) {
        perror("Must be root.");
        exit(EXIT_FAILURE);
    }

    prio = getpriority(PRIO_PROCESS, 0);
    if (rc == -1) {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("Default nice=%d\n", prio);
    printf("Press any key to continue...\n");
    getchar();

    rc = setpriority(PRIO_PROCESS, 0, -20);
    if (rc == -1) {
        perror("setpriority");
        exit(EXIT_FAILURE);
    }

    prio = getpriority(PRIO_PROCESS, 0);
    if (rc == -1) {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("Current nice=%d\n", prio);
    printf("Press any key to continue...\n");
    getchar();

    return 0;
}
