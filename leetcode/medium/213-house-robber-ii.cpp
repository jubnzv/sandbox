// https://leetcode.com/problems/house-robber-ii/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(const vector<int> &a) {
    auto sz = a.size();
    if (sz == 0)
      return 0;
    if (sz <= 3)
      return *max_element(a.begin(), a.end());
    return max(aux(a, 0, sz - 2), aux(a, 1, sz - 1));
  }

private:
  // https://www.youtube.com/watch?v=YxwKXFstR2o
  int aux(const vector<int> &a, int first, int last) {
    int prev_prev_prev_sum = a[first];
    int prev_prev_sum = a[first + 1];
    int prev_sum = a[first + 2] + a[first];
    for (int i = first + 3; i <= last; ++i) {
      int cur_sum = a[i] + max(prev_prev_prev_sum, prev_prev_sum);
      prev_prev_prev_sum = prev_prev_sum;
      prev_prev_sum = prev_sum;
      prev_sum = cur_sum;
    }
    return max(prev_sum, prev_prev_sum);
  }
};

int main(int argc, char *argv[]) {
  auto s = Solution();

  {
    vector<int> v = {2, 3, 2};
    std::cout << s.rob(v) << std::endl;
  }

  {
    vector<int> v = {1, 2, 3, 1};
    std::cout << s.rob(v) << std::endl;
  }

  {
    vector<int> v = {1, 3, 1, 3, 100};
    std::cout << s.rob(v) << std::endl;
  }

  return 0;
}
