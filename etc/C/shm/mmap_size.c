#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FNAME   "/tmp/test"
#define FSIZE   8111
#define MMAPSZ  8100

int main(int argc, char const* argv[])
{
    int fd;
    int rc, i;
    char *ptr;
    size_t pagesz;

    fd = open(FNAME, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    rc = lseek(fd, FSIZE-1, SEEK_SET);
    if (rc == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }

    rc = write(fd, "", 1);
    if (rc <= 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    ptr = mmap(NULL, MMAPSZ, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == NULL) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    pagesz = sysconf(_SC_PAGESIZE);
    printf("pagesz=%ld\n", pagesz);

    for (i = 0; i < ((MMAPSZ > FSIZE) ? MMAPSZ : FSIZE); i+=pagesz) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
        ptr[i] = 1;
        printf("ptr[%ld] = %d\n", i + pagesz - 1, ptr[i + pagesz - 1]);
        ptr[i + pagesz - 1] = 1;
    }
    printf("ptr[%d] = %d\n", i, ptr[i]);

    return 0;
}
