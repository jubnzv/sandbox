'''
http://www.codewars.com/kata/indexed-capitalization/train/python

Given a string and an array of integers representing indices, capitalize all letters at the given indices.

For example:

capitalize("abcdef",[1,2,5]) = "aBCdeF"
capitalize("abcdef",[1,2,5,100]) = "aBCdeF". There is no index 100.
The input will be a lowercase string with no spaces and an array of digits.
'''
capitalize = lambda s, ind: ''.join([(l, l.upper())[i in ind] for i, l in enumerate(s)])

if __name__ == '__main__':
    print(capitalize("foooobar", [1,2,3,7]))
