'''
https://www.codewars.com/kata/525f50e3b73515a6db000b83/

Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.

Example:

create_phone_number([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) # => returns "(123) 456-7890"
The returned format must be correct in order to complete this challenge.
Don't forget the space after the closing parenthesis!
'''
create_phone_number = lambda n: "({0}) {1}-{2}".format(*tuple([''.join(map(str, t)) for t in [n[:3], n[3:6], n[6:10]]]))
create_phone_number_r1 = lambda n: "({}{}{}) {}{}{}-{}{}{}{}".format(*n)

if __name__ == '__main__':
    l = [i for i in range(10)]
    print(create_phone_number_r1(l))
