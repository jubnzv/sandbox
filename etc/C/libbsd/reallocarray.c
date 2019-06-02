/** reallocarray(3) usage example. */
#include <bsd/bsd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const* argv[])
{
    int *arr = NULL;

    arr = reallocarray(NULL, 10, sizeof(int));
    if (!arr) {
        perror("reallocarray");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        printf("a[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}

