'''
https://www.codewars.com/kata/opposite-number

Very simple, given a number, find its opposite.

Examples:

1: -1
14: -14
-34: 34
But can you do it in 1 line of code and without any conditionals?
'''
opposite = lambda n: -n

if __name__ == '__main__':
    print(opposite(-1))
    print(opposite(1000000000))
