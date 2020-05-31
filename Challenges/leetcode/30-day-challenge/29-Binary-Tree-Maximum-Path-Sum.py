# Given a non-empty binary tree, find the maximum path sum.
#
# For this problem, a path is defined as any sequence of nodes from some
# starting node to any node in the tree along the parent-child connections. The
# path must contain at least one node and does not need to go through the root.
#
# Example 1:
#
# Input: [1,2,3]
#
#        1
#       / \
#      2   3
#
# Output: 6
#
# Example 2:
#
# Input: [-10,9,20,null,null,15,7]
#
#    -10
#    / \
#   9  20
#     /  \
#    15   7
#
# Output: 42

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def aux(node):
            if not node.left and not node.right:
                self.max_sum = max(self.max_sum, node.val)
                return node.val
            leftsum = 0
            rightsum = 0
            if node.left:
                leftsum = aux(node.left)
            if node.right:
                rightsum = aux(node.right)
            self.max_sum = max(
                self.max_sum, node.val+max(0, leftsum)+max(0, rightsum))
            return node.val+max(0, leftsum, rightsum)

        self.max_sum = root.val
        aux(root)
        return self.max_sum
