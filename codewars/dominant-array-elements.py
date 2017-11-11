# https://www.codewars.com/kata/dominant-array-elements/train/python
#
# An element in an array is dominant if it is greater than all elements to its right.
# For example, in the array [1,21,4,7,5], we see that 21,7,5 are dominant. Therefore, solve([1,21,4,7,5]) = [21,7,5], which is the order in which they appear.
def solve(arr):
    if not arr:
        return []

    dom = max(arr)
    dom_pos = len(arr) - 1 - arr[::-1].index(max(arr))

    if len(arr) == 1:
        return arr
    else:
        return [arr[dom_pos]] + solve(arr[dom_pos+1:])


if __name__ == '__main__':
    print(solve([1, 21, 22, 19, 3, 21, 5]))
    # print solve([17, 14, 14, 5, 2])
