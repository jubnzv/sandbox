# Given an array of integers and an integer k, you need to find the total number
# of continuous subarrays whose sum equals to k.
#
# Example 1:
# Input:nums = [1,1,1], k = 2
# Output: 2
#
# Note:
#     The length of the array is in range [1, 20,000].
#     The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
from typing import List
from collections import defaultdict


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return (0, 1)[nums[0] == k]

        res = 0
        currsum = 0
        prevsums = defaultdict(lambda: 0)

        for i in range(len(nums)):
            currsum += nums[i]
            if currsum == k:
                res += 1
            if (currsum - k) in prevsums:
                res += prevsums[currsum - k]
            prevsums[currsum] += 1

        return res
