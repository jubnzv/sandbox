// https://leetcode.com/problems/friend-circles/
//
// There are N students in a class. Some of them are friends, while some are
// not. Their friendship is transitive in nature. For example, if A is a direct
// friend of B, and B is a direct friend of C, then A is an indirect friend of
// C. And we defined a friend circle is a group of students who are direct or
// indirect friends.
//
// Given a N*N matrix M representing the friend relationship between students in
// the class. If M[i][j] = 1, then the ith and jth students are direct friends
// with each other, otherwise not. And you have to output the total number of
// friend circles among all the students.
//
// Example 1:
//
// Input:
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation:The 0th and 1st students are direct friends, so they are in a
// friend circle. The 2nd student himself is in a friend circle. So return 2.
//
// Example 2:
//
// Input:
// [[1,1,0],
//  [1,1,1],
//  [0,1,1]]
// Output: 1
// Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
// students are direct friends, so the 0th and 2nd students are indirect
// friends. All of them are in the same friend circle, so return 1.
//
// Constraints:
//
//     1 <= N <= 200
//     M[i][i] == 1
//     M[i][j] == M[j][i]
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using adj_matrix_ty = std::vector<std::vector<int>>;

class CC {
public:
  CC(const adj_matrix_ty &M)
      : Marked(std::vector<bool>(M.size(), false)),
        Id(std::vector<int>(M.size(), -1)), Count(0) {
    // Run DFS from one vertex in each component to count cc's
    for (int i = 0; i < M.size(); i++) {
      if (!Marked[i]) {
        dfs(M, i);
        Count += 1;
      }
    }
  }

  int count() const { return Count; }

private:
  void dfs(const adj_matrix_ty &M, int VertexNum) {
    Marked[VertexNum] = true;
    Id[VertexNum] = Count;
    for (int i; i < M.size(); i++) {
      if (M[VertexNum][i] && !Marked[i])
        dfs(M, i);
    }
  }

private:
  std::vector<bool> Marked;
  std::vector<int> Id;
  int Count;
};

class Solution {
public:
  int findCircleNum(adj_matrix_ty &M) {
    auto Cc = CC(M);
    return Cc.count();
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();

  {
    adj_matrix_ty M = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    auto Result = S.findCircleNum(M);
    std::cout << Result << " == " << 3 << std::endl;
    assert(Result == 3);
  }

  return 0;
}
