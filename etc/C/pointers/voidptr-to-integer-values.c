/* Convert *void to heterogeneous int arrays. */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    uint32_t a = 19; uint8_t anb = 4;
    uint16_t b = 42; uint8_t bnb = 2;
    uint32_t c = 30; uint8_t cnb = 4;

    void *storage = malloc(sizeof(uint32_t)*2 + sizeof(uint16_t));

    return 0;
}
