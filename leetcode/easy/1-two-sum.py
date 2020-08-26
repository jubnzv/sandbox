# https://leetcode.com/problems/two-sum/
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
#
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
#
# Example:
# Given nums = [2, 7, 11, 15], target = 9,
#
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
import unittest
from typing import List, Dict


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m: Dict[int, int] = {}
        assert(len(nums) >= 2)
        for i in range(len(nums)):
            num = nums[i]
            pair = target - num
            if pair in m:
                return [m[pair], i]
            m[num] = i
        return []


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test1(self):
        self.assertEqual(self.s.twoSum([2, 7, 11, 15], 9), [0, 1])
        self.assertEqual(self.s.twoSum([-1, 0, 1, 2, -1, -4], -5), [4, 5])
