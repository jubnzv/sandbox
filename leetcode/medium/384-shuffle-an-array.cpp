// https://leetcode.com/problems/shuffle-an-array/
//
// Shuffle a set of numbers without duplicates.
//
// Example:
//
// // Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);
//
// // Shuffle the array [1,2,3] and return its result. Any permutation of
// [1,2,3] must equally likely to be returned. solution.shuffle();
//
// // Resets the array back to its original configuration [1,2,3].
// solution.reset();
//
// // Returns the random shuffling of array [1,2,3].
// solution.shuffle();
#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
public:
  Solution(std::vector<int> &nums) : Size(nums.size()), DefaultNums(nums) {}

  /// Resets the array to its original configuration and return it.
  std::vector<int> reset() { return DefaultNums; }

  // Knuth's shuffle: O(n)
  std::vector<int> shuffle_Knuth() {
    // It will be faster to define this vector in class constructor, but
    // Leetcode will not accept this solution. From Hint #1:
    //
    // > The solution expects that we always use the original array to shuffle()
    // > else some of the test cases fail. (Credits; @snehasingh31)
    std::vector<int> Result(DefaultNums);

    for (std::size_t i = 1; i < Size; i++)
      std::swap(Result[std::rand() % (i + 1)], Result[i]);

    return Result;
  }

  // std::random_shuffle works too.
  // Complexity, according the docs:
  // > Linear in the distance between first and last
  // The implementation is the same as Knuth's algorithm:
  // https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/bits/stl_algo.h#L4551
  std::vector<int> shuffle_std() {
    std::vector<int> Result(DefaultNums);
    std::random_shuffle(Result.begin(), Result.end());
    return Result;
  }

private:
  std::size_t Size;
  std::vector<int> DefaultNums;
};

