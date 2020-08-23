# https://www.codewars.com/kata/567b4463933017fb1500004b
#
# Given an m x n matrix of 0s and 1s, if an element is 0 set its entire row and
# column to 0s. Do it in-place.
#
# Given array A =
# 1 0 1
# 1 1 1
# 1 1 1
# # setZeroes should return
# 0 0 0
# 1 0 1
# 1 0 1
#
# Same as my leetcode solution for:
# https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/


def setZeroes(matrix):
    """
    Given an m x n matrix of 0s and 1s, if an element is 0
    set its entire row and column to 0s. Do it in-place.
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
    return matrix
