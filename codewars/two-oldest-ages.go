//https://www.codewars.com/kata/two-oldest-ages-1/train/go

package kata

func TwoOldestAges(ages []int) [2]int {
	var oldest2, oldest1 int = 0, 0

	for _, age := range ages {
		if age >= oldest1 {
			oldest2 = oldest1
			oldest1 = age
		} else if age >= oldest2 && age <= oldest1 {
			oldest2 = age
		}
	}

	return [2]int{oldest2, oldest1}
}
