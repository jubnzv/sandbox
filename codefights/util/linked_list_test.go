package codefights_util

import "testing"

func TestListAdd(t *testing.T) {
	arr := []int{2, 3, 4, 8, 19}
	l := NewListFromArray(arr)
	PrintList(l)
}
