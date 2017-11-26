'''
https://www.codewars.com/kata/three-sticks

Imagine that you are given two sticks. You want to end up with three sticks of equal length. You are allowed to cut either or both of the sticks to accomplish this, and can throw away leftover pieces.

Write a function, maxlen, that takes the lengths of the two sticks (L1 and L2, both positive values), that will return the maximum length you can make the three sticks.
'''
def maxlen(L1, L2):
    if max([L1, L2])/3 > min([L1, L2]):
        return max([L1, L2])/3
    elif max([L1, L2])/2 < min([L1, L2]):
        return max([L1, L2])/2
    else:
        return min(sorted([L1, L2, (L1+L2)/3]))

if __name__ == '__main__':
    print(maxlen(5, 12))
