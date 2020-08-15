package main

import "fmt"
import . "github.com/jubnzv/leetcode/util"

func reverseList(head *ListNode) *ListNode {
	if head == nil { //empty list
		return nil
	}

	if head.Next == nil { // single element list
		return head
	}

	n := head.Next  // current element
	head.Next = nil // fix tail
	np := head      // previous element
	for n.Next != nil {
		nn := n.Next
		n.Next = np
		np = n
		n = nn
	}
	n.Next = np // fix head

	return n
}

func main() {
	arr := []int{3, 4, 5, 15, 28, 9, 5}
	l := NewListFromArray(arr)
	fmt.Println("Default list:")
	PrintList(l)
	lr := reverseList(l)
	fmt.Println("\nReversed list:")
	PrintList(lr)
}
