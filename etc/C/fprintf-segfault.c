// Creepy segfault on arm-crosscompilation related with fprintf formatting.
// arm-linux-gnueabihf-gcc (Debian 8.3.0-2) 8.3.0
//
// See inttypes.h:
// # if __WORDSIZE == 64
// #  define __PRI64_PREFIX	"l"
// #  define __PRIPTR_PREFIX	"l"
// # else
// #  define __PRI64_PREFIX	"ll"
// #  define __PRIPTR_PREFIX
// # endif
//
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    uint64_t b = 1, c = 2, d = 3, e = 4;

    // Segfault:
    // fprintf(fp, "%-10s %-20d %10lu %10lu %10lu %10lu %10s\n",
    //         "Task", a, b, c, d, e, "-");

    // OK:
    fprintf(stderr, "%-10s %-20d %10llu %10llu %10llu %10llu %10s\n",
            "-", a, b, c, d, e, "-");

    // Correct:
    fprintf(stderr, "%-10s %-20d %10" PRIu64 " %10" PRIu64 " %10" PRIu64 " %10" PRIu64 " %10s\n",
            "-", a, b, c, d, e, "-");

    return 0;
}
