# Return the root node of a binary search tree that matches the given preorder
# traversal.
#
# (Recall that a binary search tree is a binary tree where for every node, any
# descendant of node.left has a value < node.val, and any descendant of
# node.right has a value > node.val.  Also recall that a preorder traversal
# displays the value of the node first, then traverses node.left, then
# traverses node.right.)
#
# Example 1:
#
# Input: [8,5,1,7,10,12]
# Output: [8,5,10,1,7,null,12]
#
# Note:
#     1 <= preorder.length <= 100
#     The values of preorder are distinct.
#
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if not preorder:
            return []

        root = TreeNode(preorder[0])
        stack = [root]

        for num in preorder[1:]:
            if stack and stack[-1].val > num:
                stack[-1].left = TreeNode(num)
                stack.append(stack[-1].left)
            elif stack and stack[-1].val < num:
                while stack and stack[-1].val < num:
                    last = stack.pop()

                last.right = TreeNode(num)
                stack.append(last.right)

        return root
