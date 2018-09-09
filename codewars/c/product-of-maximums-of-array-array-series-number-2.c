// https://www.codewars.com/kata/product-of-maximums-of-array-array-series-number-2/
//
// Task
// Given an array/list [] of integers, Find the product of the k maximal
// numbers.
//
// Notes
// Array/list size is at least 3.
// Array/list's numbers Will be mixture of positives, negatives and zeros
// Repeatition of numbers in the array/list could occur.

#include <stdlib.h>

int cmp(const void * a, const void * b)
{
   return (*(int*)b - *(int*)a);
}

int maxProduct (int numbers[], int numbers_size, int sub_size)
{
    int prod = 1;

    qsort(numbers, numbers_size, sizeof(int), cmp);

    for (int i = 0; i < sub_size; i++) {
        prod *= numbers[i];
    }

    return prod;
}
