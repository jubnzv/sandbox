'''
https://codefights.com/arcade/intro/level-2/xzKiBHjhoinnpdh6m

Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.
'''
from itertools import tee
from operator import mul
def adjacentElementsProduct(l):
    def pairwise(s):  # https://docs.python.org/3/library/itertools.html#itertools-recipes
        a, b = tee(s)
        next(b, None)
        return zip(a, b)
    return max([mul(i1,i2) for i1,i2 in pairwise(l)])
