# https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/788/
#
# Construct Binary Tree from Preorder and Inorder Traversal
#
# Given preorder and inorder traversal of a tree, construct the binary tree.
#
# Note:
# You may assume that duplicates do not exist in the tree.
#
# For example, given
#
# preorder = [3,9,20,15,7]
# inorder = [9,3,15,20,7]
#
# Return the following binary tree:
#
#     3
#    / \
#   9  20
#     /  \
#    15   7
#
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if preorder:
            root = TreeNode(preorder[0])
            len_left = inorder.index(preorder[0])
            root.left = self.buildTree(
                preorder[1:len_left+1], inorder[:len_left])
            root.right = self.buildTree(
                preorder[len_left+1:], inorder[len_left+1:])
            return root
        else:
            return None
