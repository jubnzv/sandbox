// https://leetcode.com/problems/k-closest-points-to-origin/
//
// We have a list of points on the plane.  Find the K closest points to the
// origin (0, 0).
//
// (Here, the distance between two points on a plane is the Euclidean distance.)
//
// You may return the answer in any order.  The answer is guaranteed to be
// unique (except for the order that it is in.)
//
// Example 1:
//
// Input: points = [[1,3],[-2,2]], K = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest K = 1 points from the origin, so the answer is just
// [[-2,2]].
//
// Example 2:
//
// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
// Output: [[3,3],[-2,4]]
// (The answer [[-2,4],[3,3]] would also be accepted.)
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <math.h>
#include <queue>
#include <set>
#include <vector>

using PointsVec = std::vector<std::vector<int>>;
inline float getDistance(const std::vector<int> &Point) {
  return std::sqrt(std::pow(Point[0], 2) + std::pow(Point[1], 2));
}

class Solution {
public:
  // First naive implemenetation using MaxPQ based on ordered array with length
  // K. It doesn't meet leetcode time limits.
  std::vector<std::vector<int>> kClosestMaxpq(PointsVec &Points, int K) {
    std::size_t Size = Points.size();
    if (Size == 1)
      return Points;

    PointsVec Result(K);
    std::vector<int> Distances(K, -1);
    for (std::size_t i = 0; i < Size; i++) {
      auto Distance = getDistance(Points[i]);
      for (std::size_t j = 0; j < K; j++) {
        if (Distances[j] == -1) {
          Distances[j] = Distance;
          Result[j] = Points[i];
          break;
        }
        if (Distance < Distances[j]) {
          Result.insert(Result.begin() + j, Points[i]);
          Result.pop_back();
          Distances.insert(Distances.begin() + j, Distance);
          Distances.pop_back();
          break;
        }
      }
    }

    return Result;
  }

  // Implementation using std::priority_queue
  // This pass leetcode checks.
  std::vector<std::vector<int>> kClosestStdPriorityQueue(PointsVec &Points,
                                                         int K) {
    std::priority_queue<std::pair<float, std::vector<int>>> PQ;
    for (std::size_t i = 0; i < Points.size(); i++) {
      auto Distance = getDistance(Points[i]);
      // PQ.push({Distance, {Points[i][0], Points[i][1]}});
      PQ.push({Distance, Points[i]});
      if (PQ.size() > K)
        PQ.pop();
    }

    PointsVec Result;
    while (!PQ.empty()) {
      Result.push_back(PQ.top().second);
      PQ.pop();
    }
    return Result;
  }

  // Implementation with std::partial_sort.
  // It internally based on heap, see:
  // https://github.com/llvm/llvm-project// /tree/f8b72fba868bc19df829dbe03220fba7d68d38d6/libcxx/include/algorithm#L5055
  std::vector<std::vector<int>> kClosest(PointsVec &Points, int K) {
    partial_sort(Points.begin(), Points.begin() + K, Points.end(),
                 [&](std::vector<int> &Point1, std::vector<int> &Point2) {
                   return getDistance(Point1) < getDistance(Point2);
                 });
    return std::vector<std::vector<int>>(Points.begin(), Points.begin() + K);
  }
};

namespace std {
template <> struct hash<std::vector<int>> {
  std::size_t operator()(std::vector<int> const &vec) const {
    std::size_t Seed = vec.size();
    for (const auto &I : vec) {
      Seed ^= I + 0x9e3779b9 + (Seed << 6) + (Seed >> 2);
    }
    return Seed;
  }
};
} // namespace std

int main(int argc, char *argv[]) {
  auto S = Solution();

  {
    PointsVec Points = {{1, 3}, {-2, 2}};
    int K = 1;
    PointsVec Expected = {{-2, 2}};
    PointsVec Result = S.kClosest(Points, K);
    assert(std::set<std::vector<int>>(Expected.begin(), Expected.end()) ==
           std::set<std::vector<int>>(Result.begin(), Result.end()));
  }

  {
    PointsVec Points = {{3, 3}, {5, -1}, {-2, 4}};
    int K = 2;
    PointsVec Expected = {{3, 3}, {-2, 4}};
    PointsVec Result = S.kClosest(Points, K);
    assert(std::set<std::vector<int>>(Expected.begin(), Expected.end()) ==
           std::set<std::vector<int>>(Result.begin(), Result.end()));
  }

  {
    PointsVec Points = {{-5, 4}, {-6, -5}, {4, 6}};
    int K = 2;
    PointsVec Expected = {{-5, 4}, {4, 6}};
    PointsVec Result = S.kClosest(Points, K);
    std::cout << "Result:" << std::endl;
    for (const auto &Row : Result) {
      std::cout << "[";
      std::copy(Row.begin(), Row.end(),
                std::ostream_iterator<int>(std::cout, ","));
      std::cout << "] ";
    }
    std::cout << std::endl;
    assert(std::set<std::vector<int>>(Expected.begin(), Expected.end()) ==
           std::set<std::vector<int>>(Result.begin(), Result.end()));
  }

  return 0;
}
