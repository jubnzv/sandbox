package main

import (
	"fmt"
	"github.com/jubnzv/AlgorithmDesign"
)

func InsertionSort(arr []int) {
	if len(arr) <= 1 {
		return
	}

	var i, j int
	for i = 1; i < len(arr); i++ {
		for j = i; j > 0 && arr[j] < arr[j-1]; j-- {
			arr[j], arr[j-1] = arr[j-1], arr[j]
		}
	}
}

func main() {
	arr := utils.RandArray(10)
	fmt.Println("Initial array:\t", arr)
	InsertionSort(arr)
	fmt.Println("Sorted array:\t", arr)
}
