# https://leetcode.com/problems/binary-tree-preorder-traversal/
#
# Given a binary tree, return the preorder traversal of its nodes' values.
#
# Example:
#
# Input: [1,null,2,3]
#    1
#     \
#      2
#     /
#    3
#
# Output: [1,2,3]
#
# Follow up: Recursive solution is trivial, could you do it iteratively?
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal_recursive(self, root: TreeNode) -> List[int]:
        def preorderTraversal_aux(acc, node):
            if not node:
                return
            acc.append(node.val)
            preorderTraversal_aux(acc, node.left)
            preorderTraversal_aux(acc, node.right)
        acc = []
        preorderTraversal_aux(acc, root)
        return acc

    def preorderTraversal(self, root):
        acc = []
        s = [root]
        while s:
            root = s[-1]
            s.pop()
            if not root:
                continue
            acc.append(root.val)
            if root.right:
                s.append(root.right)
            if root.left:
                s.append(root.left)
        return acc
