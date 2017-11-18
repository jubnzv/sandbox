'''
https://www.codewars.com/kata/persistent-bugger/

Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.

For example:

 persistence(39) => 3  # Because 3*9 = 27, 2*7 = 14, 1*4=4
                       # and 4 has only one digit.

 persistence(999) => 4 # Because 9*9*9 = 729, 7*2*9 = 126,
                       # 1*2*6 = 12, and finally 1*2 = 2.

 persistence(4) => 0   # Because 4 is already a one-digit number.
'''
from functools import reduce

def persistence(n):
    count = 0
    while n >= 10:
        n = reduce(lambda x,y: x*y, [int(x) for x in str(n)])
        count += 1
    return count

if __name__ == '__main__':
    print(persistence(39))
    print(persistence(4))
    print(persistence(25))
    print(persistence(999))
