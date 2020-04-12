#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pipes[4];

    // Create two pipes
    pipe(pipes);
    pipe(pipes + 2);

    // Execute cat
    if (fork() == 0) {
        // Replace output with write end of first pipe
        dup2(pipes[1], 1);

        // Close all ends of pipes (we already copied it with `dup2`)
        close(pipes[0]);
        close(pipes[1]);
        close(pipes[2]);
        close(pipes[3]);

        char *exp[] = {"cat", "stackoverflow/filename.txt", NULL};
        execvp(exp[0], exp);
        perror("cat failed");
        exit(EXIT_FAILURE);
    } else {
        // Execute first grep
        if (fork() == 0) {
            // Replace input with read end of 1st pipe
            dup2(pipes[0], 0);

            // Replace output with write end of 2nd pipe
            dup2(pipes[3], 1);

            // Close all ends of pipes
            close(pipes[0]);
            close(pipes[1]);
            close(pipes[2]);
            close(pipes[3]);

            char *exp[] = {"grep", "-w", "stringname", NULL};
            execvp(exp[0], exp);
            perror("first grep failed");
            exit(EXIT_FAILURE);
        } else {
            // Execute second grep
            if (fork() == 0) {
                // Replace input with read end of 2nd pipe
                dup2(pipes[2], 0);

                // Close all ends of pipes
                close(pipes[0]);
                close(pipes[1]);
                close(pipes[2]);
                close(pipes[3]);

                char *exp[] = {"grep", "-c", "stringname", NULL};
                execvp(exp[0], exp);
                perror("second grep failed");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Close all ends of pipes
    close(pipes[0]);
    close(pipes[1]);
    close(pipes[2]);
    close(pipes[3]);

    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
}
