# https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/787/
#
# Binary Tree Zigzag Level Order Traversal
#
# Given a binary tree, return the zigzag level order traversal of its nodes'
# values. (ie, from left to right, then right to left for the next level and
#         alternate between).
#
# For example:
# Given binary tree [3,9,20,null,null,15,7],
#
#     3
#    / \
#   9  20
#     /  \
#    15   7
#
# return its zigzag level order traversal as:
#
# [
#   [3],
#   [20,9],
#   [15,7]
# ]
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        result = []
        result_nested = []
        current_stack = []
        next_stack = []

        current_stack.append(root)
        left_to_right = True

        while current_stack:
            node = current_stack[-1]
            current_stack.pop()

            result_nested.append(node.val)

            # Store data according to current order
            if left_to_right:
                if node.left:
                    next_stack.append(node.left)
                if node.right:
                    next_stack.append(node.right)
            else:
                if node.right:
                    next_stack.append(node.right)
                if node.left:
                    next_stack.append(node.left)

            if not current_stack:
                left_to_right = not left_to_right
                current_stack = next_stack
                next_stack = []
                result.append(result_nested)
                result_nested = []

        return result
