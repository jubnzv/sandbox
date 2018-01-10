package linked_list

import "testing"

func TestListAdd(t *testing.T) {
	list := NewList()
	list.Add(19)
	list.Add(20)
}
