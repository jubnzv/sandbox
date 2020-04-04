#include <stdlib.h>

int f(int a)
{
    (void)a;
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[])
{
    int A[] = {f(3), f(4)};
    exit(EXIT_SUCCESS);
}
