// https://leetcode.com/problems/erect-the-fence/
//
// There are some trees, where each tree is represented by (x,y) coordinate in a
// two-dimensional garden. Your job is to fence the entire garden using the
// minimum length of rope as it is expensive. The garden is well fenced only if
// all the trees are enclosed. Your task is to help find the coordinates of
// trees which are exactly located on the fence perimeter.
//
// Example 1:
//
// Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
// Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
// Explanation:
//
// Example 2:
//
// Input: [[1,2],[2,2],[4,2]]
// Output: [[1,2],[2,2],[4,2]]
// Explanation:
//
// Even you only have trees in a line, you need to use rope to enclose them.
//
// Note:
// All trees should be enclosed together. You cannot cut the rope to enclose
// trees that will separate them in more than one group. All input integers
// will range from 0 to 100. The garden has at least one tree. All
// coordinates are distinct. Input points have NO order. No order required
// for output. input types have been changed on April 15, 2019. Please reset
// to default code definition to get new method signature.
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <unordered_set>
#include <utility>
#include <vector>
#include <set>

// My first solution, rewritten completely below.
//
// Implemented using Graham scan.
// See Cormen's Introduction to Algorithms chapter 33.3 for the reference.
#if 0
class Solution {
  using Point2D = std::vector<int>;
  enum Clockwise { Clockwise, CounterClockwise, Collinear };

public:
  std::vector<std::vector<int>>
  outerTrees(std::vector<std::vector<int>> &Points) {
    if (Points.size() <= 3)
      return Points;

    std::size_t Size = Points.size();

    // Find the lowest y-coordinate and leftmost point P0
    Point2D P0 = Points[0];
    auto P0PolarAngle = getPolarAngle(P0);
    int LowestY = P0[1];
    for (const auto &P : Points)
      if (LowestY < P[1]) {
        P0 = P;
        LowestY = P[1];
      }

    // Keep track polar angles for each vertex.
    std::map<Point2D *, double> PolarAngles;
    for (auto &Point : Points)
      PolarAngles.emplace(
          std::pair<Point2D *, double>(&Point, getPolarAngle(Point)));

    // Sort points by polar angle with P0, if several points have the same polar
    // angle then only keep the farthest.
    // FIXME: Shell's sort is not the best solution
    std::size_t h = 1;
    while (h < Size / 3)
      h = h * 3 + 1;
    while (h >= 1) {
      for (auto i = h; i < Size; i++)
        for (auto j = i; j >= h; j -= h) {
          auto PolarAngle = PolarAngles.at(&Points[j]);
          auto PrevPolarAngle = PolarAngles.at(&Points[j - 1]);
          if (PolarAngle > PrevPolarAngle) {
            std::swap(Points[j], Points[j - 1]);
          } else if (PolarAngle == PrevPolarAngle) {
            auto Distance = getDistance(Points[i], Points[j]);
            auto PrevDistance = getDistance(Points[i], Points[j - 1]);
            if (PrevDistance < Distance)
              Points.erase(Points.begin() + j - 1);
            else
              Points.erase(Points.begin() + j);
            Size -= 1; // TODO: Does this works?..
            // What if they are on one line?..
          }
        }
      h /= 3;
    }

    // Add first three points to the stack. We're using vector since we want
    // to return this value "as is".
    std::vector<Point2D> Hull;

    return Hull;
  }

private:
  inline double getDistance(const Point2D &A, const Point2D &B) const {
    return std::sqrt((B[1] - A[1]) ^ 2 + (B[0] - A[0]) ^ 2);
  }

  double getPolarAngle(const Point2D &A) const {
    double Angle = atan2(A[1], A[0]);
    return (Angle > 0) ? Angle : Angle + 2 * PI;
  }

  // Adapted from Sedgewick's lecture 7 ("Algorithms 1" course, chapter 5)
  int ccw(const Point2D &A, const Point2D &B, const Point2D &C) const {
    auto Area2 = (B[0] - A[0]) * (C[1] - C[1]) - (B[1] - A[1]) * (C[0] - A[0]);
    if (Area2 < 0)
      return Clockwise::Clockwise;
    else if (Area2 > 0)
      return Clockwise::CounterClockwise;
    else
      return Clockwise::Collinear;
  }

private:
  constexpr static const double PI = /* acos(-1.0) */ 3.14159265;
};
#endif // if 0

namespace std {
template <> struct hash<std::vector<int>> {
  std::size_t operator()(std::vector<int> const &vec) const {
    std::size_t seed = vec.size();
    for (auto &i : vec) {
      seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};
} // namespace std

/// Rewritten after watching Tushar Roy explaintaions:
/// * https://www.youtube.com/watch?v=Vu84lmMzP2o
/// * https://github.com/mission-peace/interview/blob/master/src/com/interview/geometry/JarvisMarchConvexHull.java
///
/// Convex hull or convex envelope of a set X of points in the Euclidean plane
/// or in a Euclidean space (or, more generally, in an affine space over the
/// reals) is the smallest convex set that contains X.
///
/// Jarvis March is finding convex or gift wrapping algorithm.
///
/// Time complexity O(nh)
///  n - number of points
///  h - number of points on the boundary.
///  Worst case O(n^2)
///
/// Space complexity O(n^2)
///
/// Reference
/// https://leetcode.com/problems/erect-the-fence/description/
/// https://en.wikipedia.org/wiki/Convex_hull
/// https://en.wikipedia.org/wiki/Gift_wrapping_algorithm
class Solution {
  using Point2D = std::vector<int>;
  enum Clockwise { Clockwise, CounterClockwise, Collinear };

public:
  std::vector<std::vector<int>>
  outerTrees(std::vector<std::vector<int>> &Points) {
    if (Points.size() <= 3)
      return Points;

    std::size_t Size = Points.size();

    // Find the leftmost point P0
    Point2D P0 = Points[0];
    for (std::size_t i = 1; i < Size; i++)
      if (P0[0] > Points[i][0])
        P0 = Points[i];
    Point2D CurrentPoint = P0;

    std::cout << "Start point: [" << P0[0] << ", " << P0[1] << "]" << std::endl;

    // Use set because this algorithm might try to insert duplicate point.
    auto Result = std::unordered_set<std::vector<int>>();
    Result.insert(P0);

    // Sort points by polar angle with P0, if several points have the same polar
    // angle then only keep the farthest.
    std::vector<std::vector<int>> CollinearPoints;
    while (true) {
      auto NextTarget = Points[0];

      for (std::size_t i = 1; i < Size; i++) {
        if (Points[i] == CurrentPoint)
          continue;

        switch (ccw(CurrentPoint, NextTarget, Points[i])) {
        // If it's collinear point then pick the further one but add closer one
        // to list of collinear points.
        case Clockwise::Clockwise:
          NextTarget = Points[i];
          // Reset collinear points because we now how a new NextTarget.
          CollinearPoints.clear();
          break;
        // If it's collinear point then pick the further one but add closer one
        // to list of collinear points.
        case Clockwise::Collinear:
          if (distance(CurrentPoint, NextTarget, Points[i]) == -1) {
            CollinearPoints.push_back(NextTarget);
            NextTarget = Points[i];
          } else {
            CollinearPoints.push_back(Points[i]);
          }
          break;
        // Nothing to do since Points[i] is on right side of current ->
        // nextTarget.
        default:
          break;
        }
      }

      for (const auto &Point : CollinearPoints) {
        std::cout << "Inserting collinear point [" << Point[0] << ", "
                  << Point[1] << "]" << std::endl;
        Result.insert(Point);
      }

      // If nextTarget is same as leftmost it means we have formed an envelope
      // and its done.
      if (NextTarget == P0)
        break;

      // Add nextTarget to result and set current to nextTarget.
      Result.insert(NextTarget);
      std::cout << "Inserting NextTarget: [" << NextTarget[0] << ", "
                << NextTarget[1] << "]" << std::endl;
      CurrentPoint = NextTarget;
    }

    std::vector<std::vector<int>> ResultVec;
    for (auto const &Point : Result)
      ResultVec.insert(ResultVec.begin(), Point);
    return ResultVec;
  }

private:
  int ccw(const Point2D &A, const Point2D &B, const Point2D &C) {
    int y1 = A[1] - B[1];
    int y2 = A[1] - C[1];
    int x1 = A[0] - B[0];
    int x2 = A[0] - C[0];

    auto res = y2 * x1 - y1 * x2;
    if (res > 0)
      return Clockwise::Clockwise;
    else if (res == 0)
      return Clockwise::Collinear;
    return Clockwise::CounterClockwise;
  }

  /// Returns:
  /// -1 if 'b' is closer to 'a' compared to 'c'
  ///  0 if 'b' and 'c' are same distance from 'a'
  ///  1 if 'c' is closer to 'a' compared to 'b'
  int distance(const Point2D &a, const Point2D &b, const Point2D &c) {
    int y1 = a[1] - b[1];
    int y2 = a[1] - c[1];
    int x1 = a[0] - b[0];
    int x2 = a[0] - c[0];

    auto lhs = y1 * y1 + x1 * x1;
    auto rhs = y2 * y2 + x2 * x2;

    if (lhs < rhs)
      return -1;
    else if (lhs > rhs)
      return 1;
    return 0;
  }
};

int main(int argc, char *argv[]) {
  auto S = Solution();

  {
    std::vector<std::vector<int>> Points = {{1, 1}, {2, 2}, {2, 0},
                                            {2, 4}, {3, 3}, {4, 2}};
    std::vector<std::vector<int>> Expected = {
        {1, 1}, {2, 0}, {3, 3}, {2, 4}, {4, 2}};
    auto Result = S.outerTrees(Points);

    std::cout << "Result: " << std::endl;
    for (const auto &Row : Result) {
      std::cout << "[";
      std::copy(Row.begin(), Row.end(),
                std::ostream_iterator<int>(std::cout, " "));
      std::cout << "] ";
    }
    std::cout << std::endl;

    std::cout << "Expected: " << std::endl;
    for (const auto &Row : Expected) {
      std::cout << "[";
      std::copy(Row.begin(), Row.end(),
                std::ostream_iterator<int>(std::cout, " "));
      std::cout << "] ";
    }
    std::cout << std::endl;

    auto ResultSet = std::set<std::vector<int>>(Result.begin(), Result.end());
    auto ExpectedSet = std::set<std::vector<int>>(Expected.begin(), Expected.end());
    assert(ResultSet == ExpectedSet);
  }

  return 0;
}
