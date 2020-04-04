/* Cleint: first send than receive */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include "tcp.h"

int main(int argc, char const *argv[])
{
    int fd;
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

    printf("%s:%d Connect to server...\n", __func__, __LINE__);
    rc = connect(fd, (struct sockaddr *)&srvaddr, sizeof(srvaddr));
    if (rc == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        printf("%s:%d Write to server...\n", __func__, __LINE__);
        rc = write(fd, buf, BUF_SIZE);
        if (rc == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        printf("%s:%d Write OK\n", __func__, __LINE__);

        printf("%s:%d Reading from server...\n", __func__, __LINE__);
        rc = read(fd, buf, BUF_SIZE);
        if (rc == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("%s:%d Read %d bytes: %s\n", __func__, __LINE__, rc, buf);

        usleep(50000);
    }

    return 0;
}
