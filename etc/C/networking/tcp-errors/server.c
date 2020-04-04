/* Server: first receive than send */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include "tcp.h"

static int connfd;

void sigpipe_handler(int signo)
{
    (void)signo;
    printf("Got SIGPIPE\n");
    close(connfd);
}

int main(int argc, char const *argv[])
{
    int fd;
    int rc;
    struct sockaddr_in addr;
    socklen_t clientlen;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    clientlen = sizeof(addr);

    fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    rc = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (rc == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    rc = listen(fd, 1);
    if (rc == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("accept wait\n");
    connfd = accept(fd, (struct sockaddr *)&addr, &clientlen);
    if (rc == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, sigpipe_handler);

    for (;;) {
        uint8_t val1b = 0x1a;
        rc = send(connfd, &val1b, sizeof(val1b), 0);
        if (rc == -1) {
            perror("send");
        }

        uint16_t val2b = 0x1a2b;
        rc = send(connfd, &val2b, sizeof(val2b), 0);
        if (rc == -1) {
            perror("send");
        }

        uint32_t val4b = 0x1a2b3c4d;
        rc = send(connfd, &val4b, sizeof(val4b), 0);
        if (rc == -1) {
            perror("send");
        }

        uint64_t val8b = 0x1a2b3c4d50617283;
        rc = send(connfd, &val8b, sizeof(val8b), 0);
        if (rc == -1) {
            perror("send");
        }

        usleep(50000);
    }

    return 0;
}
