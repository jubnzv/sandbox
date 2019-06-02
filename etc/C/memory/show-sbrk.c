#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    char *heap_ptr;
    size_t num = 2048;

    if (argc == 1) {
        printf("Current program break: %p\n", sbrk(0));
        exit(EXIT_SUCCESS);
    }

    num = strtoul(argv[1], 0, 10);
    if ((errno == ERANGE && num == ULONG_MAX) || (errno != 0 && num == 0) ) {
        perror("strtoul");
        exit(EXIT_FAILURE);
    }

    uint64_t orig_brk = (uint64_t)sbrk(0);
    printf("Original program break: %16" PRIx64 "\n", orig_brk);
    heap_ptr = malloc(num);
    uint64_t cur_brk = (uint64_t)sbrk(0);
    printf("malloc(%lu) = %p\n", num, heap_ptr);
    printf("Current program break: %16" PRIx64 "\n", cur_brk);
    printf("(%" PRIu64 " bytes from original brk)\n", cur_brk - orig_brk);
    free(heap_ptr);

    return 0;
}
