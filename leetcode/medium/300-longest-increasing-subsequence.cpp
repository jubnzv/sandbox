// https://leetcode.com/problems/longest-increasing-subsequence/
#include <algorithm>
#include <vector>
using namespace std;

// [4,10,4,3,8,9]
// [10,9,2,5,3,7,101,18]
// [10,9,2,5,3,7,101,18]
// [10,9,2,5,3,7,18,101]

class Solution {
public:
  // DP, O(n^2)
  int lengthOfLIS_dp(vector<int> &nums) {
    auto sz = nums.size();
    if (sz < 2)
      return sz;
    vector<int> dp(sz, 1);
    for (int i = 1; i < sz; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          dp[i] = max(dp[j] + 1, dp[i]);
    return *max_element(dp.begin(), dp.end());
  }
};
