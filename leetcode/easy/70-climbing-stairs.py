# https://leetcode.com/problems/climbing-stairs/
#
# You are climbing a stair case. It takes n steps to reach to the top.
#
# Each time you can either climb 1 or 2 steps. In how many distinct ways can
# you climb to the top?
#
# Example 1:
#
# Input: 2
# Output: 2
# Explanation: There are two ways to climb to the top.
# 1. 1 step + 1 step
# 2. 2 steps
#
# Example 2:
#
# Input: 3
# Output: 3
# Explanation: There are three ways to climb to the top.
# 1. 1 step + 1 step + 1 step
# 2. 1 step + 2 steps
# 3. 2 steps + 1 step
#
# Constraints:
#     1 <= n <= 45
def memoize(f):
    memo = {}

    def helper(x, current=[]):
        if x not in memo:
            memo[x] = f(x, current=[])
        return memo[x]
    return helper


@memoize
def climb_stairs(n: int, current=[]) -> int:
    if n == 0:
        return 1
    num = climb_stairs(n-1, current + [1])
    if n >= 2:
        num += climb_stairs(n-2, current + [2])
    return num


class Solution:
    def climbStairs(self, n: int):
        return climb_stairs(n)
