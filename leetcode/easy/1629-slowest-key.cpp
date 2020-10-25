// https://leetcode.com/problems/slowest-key/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    int n = releaseTimes.size(), max_val = releaseTimes[0];
    char ans = keysPressed[0];

    for (int i = 1; i < n; i++) {
      int val = releaseTimes[i] - releaseTimes[i - 1];
      if (val >= max_val) {
        if (val == max_val)
          ans = max(ans, keysPressed[i]);
        else
          ans = keysPressed[i];
        max_val = val;
      }
    }
    return ans;
  }
};
