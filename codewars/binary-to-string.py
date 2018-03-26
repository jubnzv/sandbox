#!/usr/bin/python3
# https://www.codewars.com/kata/binary-to-string

# Your computer has forgotten how to speak ASCII! (or Unicode, whatever) It can only communicate in binary, and it has something important to tell you. Write a function which will receive a long string of binary code and convert it to a string. Remember, in Python binary output starts with '0b'.

# As an example: binary_to_string('0b10000110b11000010b1110100') == 'Cat'

# Input may consist of upper and lower case letters and numbers, in binary form of course, as well as special symbols. The input to your function will always be one string of binary.
def binary_to_string(bs): return ''.join([chr(int(bc, 2)) for bc in bs.split('0b')[1:]])

if __name__ == '__main__':
    print(binary_to_string('0b10000110b11000010b1110100'))
