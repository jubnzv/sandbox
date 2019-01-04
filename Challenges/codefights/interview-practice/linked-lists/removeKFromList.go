// https://codefights.com/interview-practice/task/gX7NXPBrYThXZuanm

// Definition for singly-linked list:
// type ListNode struct {
//   Value interface{}
//   Next *ListNode
// }

package main

func removeKFromList(l *ListNode, k int) *ListNode {
	if l == nil { // list is empty
		return nil
	}

	if l.Value == k { // head of list
		return removeKFromList(l.Next, k)
	}

	for np, n := l, l.Next; n != nil; {
		if n.Value == k {
			if n.Next == nil { // tail of list
				n = nil
				np.Next = n
				break
			}

			if n.Next.Value == k { // sequence of k-symbols
				n = n.Next
				continue
			} else { // single k
				np.Next = n.Next
				if n.Next != nil {
					n = n.Next
				}
			}
		}

		np, n = n, n.Next
	}

	return l
}
