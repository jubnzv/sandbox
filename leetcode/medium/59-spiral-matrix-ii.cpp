// Given a positive integer n, generate a square matrix filled with elements
// from 1 to n2 in spiral order.
//
// Example:
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generateMatrix(int N) {
    std::vector<std::vector<int>> M(N, std::vector<int>(N));

    auto Num = 1;
    auto R = 0, C = 0;

    while (Num <= N * N) {
      while (C < N && M[R][C] == 0)
        M[R][C++] = Num++;
      C--;
      R++;

      while (R < N && M[R][C] == 0)
        M[R++][C] = Num++;
      C--;
      R--;

      while (C >= 0 && M[R][C] == 0)
        M[R][C--] = Num++;
      C++;
      R--;

      while (R >= 0 && M[R][C] == 0)
        M[R--][C] = Num++;
      C++;
      R++;
    }

    return M;
  }
};
