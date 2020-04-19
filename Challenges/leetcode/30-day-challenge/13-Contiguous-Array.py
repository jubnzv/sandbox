# Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
#
# Example 1:
#
# Input: [0,1]
# Output: 2
# Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
#
# Example 2:
#
# Input: [0,1,0]
# Output: 2
# Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
#
# Note: The length of the given binary array will not exceed 50,000.
from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        if not nums:
            return 0
        d = {0: -1}
        cnt = 0
        res = 0
        for i, num in enumerate(nums):
            if num == 0:
                cnt -= 1
            else:
                cnt += 1
            if cnt in d:
                res = max(res, i - d[cnt])
            d[cnt] = min(d.get(cnt, i), i)
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.findMaxLength([0, 1]))
