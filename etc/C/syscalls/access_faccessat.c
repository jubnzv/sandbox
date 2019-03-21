/* The check is done using the calling process's real UID and GID, rather than the effective IDs */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define DIRP1   "/tmp/"
#define FP1     "foo_1.txt"
#define P1      "/tmp/foo_1.txt" /* meh */

void test_access(void)
{
    printf("%s %s:\n", __func__, FP1);
    printf(" exists: %d\n", access(FP1, F_OK));
    printf(" can read: %d\n", access(FP1, R_OK));
    printf(" can write: %d\n", access(FP1, W_OK));
    printf(" can exec: %d\n", access(FP1, X_OK));
    printf("\n");
}

void run_access_test(void)
{
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "touch %s", FP1);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "ls -l %s", FP1);
    system(cmd);
    test_access();

    snprintf(cmd, sizeof(cmd), "chmod 400 %s", FP1);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "ls -l %s", FP1);
    system(cmd);
    test_access();

    snprintf(cmd, sizeof(cmd), "chmod 000 %s", FP1);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "ls -l %s", FP1);
    system(cmd);
    test_access();

    snprintf(cmd, sizeof(cmd), "rm %s", FP1);
    system(cmd);
}

void test_faccessat(int dirfd, int flags)
{
    printf("%s %s:\n", __func__, FP1);
    printf(" exists: %d\n", faccessat(dirfd, FP1, F_OK, flags));
    printf(" can read: %d\n", faccessat(dirfd, FP1, R_OK, flags));
    printf(" can write: %d\n", faccessat(dirfd, FP1, W_OK, flags));
    printf(" can exec: %d\n", faccessat(dirfd, FP1, X_OK, flags));
    printf("\n");
}

void run_faccessat_test(void)
{
    char cmd[1024];
    int dirfd;

    struct stat *statbuf;
    if ((stat(P1, statbuf)) == 0)
        printf("inode=%ld\n", (long)statbuf->st_ino);

    /* Relative directory for faccessat */
    snprintf(cmd, sizeof(cmd), "mkdir -p %s", DIRP1);
    system(cmd);
    if ((dirfd = open(DIRP1, O_DIRECTORY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    snprintf(cmd, sizeof(cmd), "touch %s", FP1);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "ls -li %s", FP1);
    system(cmd);

    /*
     * OK: resolve path relatively for the calling process like `access`.
     * Consider inode numbers in output.
     */
    test_faccessat(dirfd, 0);

    snprintf(cmd, sizeof(cmd), "touch %s/%s", DIRP1, FP1);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "ls -li %s/%s", DIRP1, FP1);
    system(cmd);

    snprintf(cmd, sizeof(cmd), "chmod 400 %s/%s", DIRP1, FP1);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "ls -li %s/%s", DIRP1, FP1);
    system(cmd);
    test_access();

    snprintf(cmd, sizeof(cmd), "chmod 000 %s", FP1);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "ls -li %s/%s", DIRP1, FP1);
    system(cmd);
    test_access();

    /* Clean up */
    snprintf(cmd, sizeof(cmd), "rm -f %s", FP1);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "rm -f %s/%s", DIRP1, FP1);
    system(cmd);
}

int main(int argc, char const* argv[])
{
    run_access_test();
    run_faccessat_test();
    return 0;
}
