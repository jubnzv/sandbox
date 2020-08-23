'''
https://www.codewars.com/kata/the-first-non-repeated-character-in-a-string

You need to write a function, that returns the first non-repeated character in the given string.

For example for string `"test"` function should return `'e'`.  
For string `"teeter"` function should return `'r'`.  
  
If a string contains all unique characters, then return just the first character of the string.  
Exanple: for input `"trend"` function should return `'t'`  
  
You can assume, that the input string has always non-zero length.
'''
def first_non_repeated(s):
    for c in s:
        if s.count(c) == 1:
            return c
        s = s.translate(None, c)
    return ''

if __name__ == '__main__':
    print(first_non_repeated("test"))
    print(first_non_repeated("teeter"))
    print(first_non_repeated("121121212121212521212123"))
