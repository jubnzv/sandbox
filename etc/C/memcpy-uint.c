#include <assert.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[])
{
    uint64_t a = 42;

    uint8_t b = a;
    assert(b == 42);

    uint8_t c = 0;
    memcpy(&c, &a, sizeof(c));
    assert(c == 42);

    return 0;
}
