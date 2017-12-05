'''
https://www.codewars.com/kata/unique-string-characters

In this Kata, you will be given two strings `a` and `b` and your task will be to return the characters that are not common in the two strings. 

For example:
```Haskell
solve("xyab","xzca") = "ybzc" 
--The first string has 'yb' which is not in the second string. 
--The second string has 'zc' which is not in the first string. 
```
Notice also that you return the characters from the first string concatenated with those from the second string.

More examples in the tests cases. 

Good luck!

'''
def solve(s1, s2):
    return ''.join([c1 for c1 in s1 if c1 not in s2]+[c2 for c2 in s2 if c2 not in s1])
