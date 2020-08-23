// https://www.codewars.com/kata/5aff237c578a14752d0035ae/
//
// My grandfather always predicted how old people would get, and right before he passed away he revealed his secret!
//
// In honor of my grandfather's memory we will write a function using his formula!
//
// Take a list of ages when each of your great-grandparent died.
// Multiply each number by itself.
// Add them all together.
// Take the square root of the result.
// Divide by two.
// Example
// predictAge(65, 60, 75, 55, 60, 63, 64, 45) === 86
// Note: the result should be rounded down to the nearest integer.

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>

//  Accepts the ages of 8 great-grandparents and predicts the age of death of the grandchild according to the formula in the description.
//  arg0         = (uint64_t) An age.
//  arg1         = (uint64_t) An age.
//  arg2         = (uint64_t) An age.
//  arg3         = (uint64_t) An age.
//  arg4         = (uint64_t) An age.
//  arg5         = (uint64_t) An age.
//  arg6         = (uint64_t) An age.
//  arg7         = (uint64_t) An age.
//  return value = (uint64_t) The predicted age of death.
uint64_t predict_age(uint64_t age1, uint64_t age2, uint64_t age3, uint64_t age4, uint64_t age5, uint64_t age6, uint64_t age7, uint64_t age8)
{
    return (uint64_t)(0.5 * sqrt((pow(age1, 2))+(pow(age2, 2))+(pow(age3, 2))+(pow(age4, 2))+(pow(age5, 2))+(pow(age6, 2))+(pow(age7, 2))+(pow(age8, 2))));
}

int main(void)
{
    printf("%" PRIu64 "\n", predict_age(65, 60, 75, 55, 60, 63, 64, 45));
    return 0;
}
