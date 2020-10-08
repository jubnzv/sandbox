#    Move Zeroes
#
#  Given an array nums, write a function to move all 0's to the end of it while
#  maintaining the relative order of the non-zero elements.
#
#  Example:
#
#  Input: [0,1,0,3,12]
#  Output: [1,3,12,0,0]
#
#  Note:
#
#      You must do this in-place without making a copy of the array.
#      Minimize the total number of operations.
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pos = 0

        for i in range(len(nums)):
            if nums[i] != 0:
                nums[pos] = nums[i]
                pos += 1

        while pos < len(nums):
            nums[pos] = 0
            pos += 1


if __name__ == '__main__':
    s = Solution()
    l = [0, 1, 0, 3, 12]
    print(l)
    s.moveZeroes(l)
    print(l)
