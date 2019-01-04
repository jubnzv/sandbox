package binary_tree

type TreeNode struct {
	Value  interface{}
	Parent *TreeNode
	Left   *TreeNode
	Right  *TreeNode
}

func SearchTree(tree *TreeNode, val interface{}) *TreeNode {
	if tree == nil {
		return nil
	}

	if tree.Value == val {
		return tree
	}

	if tree.Value > val {
		return SearchTree(tree.Left, val)
	} else {
		return SearchTree(tree.Right, val)
	}
}

func FindMin(tree *TreeNode) *TreeNode {
	if tree == nil {
		return nil
	}

	min = tree
	for min != nil {
		min = tree.Left
	}
	return min
}

func FindMax(tree *TreeNode) *TreeNode {
	if tree == nil {
		return nil
	}

	max = tree
	for max != nil {
		max = tree.Right
	}
	return max
}

// TODO: Describe whole tree as separate type
func InsertTree(tree *TreeNode, val interface{}) *TreeNode {
	new_node = &TreeNode{}

	if tree == nil {
		new_node.Parent = nil
		new_node.Value = val
	}
}
