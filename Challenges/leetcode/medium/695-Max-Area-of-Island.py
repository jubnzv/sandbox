# Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
# (representing land) connected 4-directionally (horizontal or vertical.) You
# may assume all four edges of the grid are surrounded by water.
#
# Find the maximum area of an island in the given 2D array. (If there is no
# island, the maximum area is 0.)
#
# Example 1:
#
# [[0,0,1,0,0,0,0,1,0,0,0,0,0],
#  [0,0,0,0,0,0,0,1,1,1,0,0,0],
#  [0,1,1,0,1,0,0,0,0,0,0,0,0],
#  [0,1,0,0,1,1,0,0,1,0,1,0,0],
#  [0,1,0,0,1,1,0,0,1,1,1,0,0],
#  [0,0,0,0,0,0,0,0,0,0,1,0,0],
#  [0,0,0,0,0,0,0,1,1,1,0,0,0],
#  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
#
# Given the above grid, return 6. Note the answer is not 11, because the island
# must be connected 4-directionally.
#
# Example 2:
#
# [[0,0,0,0,0,0,0,0]]
#
# Given the above grid, return 0.
#
# Note: The length of each dimension in the given grid does not exceed 50.
from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid or not len(grid[0]):
            return 0

        def search(i, j):
            if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
                return 0
            if grid[i][j] == 1:
                grid[i][j] = 0
                return 1 + (search(i+1, j) +
                            search(i, j+1) +
                            search(i-1, j) +
                            search(i, j-1))
            return 0

        max_acc = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    max_acc = max(search(i, j), max_acc)

        return max_acc


if __name__ == '__main__':
    s = Solution()
    res = s.maxAreaOfIsland([
        [1, 1, 0, 0, 0],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 1, 1],
        [0, 0, 0, 1, 1]])
    print(res)
    assert res == 4
    res = s.maxAreaOfIsland([
        [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]])
    print(res)
    assert res == 6
    res = s.maxAreaOfIsland([[0, 0, 0, 0, 0, 0, 0, 0]])
    print(res)
    assert res == 0
    res = s.maxAreaOfIsland([[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]])
    print(res)
    assert res == 4

