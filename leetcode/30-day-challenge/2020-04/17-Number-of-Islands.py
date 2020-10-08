# Number of Islands
#
# Given a 2d grid map of '1's (land) and '0's (water), count the number of
# islands. An island is surrounded by water and is formed by connecting
# adjacent lands horizontally or vertically. You may assume all four edges of
# the grid are all surrounded by water.
#
# Example 1:
#
# Input:
# 11110
# 11010
# 11000
# 00000
#
# Output: 1
#
# Example 2:
#
# Input:
# 11000
# 11000
# 00100
# 00011
#
# Output: 3


class Solution:
    def search(self, i, j, grid, passed):
        passed[i][j] = False
        if i+1 < len(grid) and grid[i+1][j] == '1' and passed[i+1][j]:
            self.search(i+1, j, grid, passed)
        if j+1 < len(grid[0]) and grid[i][j+1] == '1' and passed[i][j+1]:
            self.search(i, j+1, grid, passed)
        if i-1 >= 0 and grid[i-1][j] == '1' and passed[i-1][j]:
            self.search(i-1, j, grid, passed)
        if j-1 >= 0 and grid[i][j-1] == '1' and passed[i][j-1]:
            self.search(i, j-1, grid, passed)

    def numIslands(self, grid):
        row = len(grid)
        if row == 0:
            return 0
        col = len(grid[0])

        passed = [[True for x in range(col)] for x in range(row)]
        res = 0
        for i in range(0, row):
            for j in range(0, col):
                if grid[i][j] == '1' and passed[i][j]:
                    self.search(i, j, grid, passed)
                    res += 1
        return res
