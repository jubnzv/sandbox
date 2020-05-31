// Reference: n1256 Appendix A 6.4.2.1
#include <assert.h>
int main(int argc, char *argv[])
{
    int _ = 42;
    assert(_++ == 42);
    return 0;
}
