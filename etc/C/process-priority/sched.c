// Set real-time scheduling policies using sched_setscheduler(2) syscall.
// Refrence: chrt(1) sources [0].
//
// Use top(1) to test it:
// top -c -p $(pgrep -d',' -f a.out)
//
// [0]: https://github.com/karelzak/util-linux/blob/master/schedutils/chrt.c
// [1]: TLPI Ch. 35.2

#include <errno.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static const char *get_policy_name(void)
{
    int policy = sched_getscheduler(getpid());
    switch (policy) {
    case SCHED_OTHER:
        return "SCHED_OTHER";
    case SCHED_FIFO:
        return "SCHED_FIFO";
    case SCHED_RR:
        return "SCHED_RR";
    default:
        break;
    }

    return "unknown";
}

static int set_sched_setscheduler(int priority, int policy)
{
    struct sched_param sp = {.sched_priority = priority};
    // pid 0 is a current process
    return sched_setscheduler(0, policy, &sp);
}

int main(int argc, char const *argv[])
{

    if (setuid(0) < 0) {
        perror("Must be root.");
        exit(EXIT_FAILURE);
    }

    printf("Default policy: %s\n", get_policy_name());

    if (set_sched_setscheduler(0, SCHED_OTHER) == -1) {
        perror("set_sched_setscheduler");
        exit(EXIT_FAILURE);
    }
    printf("Current policy: %s\n", get_policy_name());
    printf("Press any key to continue...\n");
    getchar();

    if (set_sched_setscheduler(99, SCHED_OTHER) == -1) {
        perror("set_sched_setscheduler");
        printf("SCHED_OTHER could not be set other then 0.\n");
    }
    printf("Current policy: %s\n", get_policy_name());
    printf("Press any key to continue...\n");
    getchar();

    if (set_sched_setscheduler(50, SCHED_FIFO) == -1) {
        perror("set_sched_setscheduler");
        exit(EXIT_FAILURE);
    }
    printf("Current policy: %s\n", get_policy_name());
    printf("Press any key to continue...\n");
    getchar();

    if (set_sched_setscheduler(99, SCHED_RR) == -1) {
        perror("set_sched_setscheduler");
        exit(EXIT_FAILURE);
    }
    printf("Current policy: %s\n", get_policy_name());
    printf("Press any key to continue...\n");
    getchar();

    return 0;
}
