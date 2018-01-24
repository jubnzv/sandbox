'''
https://www.codewars.com/kata/magic-sum-of-3s

The magic sum of 3s is calculated on an array by summing up odd numbers which include the digit 3. Write a function magic_sum which accepts an array of integers and returns the sum.

Example: [3, 12, 5, 8, 30, 13] results in 16 (3 + 13)

If the sum cannot be calculated, 0 should be returned.
'''
def magic_sum(arr):
    if arr:
        return sum([i for i in arr if '3' in str(i) and i%2])
    return 0
