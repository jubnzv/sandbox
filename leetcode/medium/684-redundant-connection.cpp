// https://leetcode.com/problems/redundant-connection/
//
// In this problem, a tree is an undirected graph that is connected and has no
// cycles.
//
// The given input is a graph that started as a tree with N nodes (with distinct
// values 1, 2, ..., N), with one additional edge added. The added edge has two
// different vertices chosen from 1 to N, and was not an edge that already
// existed.
//
// The resulting graph is given as a 2D-array of edges. Each element of edges is
// a pair [u, v] with u < v, that represents an undirected edge connecting nodes
// u and v.
//
// Return an edge that can be removed so that the resulting graph is a tree of N
// nodes. If there are multiple answers, return the answer that occurs last in
// the given 2D-array. The answer edge [u, v] should be in the same format, with
// u < v.
//
// Example 1:
//
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given undirected graph will be like this:
//   1
//  / \
// 2 - 3
//
// Example 2:
//
// Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
// Output: [1,4]
// Explanation: The given undirected graph will be like this:
// 5 - 1 - 2
//     |   |
//     4 - 3
//
// Note:
// The size of the input 2D-array will be between 3 and 1000.
// Every integer represented in the 2D-array will be between 1 and N, where N is
// the size of the input array.
//
//
// Update (2017-09-26):
// We have overhauled the problem description + test cases and specified clearly
// the graph is an undirected graph. For the directed graph follow up please see
// Redundant Connection II). We apologize for any inconvenience caused.
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

class WeightedQuickUnionUF {
public:
  WeightedQuickUnionUF(int N)
      : Count(N), Sizes(std::vector<int>(N, 1)), Ids(std::vector<int>(N)) {
    int i = 0;
    std::for_each(Ids.begin(), Ids.end(), [&](int &item) {
      item += i;
      ++i;
    });
  }

  int find(int p) {
    // Follow links to find a root
    while (p != Ids[p])
      p = Ids[p];
    return p;
  }

  bool do_union(int p, int q) {
    int i = find(p);
    int j = find(q);
    // These nodes are already part of same parent and they don't need to union
    if (i == j)
      return false;

    // Make smaller point to larger one.
    if (Sizes[i] < Sizes[j]) {
      Ids[i] = j;
      Sizes[j] += Sizes[i];
    } else {
      Ids[j] = i;
      Sizes[i] += Sizes[j];
    }

    Count -= 1;
    return true;
  }

private:
  int Count;
  std::vector<int> Sizes;
  std::vector<int> Ids;
};

class Solution {
public:
  std::vector<int>
  findRedundantConnection(std::vector<std::vector<int>> &edges) {
    auto uf = WeightedQuickUnionUF(edges.size());
    std::vector<int> LastRedundantNodes(2);
    for (auto const &e : edges)
      if (!uf.do_union(e[0], e[1]))
        LastRedundantNodes = e;
    return LastRedundantNodes.empty() ? std::vector<int>{-1, -1}
                                      : LastRedundantNodes;
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();
  std::vector<std::vector<int>> V = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  std::vector<int> Expected = {1, 4};
  auto Result = S.findRedundantConnection(V);
  std::cout << "Result:" << std::endl;
  std::copy(Result.begin(), Result.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  assert(Result == Expected);
  return 0;
}
