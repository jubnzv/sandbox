'''
https://www.codewars.com/kata/even-odd-disparity

Given an array, return the difference between the count of even numbers and the count of odd numbers. `0` will be considered an even number. 

For example, solve(`[0,1,2,3]) = 0` because there are two even numbers and two odd numbers. `Even - Odd = 2 - 2 = 0`.  

Let's now add two letters to the last example: solve(`[0,1,2,3,'a','b']) = 0`. Again, `Even - Odd = 2 - 2 = 0`. Ignore letters. 

The input will be an array of lowercase letters and numbers only. 

Good luck!

If you like this Kata, please try: 

[Longest vowel chain](https://www.codewars.com/kata/59c5f4e9d751df43cf000035)

[Word values](https://www.codewars.com/kata/598d91785d4ce3ec4f000018)
'''
def solve_1(a):
    l = [i for i in a if isinstance(i, int)]
    return len(l) - 2 * len([i for i in l if i % 2])

solve = lambda a: sum(-1 if i % 2 else 1 for i in a if isinstance(i, int))

if __name__ == '__main__':
    print(solve([1,2,3,4]))
    print(solve([1,'foo',3,4]))
    print(solve([1,2,3]))
