/* Server: first receive than send */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#include "tcp.h"

int main(int argc, char const* argv[])
{
    int fd, connfd;
    int rc;
    char buf[BUF_SIZE];
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

    /* First receive message from client */
    printf("%s:%d Waiting client...\n", __func__, __LINE__);
    connfd = accept(fd, (struct sockaddr *)&addr, &clientlen);
    if (rc == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("%s:%d Got it\n", __func__, __LINE__);

    for (;;) {
        printf("%s:%d Reading from client...\n", __func__, __LINE__);
        rc = read(connfd, buf, BUF_SIZE);
        if (rc == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("%s:%d Read %d bytes: %s\n", __func__, __LINE__, rc, buf);

        rc = write(connfd, buf, BUF_SIZE);
        if (rc == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        printf("%s:%d Write OK\n", __func__, __LINE__);

        usleep(50000);
    }

    return 0;
}
