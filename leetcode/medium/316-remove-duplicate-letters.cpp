// https://leetcode.com/problems/remove-duplicate-letters/
//
// Given a string s, remove duplicate letters so that every letter appears once
// and only once. You must make sure your result is the smallest in
// lexicographical order among all possible results.
//
// Note: This question is the same as 1081:
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
//
// Example 1:
// Input: s = "bcabc"
// Output: "abc"
//
// Example 2:
// Input: s = "cbacdcbc"
// Output: "acdb"
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  string removeDuplicateLetters(string s) {

    string str = "";

    unordered_map<char, int> mp;
    vector<bool> visited(26, false);

    // Count frequency of each character
    for (auto ch : s)
      mp[ch]++;

    for (auto c : s) {
      mp[c]--;

      // We have not visited the current character before
      if (visited[c - 'a'] == false) {
        // If the last character at string is lexographically greater and
        // its count is still there so that it can be adjusted later on in
        // iteration we remove it.
        while (str.length() > 0 and c < str.back() and mp[str.back()] > 0) {
          visited[str.back() - 'a'] = false;
          str.pop_back();
        }
        // After we are done with removing elements from last
        // push the current element and set visited to true.
        str.push_back(c);
        visited[c - 'a'] = true;
      }
    }

    return str;
  }
};
