#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include "tcp.h"

static int fd;

void sigalrm_handler(int signo)
{
    (void)signo;
    printf("Got SIGALRM\n");
    close(fd);
}

static size_t recv_bytes(int fd, char *buf, size_t length) {
    size_t got_nb;
    size_t remain_nb = length;
    size_t offset = 0;
    while ((remain_nb > 0) && ((got_nb = recv(fd, buf + offset, remain_nb, 0)) > 0)) {
        printf("Got %ld/%ld\n", got_nb, length);
        remain_nb -= got_nb;
        offset += got_nb;
    }

    return got_nb;
}

int main(int argc, char const *argv[])
{
    int rc;
    char buf[BUF_SIZE] = "Hello\0";
    struct sockaddr_in srvaddr;
    socklen_t len;

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(SERVER_PORT);
    srvaddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    rc = connect(fd, (struct sockaddr *)&srvaddr, sizeof(srvaddr));
    if (rc == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    signal(SIGALRM, sigalrm_handler);
    alarm(3);

    for (;;) {
        recv_bytes(fd, buf, 1);
        recv_bytes(fd, buf, 2);
        recv_bytes(fd, buf, 4);
        recv_bytes(fd, buf, 8);
        usleep(50000);
    }

    return 0;
}
