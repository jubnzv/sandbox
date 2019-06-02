#include <errno.h>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *heap_ptr;
    size_t num = 2048;

    if (argc == 1) {
        printf("Usage: %s <nb>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    num = strtoul(argv[1], 0, 10);
    if ((errno == ERANGE && num == ULONG_MAX) || (errno != 0 && num == 0)) {
        perror("strtoul");
        exit(EXIT_FAILURE);
    }

    heap_ptr = malloc(num);
    printf("malloc(%lu) = %p\n", num, heap_ptr);
    malloc_stats();
    free(heap_ptr);

    return 0;
}
