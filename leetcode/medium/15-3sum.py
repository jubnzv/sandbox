# https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
#
# Given an array nums of n integers, are there elements a, b, c in nums such
# that a + b + c = 0? Find all unique triplets in the array which gives the sum
# of zero.
#
# Note:
#
# The solution set must not contain duplicate triplets.
#
# Example:
#
# Given array nums = [-1, 0, 1, 2, -1, -4],
#
# A solution set is:
# [
#   [-1, 0, 1],
#   [-1, -1, 2]
# ]
import unittest
from typing import List, Set, Tuple


class Solution:
    # Updated after reading: https://stackoverflow.com/a/46432030/8541499
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        result = set()
        nums.sort()
        n = len(nums)
        for i, num in enumerate(nums):
            if i > n - 3:
                break
            left, right = i+1, n-1
            while left < right:
                s = num + nums[left] + nums[right]  # check if current sum is 0
                if s == 0:
                    # add to the solution set only if this triplet is unique
                    result.add(tuple([num, nums[left], nums[right]]))
                    right -= 1
                    left += 1
                elif s > 0:
                    right -= 1
                else:
                    left += 1
            i += 1
        return list(result)


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test1(self):
        self.assertEqual(self.s.threeSum(
            [-1, 0, 1, 2, -1, -4]), [(-1, 0, 1), (-1, -1, 2)])
