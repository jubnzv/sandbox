// https://codefights.com/interview-practice/task/pMvymcahZ8dY4g75q

//Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number for which the second occurrence has the minimal index. In other words, if there are more than 1 duplicated numbers, return the number for which the second occurrence has a smaller index than the second occurrence of the other number does. If there are no such elements, return -1.

package main

import "fmt"

func firstDuplicate(a []int) int {
	seen := make([]int, len(a))

	for _, v := range a {
		if seen[v-1] != 0 {
			return v
		}
		seen[v-1] = v
	}

	return -1
}

func main() {
	arr := []int{2, 3, 3, 1, 5, 2}

	fmt.Println("Input array:")
	fmt.Println(arr)
	fmt.Println("Duplicate value:")
	fmt.Println(firstDuplicate(arr))
}
