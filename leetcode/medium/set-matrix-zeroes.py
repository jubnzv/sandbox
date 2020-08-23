# https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/
#
# Given an m x n matrix. If an element is 0, set its entire row and column to
# 0. Do it in-place.
#
# Follow up:
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best solution.
# Could you devise a constant space solution?
#
# Example 1:
# Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
# Output: [[1,0,1],[0,0,0],[1,0,1]]
#
# Example 2:
# Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
# Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
#
# Constraints:
#     m == matrix.length
#     n == matrix[0].length
#     1 <= m, n <= 200
#     -10^9 <= matrix[i][j] <= 10^9
#
from typing import List
import unittest


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        zero_flag_first_row = False
        zero_flag_first_col = False
        for i in range(len(matrix)):
            if matrix[i][0] == "M":
                continue
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0] = "M"
                    matrix[0][j] = "M"
                    if i == 0:
                        zero_flag_first_row = True
                    if j == 0:
                        zero_flag_first_col = True
        # Set zeroes in marked rows and columns
        for i in range(1, len(matrix)):
            if matrix[i][0] == "M":
                for j in range(1, len(matrix[0])):
                    # if i == 0 and j == 2: import pdb; pdb.set_trace()  # noqa
                    matrix[i][j] = 0
        for j in range(1, len(matrix[0])):
            if matrix[0][j] == "M":
                for i in range(1, len(matrix)):
                    matrix[i][j] = 0
        # Replace first line and column since we kept column marks
        for i in range(len(matrix)):
            if zero_flag_first_col or matrix[i][0] == "M":
                matrix[i][0] = 0
        for j in range(len(matrix[0])):
            if zero_flag_first_row or matrix[0][j] == "M":
                matrix[0][j] = 0


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_solution(self):
        m = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
        self.s.setZeroes(m)
        self.assertEqual(m, [[1, 0, 1], [0, 0, 0], [1, 0, 1]])

        m = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
        self.s.setZeroes(m)
        self.assertEqual(m, [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]])

        m = [[1, 2, 3, 4], [5, 0, 7, 8], [0, 10, 11, 12], [13, 14, 15, 0]]
        self.s.setZeroes(m)
        self.assertEqual(m, [[0, 0, 3, 0], [0, 0, 0, 0],
                             [0, 0, 0, 0], [0, 0, 0, 0]])

        m = [[0, 0, 0, 5], [4, 3, 1, 4], [
            0, 1, 1, 4], [1, 2, 1, 3], [0, 0, 1, 1]]
        self.s.setZeroes(m)
        self.assertEqual(m, [[0, 0, 0, 0], [0, 0, 0, 4], [
                         0, 0, 0, 0], [0, 0, 0, 3], [0, 0, 0, 0]])


if __name__ == '__main__':
    s = Solution()
    # m = [[1, 2, 3, 4], [5, 0, 7, 8], [0, 10, 11, 12], [13, 14, 15, 0]]
    m = [[0, 0, 0, 5], [4, 3, 1, 4], [
        0, 1, 1, 4], [1, 2, 1, 3], [0, 0, 1, 1]]
    s.setZeroes(m)
    print(m)
