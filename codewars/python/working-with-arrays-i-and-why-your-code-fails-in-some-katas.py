#/usr/bin/python2.7
# https://www.codewars.com/kata/working-with-arrays-i-and-why-your-code-fails-in-some-katas/train/python
def without_last(lst):
    lst = lst[:len(lst)-1]
    return lst
