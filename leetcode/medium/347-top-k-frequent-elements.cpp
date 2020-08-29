// https://leetcode.com/problems/top-k-frequent-elements/
//
// Given a non-empty array of integers, return the k most frequent elements.
//
// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
//
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
//
// Note:
//  You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//  Your algorithm's time complexity must be better than O(n log n), where n
//  is the array's size. It's guaranteed that the answer is unique, in other
//  words the set of the top k frequent elements is unique. You can return
//  the answer in any order.
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  // First naive implementation: put values in std::unordered_map, sort it by
  // values with quicksort and retrieve the result vector.
  //
  // Suddenly, this solution was accepted by leetcode with:
  // Runtime: 36 ms, faster than 78.44% of C++ online submissions
  // Memory Usage: 14 MB, less than 49.56% of C++ online submissions
  std::vector<int> topKFrequentNaive(std::vector<int> &Nums, int K) {
    // Search, insertion, and removal of elements have average constant-time
    // complexity.
    std::unordered_map<int /* value */, std::size_t /* number of elements */>
        FreqMap;
    for (const auto &Num : Nums) {
      auto Res = FreqMap.find(Num);
      if (Res == FreqMap.end())
        FreqMap.insert({Num, 1});
      else
        Res->second++;
    }

    // As alternative: use multimap
    std::vector<std::pair<int, std::size_t>> Vec;
    for (auto It = FreqMap.begin(); It != FreqMap.end(); It++)
      Vec.push_back(std::make_pair(It->first, It->second));

    std::sort(Vec.begin(), Vec.end(),
              [](const std::pair<int, std::size_t> &First,
                 const std::pair<int, std::size_t> &Second) {
                return First.second > Second.second;
              });

    std::vector<int> Result;
    for (std::size_t i = 0; i < K; i++)
      Result.push_back(Vec[i].first);
    return Result;
  }

  // Same as previous, but use heap instead of quicksort.
  // We're using heap of size K to improve performance of heap operations.
  //
  // Thanks to:
  // https://leetcode.com/problems/top-k-frequent-elements/discuss/646156/C%2B%2B-Minheap-O(nlogk)
  //
  // Runtime: 32 ms, faster than 92.26% of C++ online submissions
  // Memory Usage: 13.9 MB, less than 85.64% of C++ online submissions
  std::vector<int> topKFrequent(std::vector<int> &Nums, int K) {
    std::unordered_map<int /* value */, std::size_t /* number of elements */>
        FreqMap;
    for (const auto &Num : Nums) {
      auto Res = FreqMap.find(Num);
      if (Res == FreqMap.end())
        FreqMap.insert({Num, 1});
      else
        Res->second++;
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> Heap;
    for (auto It = FreqMap.begin(); It != FreqMap.end(); It++) {
      Heap.push(It->second);
      if (Heap.size() > K)
        Heap.pop();
    }

    std::vector<int> Result;
    auto Top = Heap.top();
    for (auto It = FreqMap.begin(); It != FreqMap.end(); It++) {
      if (It->second >= Top)
        Result.push_back(It->first);
    }
    return Result;
  }
};
