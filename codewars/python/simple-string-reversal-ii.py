#!/usr/local/bin/python3.6

# https://www.codewars.com/kata/simple-string-reversal-ii
# In this Kata, you will be given a string and two indexes. Your task is to reverse the portion of that string between those two indexes inclusive.

# solve("codewars",1,5) = "cawedors" -- elements at index 1 to 5 inclusive are "odewa". So we reverse them.
# solve("cODEWArs", 1,5) = "cAWEDOrs" -- to help visualize.
# Input will be lowercase and uppercase letters only.
from __future__ import print_function


def solve(st, a, b): return ''.join([st[:a], ''.join(reversed(st[a:b+1])), st[b+1:]])


if __name__ == '__main__':
    print(solve("codewars", 1, 5))
    print(solve("codingIsFun", 2, 100))
    print(solve("abcefghijklmnopqrstuvwxyz", 0, 20))
def solve(st, a, b): return ''.join([st[:a], ''.join(reversed(st[a:b+1])), st[b+1:]])
