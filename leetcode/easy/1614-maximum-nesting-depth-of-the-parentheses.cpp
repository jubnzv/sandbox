#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int depth(string &s, int *pos) {
    int c = 0;

    int n = 0;
    int m = 0;
    int nd = 0;
    int p = 0;

    for (; *pos < s.size(); ++(*pos)) {
      if (s[*pos] == '(') {
        ++n;
      } else if (s[*pos] == ')') {
        ++m;
      } else {
        nd = std::max(nd, n-m);
      }

      if (n == m && n != 0)
        break;
    }

    return nd;
  }

  int maxDepth(string &s) {
    if (s.size() <= 1)
      return 0;

    int p = 0;
    int r = 0;
    while (p < s.size()) {
      auto v = depth(s, &p);
      if (v > r)
        r = v;
    }

    return r;
  }
};

int main(int argc, char *argv[]) {
  auto s = Solution();
  {
    std::string ss = "(1+(2*3)+((8)/4))+1";
    std::cout << s.maxDepth(ss) << std::endl;
  }
  {
    std::string ss = "(1)+((2))+(((3)))";
    std::cout << s.maxDepth(ss) << std::endl;
  }
  {
    std::string ss = "1+(2*3)/(2-1)";
    std::cout << s.maxDepth(ss) << std::endl;
  }
  {
    std::string ss = "1";
    std::cout << s.maxDepth(ss) << std::endl;
  }
  return 0;
}
