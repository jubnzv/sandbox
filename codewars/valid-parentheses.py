#!/usr/bin/python3.6
#
# https://www.codewars.com/kata/valid-parentheses/train/python
#
# Write a function called that takes a string of parentheses, and determines
# if the order of the parentheses is valid. The function should return true
# if the string is valid, and false if it's invalid.
#
#  Examples
#  "()"              =>  true
#  ")(()))"          =>  false
#  "("               =>  false
#  "(())((()())())"  =>  true

def valid_parentheses(s):
    if len(s) == 0:
        return True
    s = list(s)
    for i,c in enumerate(s):
        if s[i] == ')':
            return False
        if s[i] != '(':
            continue
        print(s[i])
        s[i] = '.'
        try:
            pos = s.index(')')
        except ValueError:
            return False
        s[pos] = '.'
    return True
