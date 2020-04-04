#include <stdio.h>

#define offsetof(type, field) ((long)&((type *)0)->field)

typedef struct {
    char a;
    long int b;
    float c;
} s1_t;

typedef struct {
    long int a;
    float b;
    char c;
} s2_t;

int main(int argc, char const *argv[])
{
    s1_t s1;
    s2_t s2;

    printf("offsetof(s1.b)=%ld\t%p\n", offsetof(s1_t, b), (&s1.b));
    printf("offsetof(s1.c)=%ld\t%p\n", offsetof(s1_t, c), (&s1.c));

    printf("\n");

    printf("offsetof(s2.b)=%ld\t%p\n", offsetof(s2_t, b), (&s2.b));
    printf("offsetof(s2.c)=%ld\t%p\n", offsetof(s2_t, c), (&s2.c));

    return 0;
}
