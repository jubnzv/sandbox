'''
https://www.codewars.com/kata/pascals-triangle-number-2/train/python

Here you will create the classic pascal's triangle. Your function will be passed the depth of the triangle and you code has to return the corresponding pascal triangle upto that depth

The triangle should be returned as a nested array.

Note: For JavaScript version, your final result is a string representation of the array. Sorry for the inconvenience, test cases are locked so this is the best I could do.

- V
for example:

pascal(5) # should return [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
To build the triangle, start with a single 1 at the top, for each number in the next row you just take the two numbers above it and add them together (except for the edges, which are all "1"). eg

          [1]
        [1   1]
       [1  2  1]
      [1  3  3  1]
here you get the 3 by adding the 2 and 1 above it.
'''
from operator import add

def pascal(p):
    if p == 1:
        return [[1]]
    if p == 2:
        return [[1], [1, 1]]
    else:
        result = [1] * p
        prev = pascal(p-1)
        for i in range(1, p-1):
            result[i] = add(prev[p-1-1][i-1], prev[p-1-1][i])
        return prev + [result]


if __name__ == '__main__':
    print(pascal(1))
    print(pascal(5))
