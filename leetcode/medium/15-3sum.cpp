// https://leetcode.com/problems/3sum/
//
// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the sum
// of zero.
//
// Note:
// The solution set must not contain duplicate triplets.
//
// Example:
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> Result;
    std::size_t Length = nums.size();

    std::sort(nums.begin(), nums.end());

    for (std::size_t i = 0; i < Length; i++) {
      // Handle duplicates
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      std::int64_t Left = i + 1;
      std::int64_t Right = Length - 1;
      while (Left < Right) {
        std::int64_t Sum = nums[i] + nums[Left] + nums[Right];
        if (Sum == 0) {
          Result.push_back({nums[i], nums[Left], nums[Right]});
          // Handle duplicates
          while (Left < Right && nums[Left] == nums[Left + 1])
            Left += 1;
          while (Left < Right && nums[Right] == nums[Right - 1])
            Right -= 1;
          Right -= 1;
          Left += 1;
        } else if (Sum < 0) {
          Left += 1;
        } else /* Sum > 0 */ {
          Right -= 1;
        }
      }
    }

    return Result;
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();
  std::vector<int> Values = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> Result = S.threeSum(Values);
  for (const auto &Row : Result) {
    std::cout << "[ ";
    std::copy(Row.begin(), Row.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]\n";
  }
  return 0;
}
