# Given an array of distinct integers candidates and a target integer target,
# return a list of all unique combinations of candidates where the chosen
# numbers sum to target. You may return the combinations in any order.
#
# The same number may be chosen from candidates an unlimited number of times.
# Two combinations are unique if the frequency of at least one of the chosen
# numbers is different.
#
# Example 1:
# Input: candidates = [2,3,6,7], target = 7
# Output: [[2,2,3],[7]]
# Explanation:
# 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
# times.
# 7 is a candidate, and 7 = 7.
# These are the only two combinations.
#
# Example 2:
# Input: candidates = [2,3,5], target = 8
# Output: [[2,2,2,2],[2,3,3],[3,5]]
#
# Example 3:
# Input: candidates = [2], target = 1
# Output: []
#
# Example 4:
# Input: candidates = [1], target = 1
# Output: [[1]]
#
# Example 5:
# Input: candidates = [1], target = 2
# Output: [[1,1]]
#
# Constraints:
#  1 <= candidates.length <= 30
#  1 <= candidates[i] <= 200
#  All elements of candidates are distinct.
#  1 <= target <= 500
import copy
from typing import List


class Solution:
    def combinationSum(self,
                       candidates: List[int],
                       target: int
                       ) -> List[List[int]]:
        candidates.sort()
        result = []
        self.findCombinations(candidates, target, result)
        return result

    def findCombinations(self, candidates: List[int],
                         target: int,
                         result: List[List[int]],
                         current: List[int] = [],
                         index: int = 0) -> None:
        if target == 0:
            result.append(copy.copy(current))
            return

        i = index
        while i < len(candidates):
            if candidates[i] > target:
                break
            current.append(candidates[i])
            r = self.findCombinations(
                candidates, target - candidates[i], result, current, i)
            current.pop()
            i += 1


if __name__ == '__main__':
    s = Solution()
    r = s.combinationSum([2, 3, 5, 7], 7)
    print('s.combinationSum([2, 3, 5, 7], 7) == [[2, 2, 3], [7]]: ', r)
