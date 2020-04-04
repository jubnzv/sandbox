#include <stdio.h>
#include <string.h>

#define SIZE 20

int main(int argc, char const *argv[])
{
    char s[SIZE] = {0};
    printf("%s:%d s=%s len=%d (s==NULL)=%d\n", __func__, __LINE__, s, strlen(s),
        s == NULL);
    strncpy(s, "0.0.0.0", SIZE);
    printf("%s:%d s=%s len=%d (s==NULL)=%d\n", __func__, __LINE__, s, strlen(s),
        s == NULL);
    return 0;
}
