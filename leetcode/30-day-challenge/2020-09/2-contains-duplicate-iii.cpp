// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3446/
//
// Given an array of integers, find out whether there are two distinct indices i
// and j in the array such that the absolute difference between nums[i] and
// nums[j] is at most t and the absolute difference between i and j is at most
// k.
//
// Example 1:
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
//
// Example 2:
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
//
// Example 3:
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false
#include <set>
#include <vector>

class Solution {
public:
  bool containsNearbyAlmostDuplicate(std::vector<int> &Nums, int k, int t) {
    std::multiset<int> Set;
    int n = Nums.size();
    for (int i = 0; i < n; i++) {
      std::multiset<int>::iterator It = Set.lower_bound(Nums[i]);
      if (It != Set.end() && *It <= Nums[i] + t)
        return true;
      if (It != Set.begin()) {
        It = std::next(It, -1);
        if (*It + t >= Nums[i])
          return true;
      }
      Set.insert(Nums[i]);
      if (i >= k)
        Set.erase(Nums[i - k]);
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();
  std::vector<int> V = {1, 2, 3, 1};
  std::cout << (S.containsNearbyAlmostDuplicate(V, 3, 0)) << std::endl;
  return 0;
}
