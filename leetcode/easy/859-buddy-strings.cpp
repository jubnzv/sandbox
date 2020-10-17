// https://leetcode.com/problems/buddy-strings/
//
// Given two strings A and B of lowercase letters, return true if you can swap
// two letters in A so the result is equal to B, otherwise, return false.
//
// Swapping letters is defined as taking two indices i and j (0-indexed) such
// that i != j and swapping the characters at A[i] and A[j]. For example,
// swapping at indices 0 and 2 in "abcd" results in "cbad".
//
// Example 1:
//
// Input: A = "ab", B = "ba"
// Output: true
// Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is
// equal to B.
//
// Example 2:
//
// Input: A = "ab", B = "ab"
// Output: false
// Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b',
// which results in "ba" != B.
//
// Example 3:
//
// Input: A = "aa", B = "aa"
// Output: true
// Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is
// equal to B.
//
// Example 4:
//
// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
//
// Example 5:
//
// Input: A = "", B = "aa"
// Output: false
//
// Constraints:
//
//     0 <= A.length <= 20000
//     0 <= B.length <= 20000
//     A and B consist of lowercase letters.
#include <iostream>
#include <string>
#include <unordered_set>

using std::string;

class Solution {
public:
  bool buddyStrings(string A, string B) {
    size_t sz = A.length();
    if (sz < 2 || sz != B.length())
      return false;
    int diff1 = -1, diff2 = -1;
    std::unordered_set<char> A_letters;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] != B[i]) {
        if (diff1 == -1)
          diff1 = i;
        else if (diff2 == -1)
          diff2 = i;
        else
          return false;
      }
      A_letters.insert(A[i]);
    }
    if (diff1 != -1 && diff2 != -1)
      return A[diff1] == B[diff2] && A[diff2] == B[diff1];
    if (diff1 != -1)
      return false;
    return A_letters.size() < A.size();
  }
};

int main(int argc, char *argv[]) {
  auto s = Solution();
  std::cout << (int)s.buddyStrings("ab", "ba") << std::endl;
  std::cout << (int)s.buddyStrings("ab", "ab") << std::endl;
  std::cout << (int)s.buddyStrings("aa", "aa") << std::endl;
  std::cout << (int)s.buddyStrings("aaaaaaabc", "aaaaaaacb") << std::endl;
  return 0;
}
