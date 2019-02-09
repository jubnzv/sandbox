#include <stdio.h>

#define FPATH   "./f1.txt"

int main(int argc, char const* argv[])
{
    FILE *fs = fopen(FPATH, "r");
    char buf[32] = { 0 };
    fread(buf, sizeof(char), 2, fs);
    printf("%s\n", buf);
    fclose(fs);
    return 0;
}
