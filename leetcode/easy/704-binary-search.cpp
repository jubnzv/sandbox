// https://leetcode.com/problems/binary-search/
//
// Given a sorted (in ascending order) integer array nums of n elements and a
// target value, write a function to search target in nums. If target exists,
// then return its index, otherwise return -1.
//
// Example 1:
//
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
//
// Example 2:
//
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
//
// Note:
//  You may assume that all elements in nums are unique.
//  n will be in the range [1, 10000].
//  The value of each element in nums will be in the range [-9999, 9999].
#include <cassert>
#include <vector>
#include <iostream>

class Solution {
public:
  int search(std::vector<int> &Nums, int Target) {
    auto Size = Nums.size();

    if (Size == 1)
      return Nums[0] == Target ? 0 : -1;

    std::size_t Start = 0;
    std::size_t Mid = 0;
    std::size_t End = Size - 1;

    while (Start <= End) {
      Mid = (Start + End) / 2;
      if (Nums[Mid] == Target)
        return Mid;
      if (Nums[Mid] > Target)
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
    std::vector<int> Seq = {-1, 0, 3, 5, 9, 12};
    auto Result = S.search(Seq, 9);
    assert(Result == 4);
  }

  {
    std::vector<int> Seq = {-1, 0, 3, 5, 9, 12};
    auto Result = S.search(Seq, 2);
    assert(Result == -1);
  }

  {
    std::vector<int> Seq = {5};
    auto Result = S.search(Seq, -5);
    assert(Result == -1);
  }

  {
    std::vector<int> Seq = {2, 5};
    auto Result = S.search(Seq, 0);
    assert(Result == -1);
  }

  {
    std::vector<int> Seq = {2, 5};
    auto Result = S.search(Seq, 5);
    assert(Result == 1);
  }

  return 0;
}
