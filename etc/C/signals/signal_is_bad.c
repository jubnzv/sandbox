/* Check rt_sigaction flags with strace. */
#include <signal.h>
#include <stdlib.h>

void handler(int signo) { (void)signo; }

int main(int argc, char const* argv[])
{
    signal(SIGINT, handler);

    struct sigaction sa;
    sa.sa_flags = SA_NODEFER;
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);

    return 0;
}
