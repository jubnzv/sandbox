#!/usr/local/bin/python3.6
'''
https://leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. Do this without extra space.
'''

def isPalindrome(x):
    if x < 0:  # negative numbers is not palindromes here
        return False

    for i in range(len(str(x))//2):
        if int(str(x)[i]) != int(str(x)[-i-1]):
            return False
    return True

if __name__ == '__main__':
    print(isPalindrome(19))
    print(isPalindrome(-2147483648))
    print(isPalindrome(-2147447412))
    print(isPalindrome(345543))
    print(isPalindrome(3334333))
