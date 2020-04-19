# Given an array nums of n integers where n > 1,  return an array output such
# that output[i] is equal to the product of all the elements of nums except
# nums[i].
#
# Example:
#
# Input:  [1,2,3,4]
# Output: [24,12,8,6]
#
# Constraint: It's guaranteed that the product of the elements of any prefix or
# suffix of the array (including the whole array) fits in a 32 bit integer.
#
# Note: Please solve it without division and in O(n).
#
# Follow up:
# Could you solve it with constant space complexity? (The output array does not
# count as extra space for the purpose of space complexity analysis.)
import operator
from functools import reduce
from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l = [1 for i in range(n)]
        r = [1 for i in range(n)]
        for i in range(1, n):
            j = n - 1 - i
            l[i] = l[i - 1] * nums[i - 1]
            r[j] = r[j + 1] * nums[j + 1]
        res = [1 for i in range(n)]
        for i in range(n):
            res[i] = l[i] * r[i]
        return res
