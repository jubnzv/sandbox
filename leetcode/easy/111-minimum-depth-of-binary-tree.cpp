// https://leetcode.com/problems/minimum-depth-of-binary-tree/
#include <deque>
#include <unordered_set>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    deque<pair<const TreeNode *, int /* depth */>> d = {{root, 1}};
    unordered_set<const TreeNode *> s = {root};
    while (!d.empty()) {
      auto [v, depth] = d.front();
      d.pop_front();

      auto l = v->left;
      auto r = v->right;
      if (!l && !r)
        return depth;

      if (l && s.find(l) == s.end()) {
        s.insert(l);
        d.push_back({l, depth + 1});
      }
      if (r && s.find(r) == s.end()) {
        s.insert(r);
        d.push_back({r, depth + 1});
      }
    }
    return -1;
  }
};
