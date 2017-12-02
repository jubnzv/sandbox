'''
https://www.codewars.com/kata/coordinates-validator

You need to create a function that will validate if given parameters are valid geographical coordinates.

Valid coordinates look like the following: __"23.32353342, -32.543534534"__.
The return value should be either __true__ or __false__.

Latitude (which is first float) can be between 0 and 90, positive or negative.
Longitude (which is second float) can be between 0 and 180, positive or negative.

Coordinates can only contain digits, or one of the following symbols (including space after comma) __ -, . __

There should be no space between the minus "-" sign and the digit after it.

Here are some valid coordinates:

* -23, 25
* 24.53525235, 23.45235
* 04, -23.234235
* 43.91343345, 143
* 4, -3

And some invalid ones:

* 23.234, - 23.4234
* 2342.43536, 34.324236
* N23.43345, E32.6457
* 99.234, 12.324
* 6.325624, 43.34345.345
* 0, 1,2
* 0.342q0832, 1.2324
'''
import re
def is_valid_coordinates(cordinates):
    print cordinates
    p = re.compile(r'^(-?(\d+)(\.\d+)?), (-?(\d+)(\.\d+)?)$')
    m = p.match(cordinates)
    if not m:
        return False
    else:
        _, c1i, c1f, _, c2i, c2f = m.groups()
        if int(c1i) == 90 and c1f: return False
        if int(c2i) == 90 and c2f: return False
        return True if int(c1i) in xrange(0, 91) and int(c2i) in xrange(0, 181) else False


if __name__ == '__main__':
    # print(is_valid_coordinates("-23 -25"))
    valid_coordinates = [
            "-23, 25",
            "4, -3",
            "24.53525235, 23.45235",
            "04, -23.234235",
            "43.91343345, 143"
            ]

    print("Valid coordinates:")
    for coordinate in valid_coordinates:
        print(is_valid_coordinates(coordinate))

    invalid_coordinates = [
        "23.234, - 23.4234",
        "2342.43536, 34.324236",
        "N23.43345, E32.6457",
        "99.234, 12.324",
        "6.325624, 43.34345.345",
        "0, 1,2",
        "0.342q0832, 1.2324",
        "23.245, 1e1"
        ]

    print("Invalid coordinates:")
    for coordinate in invalid_coordinates:
        print(is_valid_coordinates(coordinate))

