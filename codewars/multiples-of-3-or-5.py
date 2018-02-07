#!/usr/bin/python3
"""
https://www.codewars.com/kata/multiples-of-3-or-5/

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.

Note: If the number is a multiple of both 3 and 5, only count it once.

Courtesy of ProjectEuler.net
"""
from operator import add
from functools import reduce

def solution(number):
    def gen(max_num):
        for n in range(max_num):
            if n % 3 == 0 or n % 5 == 0:
                yield n
    return reduce(add, gen(number))

if __name__ == '__main__':
    print(solution(90000000))
