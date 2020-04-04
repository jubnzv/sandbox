#include "util.h"

#include <errno.h>
#include <sys/types.h>
#include <stddef.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t send_size(int fd, const void *buf, size_t length)
{
    size_t written = 0;

    while (written < length) {
        const ssize_t n = write(fd, ((char *)buf) + written, length - written);
        if (n == -1) {
            if (errno == EINTR || errno == EAGAIN)
                continue;
            return n;
        }
        written += (size_t)n;
    }

    return written;
}

int recv_size(int fd, void *buf, size_t length)
{
    size_t num_read = 0;

    while (num_read != length) {
        num_read = read(fd, buf, length);
        if (num_read == (size_t)-1) {
            return -1;
        }
    }

    return num_read;
}

void setblocking(int fd, int state)
{
    int mode;

    if ((mode = fcntl(fd, F_GETFL)) != -1) {
        if (!state)
            mode |= O_NONBLOCK;
        else
            mode &= ~O_NONBLOCK;
        fcntl(fd, F_SETFL, mode);
    }
}
