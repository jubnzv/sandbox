// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3445/
//
// Given an array of 4 digits, return the largest 24 hour time that can be made.
//
// The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from
// 00:00, a time is larger if more time has elapsed since midnight.
//
// Return the answer as a string of length 5.  If no valid time can be made,
// return an empty string.
//
// Example 1:
// Input: [1,2,3,4]
// Output: "23:41"
//
// Example 2:
// Input: [5,5,5,5]
// Output: ""
//
// Note:
//  A.length == 4
//  0 <= A[i] <= 9
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define HANDLE_DIGIT(VEC)                                                      \
  if ((Res = findAndErase((VEC), A)) != -1)                                    \
    Result += std::to_string(Res);                                             \
  else                                                                         \
    return "";

class Solution {
#if 0
public:
  std::string largestTimeFromDigits(std::vector<int> &A) {
    assert(A.size() == 4);
    std::string Result;
    int Res = -1;
    HANDLE_DIGIT(std::vector<int>({2, 1, 0}));
    if (Res == 2) {
      HANDLE_DIGIT(std::vector<int>({9, 8, 7, 6, 5, 4, 3, 2, 1, 0}));
    } else {
      HANDLE_DIGIT(std::vector<int>({3, 2, 1, 0}));
    }
    Result += ":";
    HANDLE_DIGIT(std::vector<int>({5, 4, 3, 2, 1, 0}));
    HANDLE_DIGIT(std::vector<int>({9, 8, 7, 6, 5, 4, 3, 2, 1, 0}));
    return Result;
  }

private:
  int findAndErase(const std::vector<int> &Values, std::vector<int> &Vec) {
    std::vector<int>::iterator It;
    for (const auto &Value : Values) {
      It = std::find(Vec.begin(), Vec.end(), Value);
      std::cout << "searching " << Value << std::endl;
      if (It != Vec.end()) {
        int Res = *It;
        Vec.erase(It);
        std::cout << "OK" << std::endl;
        return Res;
      }
    }
    return -1;
  }
#endif // if 0

  // TIL: https://en.cppreference.com/w/cpp/algorithm/next_permutation
  std::string largestTimeFromDigits(std::vector<int> &A) {
    int max_time = -1;
    // prepare for the generation of permutations next.
    std::sort(A.begin(), A.end());

    do {
      int hour = A[0] * 10 + A[1];
      int minute = A[2] * 10 + A[3];

      if (hour < 24 && minute < 60) {
        int new_time = hour * 60 + minute;
        max_time = new_time > max_time ? new_time : max_time;
      }
    } while (std::next_permutation(A.begin(), A.end()));

    if (max_time == -1) {
      return "";
    } else {
      std::ostringstream strstream;
      strstream << std::setw(2) << std::setfill('0') << max_time / 60 << ":"
                << std::setw(2) << std::setfill('0') << max_time % 60;
      return strstream.str();
    }
  }
};
