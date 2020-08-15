/* https://www.codewars.com/kata/53dc54212259ed3d4f00071c/train/c */

/* Sum Array
 * Write a method sum (sum_array in python, SumArray in C#) that takes an array of numbers and returns the sum of the numbers. These may be integers or decimals for Ruby and any instance of Num for Haskell. The numbers can also be negative. If the array does not contain any numbers then you should return 0.
 *
 * Examples
 * numbers = [1, 5.2, 4, 0, -1]
 * puts sum(numbers)
 * 9.2
 * Assumptions
 * You can assume that you are only given numbers.
 * You cannot assume the size of the array.
 * You can assume that you do get an array and if the array is empty, return 0.
 * What We're Testing
 * We're testing basic loops and math operations. This is for beginners who are just learning loops and math operations.
 *
 * Disclaimer
 * This is for beginners so we want to test basic loops and math operations. Advanced users may find this extremely easy and can easily write this in one line. */

#include <stddef.h>

int sum_array(const int *values, size_t count)
{
    int sum = 0;
    for (int i=0; i<count; i++) sum += values[i];
    return sum;
}
