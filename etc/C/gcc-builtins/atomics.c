// https://gcc.gnu.org/onlinedocs/gcc-4.8.0/gcc/_005f_005fatomic-Builtins.html
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    bool a = false;

    printf("a = %d\n", a);
    if (__atomic_compare_exchange()) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    printf("a = %d\n", a);

    return 0;
}
