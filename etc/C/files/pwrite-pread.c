#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define FILENAME    "foo.txt"
#define SIZE        3

int main(int argc, char const* argv[])
{
    system("echo foo-bar-baz >> " FILENAME);

    int fd;
    ssize_t nb;

    if ((fd= open(FILENAME, O_RDWR)) == -1) {
            perror("open");
            exit(EXIT_FAILURE);
    }

    char read_buf[SIZE+1] = {'\0'};
    nb = pread(fd, (void *)read_buf, SIZE+1, (off_t)4);
    assert(nb == 4);
    assert(!strncmp(read_buf, "bar", 3));

    const char *write_buf = "sss";
    nb = pwrite(fd, (void *)write_buf, SIZE, (off_t)3);
    assert(nb == 3);

    system("/bin/rm " FILENAME);

    return 0;
}
