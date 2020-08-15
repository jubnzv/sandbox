// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example:

// Given the sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

package main

import "fmt"

// import "github.com/jubnzv/leetcode/util"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}

	node := &TreeNode{}
	if len(nums) == 1 {
		node.Val = nums[0]
		return node
	}

	midI := len(nums) / 2

	node.Val = nums[midI]
	node.Left = sortedArrayToBST(nums[:midI])
	node.Right = sortedArrayToBST(nums[midI+1:])

	return node
}

func printTree(node *TreeNode) {
	if node != nil {
		printTree(node.Left)
		fmt.Println(node.Val)
		printTree(node.Right)
	}
}

func main() {
	a := []int{-10, -3, 0, 5, 9}
	result := sortedArrayToBST(a)
	printTree(result)
}
