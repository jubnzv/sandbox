/* Writing in FILE stream after inode deletion does not cause any error. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_PATH   "/tmp/foo.txt"

int main(int argc, char const* argv[])
{
    pid_t child_pid;
    char cmd[256];
    snprintf(cmd, 255, "echo 19 > %s\0", FILE_PATH);
    printf("cmd=%s\n", cmd);
    system(cmd);

    switch (child_pid = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0: {
            sleep(3);
            snprintf(cmd, 255, "rm %s\0", FILE_PATH);
            system(cmd);
            exit(EXIT_SUCCESS);
        }
        default: {
            char data[16];
            int res;
            FILE *fp;

            fp = fopen(FILE_PATH, "wb");
            if (fp == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }

            for (size_t i = 0; i < 10; i++) {
                snprintf(data, 15, "%ld", (long)i);
                res = fwrite(data, sizeof(data), 1, fp);
                printf("%s:%d fwrite returns: %d\n", __func__, __LINE__, res);
                res = fread(data, sizeof(data), 1, fp);
                printf("%s:%d fread returns: %d data=%s\n", __func__, __LINE__, res, data);
                sleep(1);
            }
            break;
        }
    }
    return 0;
}
