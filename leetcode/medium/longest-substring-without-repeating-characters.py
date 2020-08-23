# https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/779/
#
# Given a string, find the length of the longest substring without repeating
# characters.
#
# Example 1:
# Input: "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.
#
# Example 2:
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
#
# Example 3:
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. Note that the answer
# must be a substring, "pwke" is a subsequence and not a substring.
import unittest


class Solution:
    def lengthOfLongestSubstring(self, s):
        if not s:
            return 0
        acc = set()
        substr = ''
        length = len(s)

        for i in range(length):
            if s[i] in substr:
                acc.add(substr)
                substr = substr[substr.index(s[i]) + 1:]
            substr += s[i]
            if i == length - 1:
                acc.add(substr)
        return len(sorted(acc, key=lambda x: len(x))[-1])


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_solution(self):
        self.assertEqual(self.s.lengthOfLongestSubstring("abcabcbb"), 3)
        self.assertEqual(self.s.lengthOfLongestSubstring("bbbbb"), 1)
        self.assertEqual(self.s.lengthOfLongestSubstring("pwwkew"), 3)
        self.assertEqual(self.s.lengthOfLongestSubstring("vqblqcb"), 4)


if __name__ == '__main__':
    s = Solution()
    print(s.lengthOfLongestSubstring("vqblqcb"))
