// https://leetcode.com/problems/remove-covered-intervals/
//
// Given a list of intervals, remove all intervals that are covered by another
// interval in the list.
//
// Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.
//
// After doing so, return the number of remaining intervals.
//
// Example 1:
//
// Input: intervals = [[1,4],[3,6],[2,8]]
// Output: 2
// Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
//
// Example 2:
//
// Input: intervals = [[1,4],[2,3]]
// Output: 1
//
// Example 3:
//
// Input: intervals = [[0,10],[5,12]]
// Output: 2
//
// Example 4:
//
// Input: intervals = [[3,10],[4,10],[5,11]]
// Output: 2
//
// Example 5:
//
// Input: intervals = [[1,2],[1,4],[3,4]]
// Output: 1
//
// Constraints:
//  1 <= intervals.length <= 1000
//  intervals[i].length == 2
//  0 <= intervals[i][0] < intervals[i][1] <= 10^5
//  All the intervals are unique.
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
#define vi vector<int>

class Solution {
public:
  int removeCoveredIntervals(vector<vi> &is) {
    auto sz = is.size();
    if (sz < 2)
      return sz;

    // Sort in ASC order by start of interval. and in DESC by end of interval
    // in this case biggest interval will be in the beginning
    std::sort(is.begin(), is.end(), [](vi &a, vi &b) {
      return (a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]) < 0;
    });

    int rem = 0;
    vi p = is[0];
    for (int i = 1; i < sz; i++) {
      vi n = is[i];
      if (p[0] <= n[0] && p[1] >= n[1])
        continue;
      p = n;
      rem++;
    }

    return rem;
  }
};

int main(int argc, char *argv[]) {
  auto s = Solution();
  {
    auto v = std::vector<std::vector<int>>{{1, 4}, {3, 6}, {2, 8}};
    std::cout << s.removeCoveredIntervals(v) << std::endl;
  }
  {
    auto v = std::vector<std::vector<int>>{{1, 4}, {2, 3}};
    std::cout << s.removeCoveredIntervals(v) << std::endl;
  }
  return 0;
}
