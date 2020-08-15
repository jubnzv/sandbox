#!/bin/python3
"""
https://www.hackerrank.com/contests/projecteuler/challenges/euler001
"""

import sys
from functools import reduce
from operator import add


def mul_gen(max_num):
    for n in range(max_num):
        if n % 3 == 0 or n % 5 == 0:
            yield n

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    if n > pow(10, 9): continue
    else: print(reduce(add, mul_gen(number)))
