/* https://leetcode.com/problems/same-tree/description/

Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Definition for a binary tree node:
type TreeNode struct {
	Val int
    Left *TreeNode
    Right *TreeNode
} */

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if (p == nil && q != nil) ||
		(p != nil && q == nil) {
		return false
	}

	if p != nil && q != nil {
		if isSameTree(p.Left, q.Left) == false {
			return false
		}
		if p.Val != q.Val {
			return false
		}
		if isSameTree(p.Right, q.Right) == false {
			return false
		}
	}

	return true
}
