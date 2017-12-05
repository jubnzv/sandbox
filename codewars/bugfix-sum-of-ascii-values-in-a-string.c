/*
https://www.codewars.com/kata/bugfix-sum-of-ascii-values-in-a-string

# Task

The given function `sum_ascii` is supposed to find the sum of ASCII values
of all characters in the given string.

However, it has a very subtle problem in the code, so it does not pass the tests.

Analyze the code carefully, and fix it to pass all tests.
*/
int sum_ascii(char *str)
{
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        sum += str[i];
    }
    return sum;
}
