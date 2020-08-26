// https://leetcode.com/problems/search-in-rotated-sorted-array
//
// Given an integer array nums sorted in ascending order, and an integer target.
//
// Suppose that nums is rotated at some pivot unknown to you beforehand (i.e.,
// [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You should search for target in nums and if you found return its index,
// otherwise return -1.
//
// Example 1:
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
// Example 2:
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//
// Example 3:
//
// Input: nums = [1], target = 0
// Output: -1
//
// Constraints:
//  1 <= nums.length <= 5000
//  -10^4 <= nums[i] <= 10^4
//  All values of nums are unique.
//  nums is guranteed to be rotated at some pivot.
//  -10^4 <= target <= 10^4
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
  int search(std::vector<int> &Nums, int Target) {
    std::size_t Size = Nums.size();

    if (Size == 1)
      return (Target == Nums[0]) ? 0 : -1;

    // Note: This compiles to illegal hardware instruction for AMD64 with LLVM
    // 12 (nightly).
    std::size_t Shift = 0;
    while (!((Nums[0] < Nums[1]) && (Nums[1] <= Nums[Size - 1]))) {
      std::rotate(Nums.begin(), Nums.begin() + 1, Nums.end());
      Shift++;
    }

    // Binary search
    // Time complexity: O(logN)
    std::size_t Start = 0;
    std::size_t End = Size - 1;
    std::size_t Mid = 0;
    while (Start <= End) {
      Mid = (Start + End) / 2;
      if (Nums[Mid] == Target) {
        auto Result = Mid + Shift;
        return (Result < Size) ? Result : Size - Result;
      } else if (Nums[Mid] > Target)
        End = Mid - 1;
      else
        Start = Mid + 1;
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();

  {
    std::vector<int> Seq = {4, 5, 6, 7, 0, 1, 2};
    auto Result = S.search(Seq, 0);
    assert(Result == 4);
  }

  {
    std::vector<int> Seq = {4, 5, 6, 7, 0, 1, 2};
    auto Result = S.search(Seq, 0x42);
    assert(Result == -1);
  }

  {
    std::vector<int> Seq = {0, 3};
    auto Result = S.search(Seq, 0);
    assert(Result == 0);
  }

  return 0;
}
