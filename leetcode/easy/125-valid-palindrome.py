#!/usr/local/bin/python3.6
'''
https://leetcode.com/problems/valid-palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
'''

from string import ascii_lowercase, digits

def isPalindrome(s):
    if not s:  # empty string
        return True

    fs = ''.join(c for c in s.lower() if c in ascii_lowercase or c in digits)
    for i in range(0, len(fs)//2):
        if fs[i] != fs[-i-1]:
            return False

    return True

if __name__ == '__main__':
    print(isPalindrome("A man, a plan, a canal: Panama"))
    print(isPalindrome("0P"))
    print(isPalindrome("race a car"))
