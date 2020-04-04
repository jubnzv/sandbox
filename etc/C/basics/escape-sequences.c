// References:
// * n1570 6.4.4.4
// * https://trac.cppcheck.net/ticket/9370
// *
// https://sourceforge.net/p/cppcheck/discussion/development/thread/7274ed3842/?limit=25#799a
#include <assert.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Test octal escape sequences.
    {
        char semicolon = '\072'; // \072 is 58 int -- ':' symbol
        printf("%c\n", semicolon);
        assert(semicolon == ':');
    }

    // Multi-character character constants are implementation-defined.
    {
        int a = '\111\111';
        printf("a=%x\n", a); // 4949
    }

    // How does unknown sequences work?
    // {
    //     printf("%s\n", "test\gtest");
    // }

    return 0;
}
