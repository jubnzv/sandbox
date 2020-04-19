# Given a m x n grid filled with non-negative numbers, find a path from top
# left to bottom right which minimizes the sum of all numbers along its path.
#
# Note: You can only move either down or right at any point in time.
#
# Example:
#
# Input:
# [
#   [1,3,1],
#   [1,5,1],
#   [4,2,1]
# ]
# Output: 7
# Explanation: Because the path 1→3→1→1→1 minimizes the sum.
#
from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0

        rows = len(grid)
        cols = len(grid[0])

        for i in range(1, cols):
            grid[0][i] = grid[0][i] + grid[0][i - 1]
        for i in range(1, rows):
            grid[i][0] = grid[i][0] + grid[i - 1][0]

        for i in range(1, rows):
            for j in range(1, cols):
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j]

        return grid[rows - 1][cols - 1]
