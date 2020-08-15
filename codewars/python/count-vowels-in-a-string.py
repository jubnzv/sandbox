'''
https://www.codewars.com/kata/count-vowels-in-a-string/

Write a function count_vowels to count the number of vowels in a given string.

Notes:
Return nil or None for non-string inputs.
Return 0 if the parameter is omitted.
Examples:
count_vowels("abcdefg") => 2
count_vowels("aAbcdeEfg") => 4

count_vowels(12) => None
'''
from collections import Counter
def count_vowels(s = ''):
    if not isinstance(s, str): return None
    c = Counter(str(s))
    return sum([c[n] for n in 'aeiou'+'AEIOU'])

