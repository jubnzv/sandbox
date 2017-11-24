'''
https://www.codewars.com/kata/pythagorean-triple

Given an array of 3 integers ```a, b and c```, determine if they form a pythagorean triple.

A pythagorean triple is formed when:
## c<sup>2</sup> = a<sup>2</sup> + b<sup>2</sup>

where `c` is the largest value of `a, b, c`.


For example: ```a = 3, b = 4, c = 5```
forms a pythagorean triple, because 
5<sup>2</sup> = 3<sup>2</sup> + 4<sup>2</sup>


### Return Values

* `1` if `a`, `b` and `c` form a pythagorean triple
* `0` if `a`, `b` and `c` do not form a pythagorean triple
* For Python: return `True` or `False`
'''
import math

def pythagorean_triple(integers):
    a, b, c = sorted(integers)
    return a * a + b * b == c * c


if __name__ == '__main__':
    print(pythagorean_triple([3, 4, 5]))
    print(pythagorean_triple([3, 5, 9]))
