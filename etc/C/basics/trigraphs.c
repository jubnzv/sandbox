// Compile with: gcc triggraphs.c -trigraphs
??=include <stdio.h>                         /* #          */

int main(void)
??<                                          /* {          */
        char n??(5??);                       /* [ and ]    */

        n??(4??) = '0' - (??-0 ??' 1 ??! 2); /* ~, ^ and | */
        printf("%c??/n", n??(4??));          /* ??/ = \    */
        return 0;
??>
