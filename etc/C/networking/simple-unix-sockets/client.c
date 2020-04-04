#include <errno.h>
#include <stdio.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#include "util.h"

int main(int argc, char const *argv[])
{
    int fd;
    struct sockaddr_un sa;
    const char buf[BUF_SIZE] = "Test data.\0";

    sa.sun_family = AF_UNIX;
    memset(&sa.sun_path, 0, sizeof(sa.sun_path));
    memcpy(&sa.sun_path, SOCKPATH, sizeof(SOCKPATH));

    fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(fd, (struct sockaddr *)&sa, sizeof(struct sockaddr_un)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    setblocking(fd, 1);
    sleep(1);

#warning "here"
srand(time (NULL));
int r;
setblocking(fd, 0);
while(1) {
    if ((rand() % 10) > 5) {
    r = send_size(fd, (void *)&buf, BUF_SIZE);
    printf("send r=%d\n", r);
    } else {
    r = recv_size(fd, (void *)&buf, BUF_SIZE);
    printf("recv r=%d\n", r);
    }
    usleep(100);
}

    printf("Sending...\n");
    if (!send_size(fd, (void *)&buf, BUF_SIZE)) {
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}
