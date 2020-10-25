// https://leetcode.com/contest/weekly-contest-211/problems/best-team-with-no-conflicts/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class Solution {

public:
  // First sort of bruteforce solution which fails on some test cases.
  int bestTeamScore_error(vector<int> &scores, vector<int> &ages) {
    auto sz = scores.size();
    if (sz == 1)
      return scores[0];

    // Sort incoming data by scores in descending order. Store results in map,
    // where keys are scores and values are sorted ages.
    // XXX: Probably the error is here. I need to sort by age and break ties by
    // score.
    map<int, vector<int>, greater<int>> msc;
    for (size_t i = 0; i < sz; ++i) {
      auto vp = msc.find(scores[i]);
      if (vp == msc.end()) {
        auto v = vector<int>{ages[i]};
        msc[scores[i]] = v;
      } else {
        auto v = &vp->second;
        v->insert(lower_bound(v->begin(), v->end(), ages[i], less<int>()),
                  ages[i]);
      }
    }

    int bsc = 0;
    for (auto mit = msc.cbegin(); mit != msc.cend(); ++mit) {
      int cur_sc = 0;
      for (const auto &cur_age : (*mit).second) {
        int min_age = cur_age;
        cur_sc += (*mit).first;
        for (auto mit_ = next(mit); mit_ != msc.cend(); ++mit_) {
          for (auto const &age : (*mit_).second) {
            if (age <= min_age) {
              min_age = age;
              cur_sc += (*mit_).first;
            }
          }
        }
        bsc = max(cur_sc, bsc);
      }
    }

    return bsc;
  }

  // DP solution based on
  // https://leetcode.com/problems/longest-increasing-subsequence/ Time: O(n^3)
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    auto sz = scores.size();
    if (sz == 1)
      return scores[0];

    vector<pair<int, int>> arr(sz);
    for (size_t i = 0; i < sz; ++i) {
      arr[i].first = ages[i];
      arr[i].second = scores[i];
    }

    // std::pair will be sorted by this way:
    // __x.first < __y.first || (!(__y.first < __x.first) && __x.second <
    // __y.second);
    sort(arr.begin(), arr.end());

    int bsc = 0;
    vector<int> dp(sz, 0);
    for (int i = 0; i < sz; ++i) {
      dp[i] = arr[i].second;
      for (int j = i - 1; j > -1; --j) {
        if (arr[i].second >= arr[j].second)
          dp[i] = max(dp[i], dp[j] + arr[i].second);
        bsc = max(bsc, dp[i]);
      }
    }

    return bsc;
  }
};

int main(int argc, char *argv[]) {
  auto s = Solution();
  {
    std::vector<int> ss = {4, 5, 6, 5};
    std::vector<int> as = {2, 1, 2, 1};
    std::cout << s.bestTeamScore(ss, as) << " (16)" << std::endl;
  }
  {
    std::vector<int> ss = {1, 3, 7, 3, 2, 4, 10, 7, 5};
    std::vector<int> as = {4, 5, 2, 1, 1, 2, 4, 1, 4};
    std::cout << s.bestTeamScore(ss, as) << " (29)" << std::endl;
  }
  {
    std::vector<int> ss = {596, 277, 897, 622, 500, 299, 34,  536, 797,
                           32,  264, 948, 645, 537, 83,  589, 770};
    std::vector<int> as = {18, 52, 60, 79, 72, 28, 81, 33, 96,
                           15, 18, 5,  17, 96, 57, 72, 72};
    std::cout << s.bestTeamScore(ss, as) << " (3287)" << std::endl;
  }
  {
    std::vector<int> ss = {4, 4, 3, 3, 4, 3, 1, 1};
    std::vector<int> as = {5, 7, 8, 11, 19, 3, 5, 9};
    std::cout << s.bestTeamScore(ss, as) << std::endl;
  }
  return 0;
}
