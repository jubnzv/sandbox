#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 3322

static int try_bind()
{
    int sd, opt = 1;
    struct sockaddr_in saddr;

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(int)) < 0) {
        return -1;
    }

    memset((char *)&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons((unsigned short)PORT);

    if (bind(sd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
        return -1;
    }

    // Don't close the socket
    return 0;
}

int main(int argc, char *argv[])
{
    assert(try_bind() == 0);
    assert(try_bind() == 0);
    assert(try_bind() == 0);
    assert(try_bind() == 0);
}

