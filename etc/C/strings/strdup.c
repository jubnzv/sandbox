#include <stdio.h>
#include <string.h>

char *get_string(void)
{
    const char foo[] = "nevermind";
    return strdup(foo);
}

int main(int argc, char const *argv[])
{
    printf("%s\n", get_string());
    return 0;
}

