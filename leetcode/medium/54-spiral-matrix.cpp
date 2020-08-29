// https://leetcode.com/problems/spiral-matrix/P
//
// Given a matrix of m x n elements (m rows, n columns), return all elements of
// the matrix in spiral order.
//
// Example 1:
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &Matrix) {
    if (Matrix.empty())
      return {};
    if (Matrix.size() == 1)
      return Matrix[0];

    int N = Matrix.size();
    int M = Matrix[0].size();
    std::vector<int> Result;
    int Row = 0;
    int Col = 0;

    int RS = 0, RE = N - 1;
    int CS = 0, CE = M - 1;

    while (true) {
      Row = RS;
      Col = CS;
      while (Col <= CE) {
        Result.push_back(Matrix[Row][Col]);
        Col++;
      }
      if (Result.size() == N * M)
        break;
      RS++;

      Row = RS;
      Col = CE;
      while (Row <= RE) {
        Result.push_back(Matrix[Row][Col]);
        Row++;
      }
      if (Result.size() == N * M)
        break;
      CE--;

      Row = RE;
      Col = CE;
      while (Col >= CS) {
        Result.push_back(Matrix[Row][Col]);
        Col--;
      }
      if (Result.size() == N * M)
        break;
      RE--;

      Row = RE;
      Col = CS;
      while (Row >= RS) {
        Result.push_back(Matrix[Row][Col]);
        Row--;
      }
      if (Result.size() == N * M)
        break;
      CS++;
    }

    return Result;
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();
  // std::vector<std::vector<int>> M = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> M = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  auto Result = S.spiralOrder(M);
  std::for_each(Result.begin(), Result.end(),
                [](int V) { std::cout << V << " "; });
  std::cout << std::endl;
  return 0;
}
