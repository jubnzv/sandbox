#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void exit_handler(void)
{
    printf("%s\n", __func__);
    fflush(stdout);
}

int main(int argc, char const* argv[])
{
    int rc;

    rc = atexit(exit_handler);
    if (rc != 0) {
        perror("atexit");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
