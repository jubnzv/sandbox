'''
https://www.codewars.com/kata/alternate-capitalization

Given a string, capitalize the letters that occupy even indexes and odd indexes separately, and return as shown below. Index `0` will be considered even.

For example, `capitalize("abcdef") = ['AbCdEf', 'aBcDeF']`. See test cases for more examples.

The input will be a lowercase string with no spaces.

Good luck!

If you like this Kata, please try: 

[Indexed capitalization](https://www.codewars.com/kata/59cfc09a86a6fdf6df0000f1)

[Even-odd disparity](https://www.codewars.com/kata/59c62f1bdcc40560a2000060)
'''
def capitalize_1(s):
    result = ["", ""]
    for i,v in enumerate(s):
        if i % 2:
            result[0] += v
            result[1] += v.upper()
        else:
            result[0] += v.upper()
            result[1] += v
    return result

def capitalize(s):
    s = ''.join(c if i%2 else c.upper() for i,c in enumerate(s))
    return [s, s.swapcase()]

if __name__ == '__main__':
    print(capitalize("foobar"))
