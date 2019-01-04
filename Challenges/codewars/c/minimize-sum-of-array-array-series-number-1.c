// https://www.codewars.com/kata/minimize-sum-of-array-array-series-number-1
//
// Task
// Given an array of intgers , Find the minimum sum which is obtained from
// summing each Two integers product.
//
// Notes
// Array/list will contain positives only .
// Array/list will always has even size
#include <stdlib.h>

int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int minSum(int passed[], int passed_size)
{
    int sum = 0;

    qsort(passed, passed_size, sizeof(int), cmp);

    for (int i = 0; i < (passed_size/2); i++) {
        sum += passed[i] * passed[passed_size-i-1];
    }

    return sum;
}
