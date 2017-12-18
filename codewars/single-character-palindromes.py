'''
https://www.codewars.com/kata/single-character-palindromes

You will be given a string and you task is to check if it is possible to convert that string into a palindrome by removing a single character. If the string is already a palindrome, return `"OK"`. If it is not, and we can convert it to a palindrome by removing one character, then return `"remove one"`, otherwise return `"not possible"`. The order of the characters should not be changed.

For example:
```Haskell
solve("abba") = "OK". -- This is a palindrome
solve("abbaa") = "remove one". -- remove the 'a' at the extreme right. 
solve("abbaab") = "not possible". 
```

More examples in the test cases. 

Good luck!
'''
def solve(s):
    is_palindrome = lambda a: a == a[::-1]
    for i in range(0, len(s)):
        if is_palindrome(s):
            return 'OK'
        elif is_palindrome(s[:i] + s[i+1:]):
            return 'remove one'
    return 'not possible'
