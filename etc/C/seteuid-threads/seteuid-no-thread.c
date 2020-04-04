#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    getchar();
    getchar();
    printf("seteuid: rc=%d\n", seteuid(0));
    return 0;
}
