'''
https://www.codewars.com/kata/contamination-number-1-string

An AI has infected a text with a character!! 

This text is now **fully mutated** to this character.

If the text or the character are empty, return an empty string.  
There never will be a case when both are empty as nothing is going on!!

_The character is a string. It will always be of length 1 if it's not empty._

Example:
```
before = "abc"
character = "z"
after = "zzz"
```
'''
contamination = lambda t, c: c*len(t)
