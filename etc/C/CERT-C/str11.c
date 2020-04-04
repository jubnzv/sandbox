#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    const char s1[3] = "abc";
    const char s2[] = "abc";
    const char s3[3] = {'a', 'b', 'c'};
    printf("s1=%s (%d %d)\n", s1, sizeof(s1), strlen(s1));
    printf("s2=%s (%d %d)\n", s2, sizeof(s2), strlen(s2));
    printf("s3=%s (%d %d)\n", s3, sizeof(s3), strlen(s3));
    return 0;
}
