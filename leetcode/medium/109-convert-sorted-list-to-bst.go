// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example:

// Given the sorted linked list: [-10,-3,0,5,9],

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

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}

	treeNode := &TreeNode{}
	// List contains only one node
	if head.Next == nil {
		treeNode.Val = head.Val
		return treeNode
	}
	// List contains two nodes
	if head.Next.Next == nil {
		if (head.Next).Val < head.Val {
			treeNode.Val, treeNode.Left = head.Val, &TreeNode{Val: (head.Next).Val}
		} else {
			treeNode.Val, treeNode.Left = (head.Next).Val, &TreeNode{Val: head.Val}
		}
		return treeNode
	}

	// Find the middle element of the list and fix Next pointer in his previous element
	listNodeMid := head
	for listNodeMidPrev, listNodeTail := listNodeMid, head.Next; ; listNodeMidPrev, listNodeMid, listNodeTail = listNodeMid, listNodeMid.Next, listNodeTail.Next.Next {
		if listNodeTail == nil {
			listNodeMidPrev.Next = nil
			break
		}
		if listNodeTail.Next == nil {
			listNodeMidPrev.Next = nil
			break
		}
	}

	// Initialize tree values
	fmt.Println("init\t", listNodeMid.Val)
	treeNode.Val = listNodeMid.Val
	treeNode.Left = sortedListToBST(head)
	treeNode.Right = sortedListToBST(listNodeMid.Next)

	return treeNode
}

func printTree(node *TreeNode) {
	if node != nil {
		printTree(node.Left)
		fmt.Println(node.Val)
		printTree(node.Right)
	}
}

func printList(node *ListNode) {
	if node != nil {
		fmt.Print(node.Val, " -> ")
		printList(node.Next)
	} else {
		fmt.Println()
	}
}

func createListFromArray(nums []int) *ListNode {
	if len(nums) == 0 {
		return nil
	}

	return &ListNode{Val: nums[0], Next: createListFromArray(nums[1:])}
}

func main() {
	// a := []int{-10, -3, 0, 5, 9, 10}
	a := []int{-10, -3, 0, 5, 9}
	l := createListFromArray(a)
	fmt.Println("Input list:")
	printList(l)
	result := sortedListToBST(l)
	fmt.Println("Result tree:")
	printTree(result)
}
