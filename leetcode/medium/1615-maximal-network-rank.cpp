#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {

public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<int> cnt(n);
    set<pair<int, int>> adj;
    size_t res = 0;

    for (auto &r : roads) {
      ++cnt[r[0]];
      ++cnt[r[1]];
      adj.insert({min(r[0], r[1]), max(r[0], r[1])});
    }

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        res = max(res, cnt[i] + cnt[j] - adj.count({i, j}));

    return res;
  }
};

int main(int argc, char *argv[]) {
  auto s = Solution();

  {
    vector<vector<int>> v = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};
    std::cout << s.maximalNetworkRank(4, v) << std::endl;
  }

  {
    vector<vector<int>> v = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
    std::cout << s.maximalNetworkRank(5, v) << std::endl;
  }

  {
    vector<vector<int>> v = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};
    std::cout << s.maximalNetworkRank(8, v) << std::endl;
  }

  return 0;
}
