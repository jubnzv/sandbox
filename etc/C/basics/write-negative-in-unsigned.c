#include <stdint.h>
#include <stdio.h>

static int foo() { return -1; }

int main(int argc, char const *argv[])
{
    uint8_t res = foo();
    printf("res=%d\n", res);
    return 0;
}
