// http://www.codewars.com/kata/5a87449ab1710171300000fd/train/c
//
// Definition
// A Tidy number is a number whose digits are in non-decreasing order.
//
// Task
// Given a number, Find if it is Tidy or not .
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool tidyNumber(int n)
{
    char sn[100];
    sprintf(sn, "%d", n);

    if (strlen(sn) == 1) {
        return true;
    }

    for (int i = 1; i < strlen(sn); i++) {
        if (sn[i] < sn[i-1]) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    printf("12 is tidy: %d\n", tidyNumber(12));
    printf("32 is tidy: %d\n", tidyNumber(32));
    printf("39 is tidy: %d\n", tidyNumber(39));
    return 0;
}
