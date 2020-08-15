package main

import "fmt"
import . "github.com/jubnzv/leetcode/util"

func debugPrint(mid, end, np, nn *ListNode) {
	fmt.Println("mid: ", mid, "\tend: ", end)
	fmt.Println("  mid prev: ", np, "\tmid next: ", nn, "\n")
}

func isPalindrome(head *ListNode) bool {
	if head == nil { //empty list
		return true
	}

	if head.Next == nil { // single element list
		return true
	}

	// Moving to middle and end of list with two pointers and revert head-middle list simultaneously
	mid, end := head.Next, (head.Next).Next
	np := head      // element before the middle
	nn := mid.Next  // element next to the middle
	head.Next = nil // fix tail of reversed list
	if nn == nil {  // Two-elements list: bailing out
		if np.Val == mid.Val {
			return true
		} else {
			return false
		}
	}
	for end != nil && end.Next != nil {
		if (end.Next).Next == nil {
			end = end.Next
			break
		}
		mid.Next = np
		np = mid
		mid, end = nn, (end.Next).Next
		nn = mid.Next
	}
	debugPrint(mid, end, np, nn)

	// Maybe even-size length list palindrome?
	if mid.Val == nn.Val && np.Val != nn.Val {
		tmp := mid
		mid.Next = np
		np = tmp
		fmt.Println("Even check")
		debugPrint(mid, end, np, nn)
	}

	// Iterate mid-head (via new reversed list) and mid-tail
	for ; nn != nil && np != nil; np, nn = np.Next, nn.Next {
		fmt.Println(np.Val, nn.Val)
		if np.Val != nn.Val {
			return false
		}

		// Need in even-sized lists: if number of elements for mid-tail and
		// mid-head lists is not equals, there is odd-length list that is not
		// palindrome.
		if (np.Next == nil && nn.Next != nil) || (np.Next != nil && nn.Next == nil) {
			return false
		}
	}

	return true
}

func main() {
	values := [][]int{
		//{1, 2},
		//{1, 1, 2, 1},
		//{1, 2, 2, 1},
		{1, 2, 2, 2, 1},
		//{1, 0, 0},
		//{1, 0, 1},
		//{3, 4, 5, 15, 28, 9, 5},
		//{3, 4, 5, 6, 5, 2, 1},
		//{3, 4, 5, 6, 5, 4, 3},
		//{3, 4, 5, 6, 6, 5, 2, 1},
		//{3, 4, 5, 6, 6, 5, 4, 3},
		//{2, 3, 2},
		//{1, 1, 1},
		//{},
		//{0},
		//{1, 2, 2, 1},
	}

	for _, v := range values {
		fmt.Println("--------------------------")
		l := NewListFromArray(v)
		fmt.Println("List:")
		PrintList(l)
		result := isPalindrome(l)
		fmt.Println("\nList is palindrome:\t", result)
		fmt.Println("--------------------------\n")
	}
}
