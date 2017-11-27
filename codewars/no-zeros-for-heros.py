'''
https://www.codewars.com/kata/no-zeros-for-heros

Numbers ending with zeros are boring.

They might be fun in your world, but not here.

Get rid of them. Only the ending ones.

    1450 -> 145
    960000 -> 96
    1050 -> 105
    -1050 -> -105
    
Zero alone is fine, don't worry about it. Poor guy anyway
'''
import re

def no_boring_zeros(n):
    return int(re.split(r'0+$', str(n))[0]) if n else 0

if __name__ == '__main__':
    print(no_boring_zeros(1450))
    print(no_boring_zeros(9600000))
    print(no_boring_zeros(1050))
    print(no_boring_zeros(-1050))
    print(no_boring_zeros(0))
