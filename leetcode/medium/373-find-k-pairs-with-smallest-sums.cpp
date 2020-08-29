// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
//
// You are given two integer arrays nums1 and nums2 sorted in ascending order
// and an integer k.
//
// Define a pair (u,v) which consists of one element from the first array and
// one element from the second array.
//
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
//
// Example 1:
//
// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence:
//              [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
// Example 2:
//
// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [1,1],[1,1]
// Explanation: The first 2 pairs are returned from the sequence:
//              [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
// Example 3:
//
// Input: nums1 = [1,2], nums2 = [3], k = 3
// Output: [1,3],[2,3]
// Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
#include <vector>

class Solution {
private:
  class SumComparator {
  public:
    bool operator()(const std::vector<int> &Lhs, const std::vector<int> &Rhs) {
      return Lhs[0] + Lhs[1] < Rhs[0] + Rhs[1];
    }
  };

public:
  std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &Nums1,
                                               std::vector<int> &Nums2, int K) {
    // auto Heap =
    //     std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
    //                         SumComparator>();
    auto Heap = std::priority_queue<std::pair<int, std::vector<int>>>();

    for (std::size_t i = 0; i < Nums1.size(); i++) {
      for (std::size_t j = 0; j < Nums2.size(); j++) {
        if (Heap.size() < K)
          Heap.push(
              {Nums1[i] + Nums2[j], std::vector<int>({Nums1[i], Nums2[j]})});
        else if (Heap.size() == K && Heap.top().first > Nums1[i] + Nums2[j]) {
          Heap.pop();
          Heap.push(
              {Nums1[i] + Nums2[j], std::vector<int>({Nums1[i], Nums2[j]})});
        }
      }
    }

    auto Result = std::vector<std::vector<int>>();
    while (!Heap.empty()) {
      Result.push_back(Heap.top().second);
      Heap.pop();
    }

    return Result;
  }
};

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

static int TestNum = 0;
static void printVec(const std::vector<int> &Vec) {
  std::copy(Vec.begin(), Vec.end(), std::ostream_iterator<int>(std::cout, " "));
}
static void printVec(const std::vector<std::vector<int>> &Vec) {
  for (const auto &Row : Vec) {
    std::cout << "{";
    printVec(Row);
    std::cout << "} ";
  }
  std::cout << std::endl;
}
#define DO_TEST(SEQ1, SEQ2, EXPECTED, K)                                       \
  do {                                                                         \
    std::vector<int> Seq1 = SEQ1;                                              \
    std::vector<int> Seq2 = SEQ2;                                              \
    std::vector<std::vector<int>> Expected = EXPECTED;                         \
    auto Result = S.kSmallestPairs(Seq1, Seq2, K);                             \
    auto ResultSet = std::set<std::vector<int>>(Result.begin(), Result.end()); \
    auto ExpectedSet =                                                         \
        std::set<std::vector<int>>(Expected.begin(), Expected.end());          \
    TestNum++;                                                                 \
    if (ExpectedSet != ResultSet) {                                            \
      std::cout << "Test " << TestNum << " failed" << std::endl;               \
      std::cout << "Input: " << std::endl;                                     \
      printVec(Seq1);                                                          \
      std::cout << std::endl;                                                  \
      printVec(Seq2);                                                          \
      std::cout << std::endl;                                                  \
      std::cout << "K=" << K << std::endl;                                     \
      std::cout << "Result: ";                                                 \
      printVec(Result);                                                        \
      std::cout << "Expected: ";                                               \
      printVec(Expected);                                                      \
    } else {                                                                   \
      std::cout << "Test " << TestNum << " passed" << std::endl;               \
    }                                                                          \
    std::cout << std::endl;                                                    \
  } while (0);

int main(int argc, char *argv[]) {
  auto S = Solution();

  DO_TEST(std::vector<int>({1, 7, 11}), std::vector<int>({2, 4, 6}),
          std::vector<std::vector<int>>({{1, 2}, {1, 4}, {1, 6}}), 3);
  DO_TEST(std::vector<int>({1, 1, 2}), std::vector<int>({1, 2, 3}),
          std::vector<std::vector<int>>({{1, 1}, {1, 1}}), 2);
  DO_TEST(std::vector<int>({1, 2}), std::vector<int>({3}),
          std::vector<std::vector<int>>({{1, 3}, {2, 3}}), 2);
  DO_TEST(std::vector<int>({1, 2, 4, 5, 6}), std::vector<int>({3, 5, 7, 9}),
          std::vector<std::vector<int>>({{1, 3}, {2, 3}, {1, 5}}), 3);

  return 0;
}
