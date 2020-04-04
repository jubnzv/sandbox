#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char const* argv[])
{
    uint16_t foo = 19;
    printf("Test multiline printf: %" PRIu16
            ". It's ok.", foo);
    return 0;
}

