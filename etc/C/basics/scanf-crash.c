#include <stdio.h>

#define MAX_DNS_NAME_LEN 256
#define MAX_PATH_LEN 2048

#define MAX_URL_LEN (MAX_PATH_LEN + MAX_DNS_NAME_LEN + 1)

#define LSS 2

static const char buf[128] = "Location: nevermind.";

int main(int argc, char const *argv[])
{
    char location[MAX_URL_LEN];
    sscanf(buf, "%*[Ll]ocation: %LSS+1s", (char *)&location);
    printf("location=%s\n", location);
    return 0;
}
