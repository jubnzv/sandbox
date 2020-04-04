#include <stdio.h>

struct in {
    int a;
    char b;
};

#pragma pack(push, 4)
struct out {
    char a;
    struct in i;
    char a1;
};
#pragma pack(pop)

int main(int argc, char const* argv[])
{
    struct in i;
    struct out o;
    printf("sizeof_in=%d sizeof_out=%d\n", sizeof(i), sizeof(o));
    fflush(stdout);
    return 0;
}
