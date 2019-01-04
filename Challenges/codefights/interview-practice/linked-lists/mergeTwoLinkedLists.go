// https://codefights.com/interview-practice/task/6rE3maCQwrZS3Mm2H
// Given two singly linked lists sorted in non-decreasing order, your task is to merge them. In other words, return a singly linked list, also sorted in non-decreasing order, that contains the elements from both original lists.

package main

import "fmt"
import . "github.com/jubnzv/codefights/util"

func mergeTwoLinkedLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil { // first list is empty
		return l2
	}

	if l2 == nil { // second list is empty
		return l1
	}

	lmn := &ListNode{}         // Pointer to next element of result list
	lm := &ListNode{Next: lmn} // Pointer to current element of result list
	result := lm.Next          // Save position to head for return value
	n1, n2 := l1, l2           // Pointers to current elements of input lists

	for ; ; lm, lmn = lmn, lmn.Next {
		//fmt.Println("n1 (", &n1, "):", n1, "n2 (", &n2, "): ", n2, "\tlm: ", lm, "lmn: ", lmn)

		if n1 == nil { // First list end
			lm.Next = n2
			break
		}

		if n2 == nil { // Second list end
			lm.Next = n1
			break
		}

		// Empty node to next iteration
		emptyNode := &ListNode{}
		lmn.Next = emptyNode

		// Insert right value
		if n1.Value.(int) < n2.Value.(int) {
			lmn.Value = n1.Value
			n1 = n1.Next
		} else {
			lmn.Value = n2.Value
			n2 = n2.Next
		}
	}

	return result
}

func main() {
	v := [][]int{
		{1, 19, 23, 27}, {4, 42, 43},
	}

	fmt.Println("--------------------------")
	l1 := NewListFromArray(v[0])
	fmt.Println("First list:")
	PrintList(l1)
	l2 := NewListFromArray(v[1])
	fmt.Println("Second list:")
	PrintList(l2)

	result := mergeTwoLinkedLists(l1, l2)

	fmt.Println("\nResult of merge:\t")
	PrintList(result)
	fmt.Println("--------------------------\n")
}
