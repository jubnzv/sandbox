/// Check asm output with different sizes.
/// References:
/// [0]: https://github.com/bminor/glibc/tree/d7a568af5546e0313abbc04060c8e9b0d3f750b4/string/strspn.c#L41
/// [1]: https://habr.com/ru/post/272269/
/// [2]: https://augias.org/paercebal/tech_doc/doc.en/cp.memset_is_evil.html
#include <string.h>

// #define SIZE    64
#define SIZE    123

int main(int argc, char const* argv[])
{
    char a[SIZE];
    memset(a, 0, SIZE);
    a[19] = 23;
    return 0;
}
