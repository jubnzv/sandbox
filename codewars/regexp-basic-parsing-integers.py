'''
https://www.codewars.com/kata/regexp-basics-parsing-integers/train/python

Implement String#to_integer, which should return Integer if object is in one of formats specified below, or nil otherwise:

Optional - or +
Base prefix 0b (binary), 0x (hexadecimal), 0o (octal), or in case of no prefix decimal.
Digits depending on base
Any extra characters, including whitespace, make number invalid, in which case you should return nil.

Digits are case insensitive, but base prefix must be lower case.
'''
import re

def to_integer(string):
    pattern = re.compile(r'(?:^|^[+-])(0(b|x|o))?[0-9a-fA-F]*$', re.M)

    match = re.search(pattern, string)

    result = 0

    if match is None or '\n' in string:
        return None
    else:
        t = 1  # position of "type" letter
        isnegative = False

        if string[0] == '-':
            isnegative = True
            t = 2

        try:
            if string[t] == 'b':
                result = int(string[t+1:], 2)
            elif string[t] == 'x':
                result = int(string[t+1:], 16)
            elif string[t] == 'o':
                result = int(string[t+1:], 8)
            else:
                result = int(string[t-1:])
        except ValueError:  # type error such as 0b12
            return None

        if isnegative:
            result *= -1

        return result


if __name__ == '__main__':
    print(to_integer("3123213"))
    print(to_integer("sdsds0x0001df"))
    print(to_integer("0o23"))
    print(to_integer("0x32"))
    print(to_integer("0b12"))
    print(to_integer("123"))
    print(to_integer("\n123"))
    print(to_integer("123\n"))
    print(to_integer("s+0x32"))
    print(to_integer("-0x32"))
    print(to_integer("0x44"))
    print(to_integer("0243D101"))
