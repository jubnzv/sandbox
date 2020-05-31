# Given a 2D binary matrix filled with 0's and 1's, find the largest square
# containing only 1's and return its area.
#
# Example:
#
# Input:
#
# 1 0 1 0 0
# 1 0 1 1 1
# 1 1 1 1 1
# 1 0 0 1 0
#
# Output: 4
from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        max_square = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                max_square = max(max_square, int(matrix[i][j]))
                if i > 0 and j > 0:
                    square = min(
                        int(matrix[i-1][j]), int(matrix[i-1][j-1]), int(matrix[i][j-1]))
                    if square > 0 and matrix[i][j] == "1":
                        matrix[i][j] = str(square + 1)
                        max_square = max(max_square, int(matrix[i][j]))
        return max_square**2
