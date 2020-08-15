#!/usr/bin/python3

# https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

# Given a binary tree, find its maximum depth.

# The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

# For example:
# Given binary tree [3,9,20,null,null,15,7],

#     3
#    / \
#   9  20
#     /  \
#    15   7
# return its depth = 3.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxDepth(self, root, depth=0):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        depth += 1
        depth_l = self.maxDepth(root.left, depth)
        depth_r = self.maxDepth(root.right, depth)
        return max([depth, depth_l, depth_r])
