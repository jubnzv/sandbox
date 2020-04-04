#include <stdio.h>

void foo(void)
{
    static int buf = 42;
    buf++;
    printf("buf=%d\n", buf);
}

int main(int argc, char const* argv[])
{
    foo();
    foo();
    return 0;
}
