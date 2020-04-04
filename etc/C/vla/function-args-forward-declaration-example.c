#include <stdio.h>

void func(int len; int x[len], int len)
{
    while (len--) {
        printf("%d\n", x[len]);
        x[len] = 0;
    }
}

int main()
{
    int x[] = {1, 2, 3, 4};
    func(x, sizeof(x) / sizeof(*x));
    func(x, sizeof(x) / sizeof(*x) + 1);
}
