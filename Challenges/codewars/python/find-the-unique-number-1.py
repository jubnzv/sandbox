'''
https://www.codewars.com/kata/find-the-unique-number-1

There is an array with some numbers. All numbers are equal except for one. Try to find it!

findUniq([ 1, 1, 1, 2, 1, 1 ]) === 2
findUniq([ 0, 0, 0.55, 0, 0 ]) === 0.55
It’s guaranteed that array contains more than 3 numbers.

The tests contain some very huge arrays, so think about performance.

This is the first kata in series:

Find the unique number (this kata)
Find the unique string
Find The Unique
'''
def find_uniq(arr):
    s = set(arr)
    return filter(lambda x: arr.count(x) == 1, s)[0]
