// https://leetcode.com/problems/clone-graph/
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }

  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  void aux(Node *ns, Node *nd, unordered_map<Node *, Node *> &nbs) {
    if (!nd) {
      nd = new Node(ns->val);
      nbs[ns] = nd;
    }
    for (const auto &nb : ns->neighbors) {
      if (nbs.find(nb) == nbs.end()) {
        nbs[ns] = nd;
        aux(nb, nullptr, nbs);
      }
      nd->neighbors.push_back(nbs[nb]);
    }
  }

public:
  Node *cloneGraph(Node *n) {
    if (!n)
      return nullptr;
    Node *nn = new Node(n->val);
    if (n->neighbors.empty())
      return nn;
    unordered_map<Node *, Node *> m;
    m[nn] = n;
    aux(n, nn, m);
    return nn;
  }
};
