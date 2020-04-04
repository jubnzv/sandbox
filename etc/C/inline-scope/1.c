#include <assert.h>

extern int foo(void);

// Cause undefined refernce error.
// extern int foo_inline(void);

int main(int argc, char const* argv[])
{
    assert(foo() == 19);
    // assert(foo_inline() == 42);
    return 0;
}
