// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//
// Given a n x n matrix where each of the rows and columns are sorted in
// ascending order, find the kth smallest element in the matrix.
//
// Note that it is the kth smallest element in the sorted order, not the kth
// distinct element.
//
// Example:
//
// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,
//
// return 13.
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ n2.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  // Naive implementation using MaxPQ. This requires additional N space.
  //
  // Runtime: 100 ms, faster than 69.01% of C++ online submissions
  // Memory Usage: 14.3 MB, less than 42.69% of C++ online submissions
  int kthSmallestMaxPQ(std::vector<std::vector<int>> &Matrix, int K) {
    std::priority_queue<int> MaxHeap;
    for (const auto &Row : Matrix) {
      for (const auto &El : Row) {
        if (MaxHeap.size() < K)
          MaxHeap.push(El);
        else {
          if (El < MaxHeap.top()) {
            MaxHeap.pop();
            MaxHeap.push(El);
          }
        }
      }
    }
    return MaxHeap.top();
  }

  // Using binary search for rows
  // Runtime: 64 ms, faster than 89.47% of C++ online submissions
  // Memory Usage: 13.2 MB, less than 87.74% of C++ online submission
  int kthSmallest(std::vector<std::vector<int>> &a, int k) {
    int Rows = a.size();
    int Cols = a[0].size();
    int Start = a[0][0];
    int End = a[Rows - 1][Cols - 1];
    while (Start < End) {
      int Mid = (Start + End) / 2;
      int j = Cols - 1;
      int Cnt = 0;
      for (int i = 0; i < Rows; i++) {
        while (j >= 0 and a[i][j] > Mid)
          j--;
        Cnt += (j + 1);
      }
      if (Cnt < k)
        Start = Mid + 1;
      else
        End = Mid;
    }
    return Start;
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();
  std::vector<std::vector<int>> Seq = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  auto Result = S.kthSmallest(Seq, 8);
  std::cout << "Got " << Result << " Expected 13" << std::endl;
  return 0;
}
