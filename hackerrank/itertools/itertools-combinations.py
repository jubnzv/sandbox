'''
https://www.hackerrank.com/challenges/itertools-combinations/problem

You are given a string . 
Your task is to print all possible combinations, up to size , of the string in lexicographic sorted order.

Input Format

A single line containing the string  and integer value  separated by a space.

Constraints

 
The string contains only UPPERCASE characters.

Output Format

Print the different combinations of string  on separate lines.

Sample Input

HACK 2
Sample Output

A
C
H
K
AC
AH
AK
CH
CK
HK
'''
from __future__ import print_function
from itertools import combinations

if __name__ == '__main__':
    S,k = raw_input().split(' ')
    for i in xrange(1, int(k)+1):
        for c in combinations(S, i):
            print(''.join(c))
