// https://codefights.com/interview-practice/task/RvDFbsNC3Xn7pnQfH
//You're given 2 huge integers represented by linked lists. Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits. The represented number might have leading zeros. Your task is to add up these huge integers and return the result in the same format.

package main

import "fmt"
import . "github.com/jubnzv/codefights/util"

func reverseList(l *ListNode) *ListNode {
	if l == nil { // empty list
		return nil
	}

	if l.Next == nil { // single-element list
		return l
	}

	np, nn := l, l.Next
	for nn != nil {
		tmp := nn.Next
		nn.Next = np
		np, nn = nn, tmp
	}
	l.Next = nil // fix tail

	return np
}

func addTwoHugeNumbers(a *ListNode, b *ListNode) *ListNode {
	if a == nil && b == nil { // empty lists
		return nil
	}

	if a == nil && b != nil { // a is empty
		return b
	}

	if a != nil && b == nil { // b is empty
		return a
	}

	// Reverse input lists
	ar, br := reverseList(a), reverseList(b)

	suml := &ListNode{} // Pointer to head of sum list
	ns := suml          // Pointer to current sum list element
	rem := 0            // Reminder to add at the next node
	tmpA, tmpB := 0, 0  // Values of current elements for input lists

	for na, nb := ar, br; ; ns = ns.Next {
		if na == nil {
			tmpA = 0
		} else {
			tmpA = na.Value.(int)
		}
		if nb == nil {
			tmpB = 0
		} else {
			tmpB = nb.Value.(int)
		}
		tmpSum := tmpA + tmpB
		if rem != 0 {
			tmpSum = tmpSum + rem
			rem = 0
		}
		if tmpSum > 9999 {
			rem = tmpSum / 10000
			tmpSum = tmpSum - (rem * 10000)
		}
		ns.Value = tmpSum

		// Do iteration
		if na != nil {
			if na.Next != nil {
				na = na.Next
			} else {
				na = nil
			}
		}
		if nb != nil {
			if nb.Next != nil {
				nb = nb.Next
			} else {
				nb = nil
			}
		}

		// Break condition
		if na == nil && nb == nil {
			break
		} else {
			ns.Next = &ListNode{Next: nil}
		}
	}

	//Fix the tail of list
	if rem != 0 {
		tail := &ListNode{Value: rem, Next: nil}
		ns.Next = tail
	}

	return reverseList(suml)
}

func main() {
	v := [][]int{
		{9876, 5432, 1999}, {1, 8001},
	}

	fmt.Println("--------------------------")
	l1 := NewListFromArray(v[0])
	fmt.Println("First huge number digits:")
	PrintList(l1)
	l2 := NewListFromArray(v[1])
	fmt.Println("Second huge number digits:")
	PrintList(l2)

	suml := addTwoHugeNumbers(l1, l2)

	fmt.Println("\nSum list:\t")
	PrintList(suml)
	fmt.Println("--------------------------\n")
}
