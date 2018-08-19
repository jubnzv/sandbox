'''
https://www.codewars.com/kata/odd-heavy-array

An array is defined to be `odd-heavy` if it contains at least one odd element and every element whose value is `odd` is greater than 
every even-valued element. 

eg.
```
Array [11,4,9,2,8] is odd-heavy 
because:- its odd elements [11,9] are greater than all the even elements [4,2,8]

Array [11,4,9,2,3,10] is not odd-heavy
because:- one of it's even element 10 from [4,2,10] is greater than two of its odd elements [9,3] from [ 11,9,3]

```
write a function called `isOddHeavy` or `is_odd_heavy` that accepts an integer array and returns `true` if the array is `odd-heavy` else return `false`.
'''
def is_odd_heavy_1(arr):
    print arr

    odds = {a for a in arr if a % 2 != 0}
    evens = {a for a in arr if a % 2 == 0}

    if len(evens) == 0 and len(odds) != 0:
        return True
    if len(evens) == 0 or len(odds) == 0:
        return False

    for i in odds:
        for j in evens:
            if i < j:
                return False

    return True

def is_odd_heavy(arr):
    max_even = max(filter(lambda n: n%2 == 0, arr), default=float("-inf"))
    min_odd  = min(filter(lambda n: n%2 == 1, arr), default=float("-inf"))
    return max_even < min_odd

if __name__ == '__main__':
    print(is_odd_heavy([0, 2, 19, 4, 4]))
    print(is_odd_heavy([1, -2, -1, 2]))
    print(is_odd_heavy([0, 0, 0, 0]))
    print(is_odd_heavy([-1, 1, -2, 2, -2, -2, -4, 4]))
    print(is_odd_heavy([0, -1, 1]))
    print(is_odd_heavy([0]))
    print(is_odd_heavy([1]))
    print(is_odd_heavy([]))
