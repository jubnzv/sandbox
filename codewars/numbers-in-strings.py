'''
https://www.codewars.com/kata/numbers-in-strings/train/python

In this Kata, you will be given a string that has lowercase letters and numbers. Your task is to compare the number groupings and return the largest number.

For example, solve("gh12cdy695m1") = 695, because this is the largest of all number groupings.
'''
import re
solve = lambda s: max([int(n) for n in filter(None, re.split(r'\D', s))])

if __name__ == '__main__':
    print(solve('gh12cdy695m1'))
    print(solve('2ti9iei7qhr5'))
    print(solve('f7g42g16hcu5'))
    print(solve('lu1j8qbbb85'))
