package linked_list

import "fmt"

// Single-linked list
type LinkedList struct {
	head *Node
}

type Node struct {
	value interface{}
	next  *Node
}

func NewList() *LinkedList {
	return &LinkedList{}
}

// Add element to a head of list
func (list *LinkedList) Add(value interface{}) {
	newNode := &Node{value: value, next: list.head}
	list.head = newNode
}

// Print values for all list elements
func (list *LinkedList) Print() {
	for node := list.head; node != nil; node = node.next {
		fmt.Println(node.value)
	}
}
