#include <arpa/inet.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

static int gen_port()
{
    // Found next free-to-bind port
    static int port = 3411;
    for (; port < 59999; ++port) {
        int fd = ::socket(AF_INET, SOCK_STREAM, 0);
        socklen_t sa_len = sizeof(sockaddr_storage);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(static_cast<uint16_t>(port));
        addr.sin_addr.s_addr = 0;
        if ((::bind(fd, reinterpret_cast<struct sockaddr *>(&addr),
                sizeof(struct sockaddr_in))) == 0) {
            close(fd);
            return port;
        }
        if (errno != EADDRINUSE) {
            close(fd);
            return -1;
        }
        close(fd);
    }

    // i don't care, it's not possible
    return -1;
}

static int test_bind(int port)
{
    printf("port=%d\n", port);
    int fd = ::socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(static_cast<uint16_t>(port));
    addr.sin_addr.s_addr = 0;
    return ::bind(fd, reinterpret_cast<struct sockaddr *>(&addr),
        sizeof(struct sockaddr_in));
}

int main(int argc, char const *argv[])
{
    test_bind(gen_port());
    test_bind(gen_port());
    test_bind(gen_port());
    test_bind(gen_port());
    test_bind(gen_port());
    test_bind(gen_port());
    return 0;
}
