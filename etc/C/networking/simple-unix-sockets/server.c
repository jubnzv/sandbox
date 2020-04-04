#include <errno.h>
#include <stdio.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>

#include "util.h"

static int set_sched(void)
{
    struct sched_param sp = {.sched_priority = 99};
    return sched_setscheduler(0, SCHED_FIFO, &sp);
}

int main(int argc, char const *argv[])
{
    int fd, connfd;
    ssize_t recvd = 0;
    struct sockaddr_un sa;
    struct sockaddr sacl;
    socklen_t len = 0;
    const char buf[32];

    if (set_sched() != 0) {
        printf("fail!\n");
        exit(1);
    }

    unlink(SOCKPATH);

    sa.sun_family = AF_UNIX;
    memset(&sa.sun_path, 0, sizeof(sa.sun_path));
    memcpy(&sa.sun_path, SOCKPATH, sizeof(SOCKPATH));

    fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (bind(fd, (struct sockaddr *)&sa, sizeof(struct sockaddr_un)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(fd, 0) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Accepting...\n");
    if (( connfd = accept(fd, &sacl, &len) ) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    setblocking(connfd, 1);

#warning "here"
srand(time (NULL));
setblocking(connfd, 0);
int r;
while(1) {
    if ((rand() % 10) > 5) {
    r = send_size(fd, (void *)&buf, BUF_SIZE);
    printf("send r=%d\n", r);
    } else {
    r = recv_size(connfd, (void *)&buf, BUF_SIZE);
    printf("recv r=%d\n", r);
    }
    usleep(100);
}

    printf("Receiving...\n");
    if ((recvd = recv_size(connfd, (void *)&buf, BUF_SIZE)) < 0) {
        perror("recv_size");
        exit(EXIT_FAILURE);
    }
    printf("Received %d bytes buf=%s\n", recvd, buf);

    close(fd);
    return 0;
}
