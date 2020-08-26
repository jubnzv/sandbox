// https://leetcode.com/problems/two-sum

// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.

// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  // Bruteforce implementation
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;

    for (unsigned i = 0; i < nums.size() - 1; i++) {
      for (unsigned j = i + 1; j < nums.size(); j++) {
        if ((nums.at(i) + nums.at(j)) == target) {
          result.push_back(i);
          result.push_back(j);
          break;
        }
      }
    }

    return result;
  }

  // Using 1-passed hash map
  vector<int> twoSum_map(vector<int> &nums, int target) {
    map<int, int> values;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums.at(i);
      if (values.find(complement) != values.end()) {
        result.push_back(values.at(complement));
        result.push_back(i);
        return result;
      }
      values.insert(pair<int, int>(nums.at(i), i));
    }
  }
};

int main(void) {
  // static const int nums_arr[] = {2, 7, 11, 15};
  // static const int target = 9;
  static const int nums_arr[] = {3, 2, 4};
  static const int target = 6;
  vector<int> nums(nums_arr, nums_arr + sizeof(nums_arr) / sizeof(nums_arr[0]));
  vector<int> result;

  Solution *s = new Solution();

  // Bruteforce
  // result = s->twoSum(nums, target);
  // for (std::vector<int>::const_iterator i = result.begin(); i !=
  // result.end(); ++i) cout << *i << ' ';

  // Hash table implementation
  result = s->twoSum_map(nums, target);
  for (std::vector<int>::const_iterator i = result.begin(); i != result.end();
       ++i)
    cout << *i << ' ';

  return 0;
}
