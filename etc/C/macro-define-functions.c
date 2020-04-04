#include <stdio.h>
#define COORD_OPERATOR(NAME) void OP_##NAME() { printf("calling %s\n", #NAME); }
#define DEF_COORD(...) {  }

COORD_OPERATOR(A);

int main(int argc, char *argv[])
{
    OP_A();
    return 0;
}
