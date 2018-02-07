#!/bin/python3
"""
https://www.hackerrank.com/contests/projecteuler/challenges/euler001
"""

import sys

from operator import add
from functools import reduce

def solution(number):
    def gen(max_num):
        for n in range(max_num):
            if n % 3 == 0 or n % 5 == 0:
                yield n
    return reduce(add, gen(number))

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(solution(n))
