# https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/786/
#
# Given a binary tree, return the inorder traversal of its nodes' values.
#
# Example:
#
# Input: [1,null,2,3]
#    1
#     \
#      2
#     /
#    3
# Output: [1,3,2]
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
    def inorderTraversal_recursive(self, root: TreeNode) -> List[int]:
        def inorder_aux(root: TreeNode, acc: List[int]) -> TreeNode:
            if not root:
                return None
            inorder_aux(root.left, acc)
            acc.append(root.val)
            inorder_aux(root.right, acc)
        result: List[int] = []
        inorder_aux(root, result)
        return result

    def inorderTraversal_iterative(self, root: TreeNode) -> List[int]:
        s = []
        acc = []
        while s or root:
            if root:
                s.append(root)
                root = root.left
            else:
                root = s[-1]
                s.pop()
                if root:
                    acc.append(root.val)
                root = root.right
        return acc
