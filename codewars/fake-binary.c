/* https://www.codewars.com/kata/fake-binary/
 *
 * Given a string of digits, you should replace any digit below 5 with '0' and any digit 5 and above with '1'. Return the resulting string. */
void fakeBin(const char *d, char *buf) {
    int i = 0;
    for (i; d[i]!='\0'; i++)
        buf[i] = (d[i]-48 < 5) ? '0' : '1';
    buf[i] = '\0';
}
