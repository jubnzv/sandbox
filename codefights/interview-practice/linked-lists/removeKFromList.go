// https://codefights.com/interview-practice/task/gX7NXPBrYThXZuanm

package main

func removeKFromList(l *ListNode, k int) *ListNode {
	if l == nil { // list is empty
		return nil
	}

	if l.Value == k { // head of list
		return removeKFromList(l.Next, k)
	}

	for np, n := l, l.Next; n != nil; np, n = n, n.Next {
		if n.Value == k {
			np.Next = n.Next
			if n.Next != nil {
				n = n.Next
			}
		}
	}

	return l
}
