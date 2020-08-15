// Contains additional definitions/routines that are used by codefights platform

package codefights_util

import "fmt"

// Definition for singly-linked list
type ListNode struct {
	Value interface{}
	Next  *ListNode
}

// Initialize singly-linked list with array of values
func NewListFromArray(vals []int) *ListNode {
	head := &ListNode{}

	if len(vals) == 0 { // empty list
		return head
	}

	head.Value = vals[0]
	nodeNext := &ListNode{}
	for i, node := 1, head; i < len(vals); i, node = i+1, node.Next {
		nodeNext = &ListNode{Value: vals[i], Next: nil}
		node.Next = nodeNext
	}

	return head
}

// Print all list values
func PrintList(head *ListNode) {
	for n := head; n != nil; n = n.Next {
		fmt.Println(n.Value)
	}
}
