# https://leetcode.com/problems/regions-cut-by-slashes/
#
# In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /,
# \, or blank space.  These characters divide the square into contiguous
# regions.
# (Note that backslash characters are escaped, so a \ is represented as "\\".)
#
# Return the number of regions.
#
# Example 1:
# Input:
# [
#   " /",
#   "/ "
# ]
# Output: 2
#
# Example 2:
# Input:
# [
#   " /",
#   "  "
# ]
# Output: 1
#
# Example 3:
# Input:
# [
#   "\\/",
#   "/\\"
# ]
# Output: 4
#
# Example 4:
# Input:
# [
#   "/\\",
#   "\\/"
# ]
# Output: 5
# Explanation: (Recall that because \ characters are escaped, "/\\" refers to
# /\, and "\\/" refers to \/.)
#
# Example 5:
# Input:
# [
#   "//",
#   "/ "
# ]
# Output: 3
#
# Note:
#     1 <= grid.length == grid[0].length <= 30
#     grid[i][j] is either '/', '\', or ' '.
import unittest
from typing import List


# Based on Sedgewick's UF from chapter 1
class WeightedQuickUnionUF:

    def __init__(self, N):
        self.count = N
        self.ids = list(range(N))
        self.szs = [1]*N

    def count(self):
        return self.count

    def connected(self, p, q):
        return self.find(p) == self.find(q)

    def find(self, p):
        while (p != self.ids[p]):
            p = self.ids[p]
        return p

    def union(self, p, q):
        i = self.find(p)
        j = self.find(q)
        if i == j:
            return

        # Make smaller root point to larger one
        if self.szs[i] < self.szs[j]:
            self.ids[i] = j
            self.szs[j] += self.szs[i]
        else:
            self.ids[j] = i
            self.szs[i] += self.szs[j]

        self.count -= 1


class Solution:

    # Based on weighted quick union algorithm
    def regionsBySlashes(self, grid: List[str]) -> int:
        assert(len(grid[0]) == len(grid))
        N = len(grid)

        # Each cell contains 4 triangles
        uf = WeightedQuickUnionUF(N*N*4)

        for i, line in enumerate(grid):
            for j, cell in enumerate(line):
                v = 4 * (i * N + j)

                if cell in '\\ ':
                    uf.union(v, v+3)
                    uf.union(v+1, v+2)
                if cell in '/ ':
                    uf.union(v, v+1)
                    uf.union(v+2, v+3)

                # Connect with neighbour cells
                if i > 0:
                    uf.union(v, v - 4 * N + 2)
                if j > 0:
                    uf.union(v + 1, v - 4 + 3)
                if i < N - 1:
                    uf.union(v + 2, v + 4 * N)
                if j < N - 1:
                    uf.union(v + 3, v + 4 + 1)

        return uf.count


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_solution(self):
        self.assertEqual(self.s.regionsBySlashes(["//", "/ "]), 3)
