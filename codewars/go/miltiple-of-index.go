// https://www.codewars.com/kata/multiple-of-index

package kata

func multipleOfIndex(ints []int) []int {
	var result []int

	for i := range ints {
		if i != 0 && ints[i]%i == 0 {
			result = append(result, ints[i])
		}
	}

	return result
}
