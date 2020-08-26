# https://leetcode.com/problems/shuffle-an-array/
#
# Shuffle a set of numbers without duplicates.
#
# Example:
#
# // Init an array with set 1, 2, and 3.
# int[] nums = {1,2,3};
# Solution solution = new Solution(nums);
#
# // Shuffle the array [1,2,3] and return its result. Any permutation of
# [1,2,3] must equally likely to be returned.
#
# solution.shuffle();
#
# // Resets the array back to its original configuration [1,2,3].
# solution.reset();
#
# // Returns the random shuffling of array [1,2,3].
# solution.shuffle();
from typing import List
import random
import copy


class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.shuffled = copy.copy(nums)

    def reset(self) -> List[int]:
        """Resets the array to its original configuration and return it."""
        return self.nums

    def shuffle(self) -> List[int]:
        """Returns a random shuffling of the array."""
        for i in range(1, len(self.shuffled)):
            idx = random.randint(0, i)
            self.shuffled[idx], self.shuffled[i] = self.shuffled[i], self.shuffled[idx]
        return self.shuffled


if __name__ == '__main__':
    s = Solution([1, 2, 3])
    print(s.shuffle())
    s.reset()
    print(s.shuffle())
