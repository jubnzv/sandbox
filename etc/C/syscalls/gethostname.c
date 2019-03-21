#include <stdio.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
    char buf[255];
    gethostname(buf, 255);
    printf("hostname=%s\n", buf);
    return 0;
}
