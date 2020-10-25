// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  int getDiff(vector<int> &A, vector<int> &B, int v) {
    int da = 0;
    int db = 0;
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] != v && B[i] != v)
          return -1;
      if (A[i]!=v) ++da;
      if (B[i]!=v) ++db;
    }
    return min(da,db);
  }

public:
  int minDominoRotations(vector<int> &A, vector<int> &B) {
      int da=getDiff(A,B,A[0]);
      int db=getDiff(A,B,B[0]);
      return min(da,db)>0?min(da,db):max(da,db);
  }
};
