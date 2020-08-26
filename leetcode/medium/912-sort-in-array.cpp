// https://leetcode.com/problems/sort-an-array/
//
// Given an array of integers nums, sort the array in ascending order.
//
// Example 1:
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
//
// Example 2:
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
//
// Constraints:
//  1 <= nums.length <= 50000
//  -50000 <= nums[i] <= 50000
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
  std::vector<int> sortArray(std::vector<int> &nums) {
    return sortArray_mergesort(nums);
  }

private:
  std::vector<int> sortArray_ShellSort(std::vector<int> &nums) {
    std::size_t Size = nums.size();
    std::size_t h = 1;

    // Use Knuth's algorithm
    while (h < Size / 3)
      h = h * 3 + 1;

    while (h >= 1) {
      for (auto i = h; i < Size; i++)
        for (auto j = i; j >= h && nums[j] < nums[j - h]; j -= h)
          std::swap(nums[j], nums[j - h]);
      h /= 3;
    }

    return nums;
  }

  std::vector<int> sortArray_insertionSort(std::vector<int> &nums) {
    std::size_t Size = nums.size();

    for (auto i = 0; i < Size; i++)
      for (auto j = i; j > 0; j--)
        if (nums[j] < nums[j - 1])
          std::swap(nums[j], nums[j - 1]);

    return nums;
  }

  std::vector<int> sortArray_selectionSort(std::vector<int> &nums) {
    std::size_t Size = nums.size();

    for (auto i = 0; i < Size; i++) {
      auto Min = i;
      for (auto j = i + 1; j < Size; j++)
        if (nums[j] < nums[Min])
          Min = j;
      std::swap(nums[i], nums[Min]);
    }

    return nums;
  }

  // Top-down mergesort adapted from Sedgewick
  // Time complexity: Nlog(N)
  std::vector<int> sortArray_mergesort(std::vector<int> &nums) {
    std::size_t Size = nums.size();
    std::vector<int> Aux(Size);
    sort(nums, Aux, 0, Size - 1);
    return nums;
  }
  void sort(std::vector<int> &Nums, std::vector<int> &Aux, int Low, int High) {
    if (High <= Low)
      return;
    auto Mid = Low + (High - Low) / 2;
    sort(Aux, Nums, Low, Mid);
    sort(Aux, Nums, Mid + 1, High);
    if (Nums[Mid + 1] > Nums[Mid])
      return;
    merge(Nums, Aux, Low, Mid, High); // Switch roles of Aux and Nums
  }
  void merge(std::vector<int> &Nums, std::vector<int> &Aux, int Low, int Mid,
             int High) {
    auto i = Low;
    auto j = Mid + 1;

    for (int k = Low; k <= High; k++) {
      if (i > Mid)
        Aux[k] = Nums[j++];
      else if (j > High)
        Aux[k] = Nums[i++];
      else if (Nums[j] < Nums[i])
        Aux[k] = Nums[j++];
      else
        Aux[k] = Nums[i++];
    }
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();
  std::vector<int> Seq = {5, 1, 1, 2, 0, 0};
  auto Result = S.sortArray(Seq);
  std::copy(Result.begin(), Result.end(),
            std::ostream_iterator<int>(std::cout, " "));

  return 0;
}
