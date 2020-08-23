# 14. Longest Common Prefix
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
#
# If there is no common prefix, return an empty string "".
#
# Example 1:
# Input: ["flower","flow","flight"]
# Output: "fl"
#
# Example 2:
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
#
# Note:
# All given inputs are in lowercase letters a-z.
from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        prefix_chars = []
        for i in range(min([len(s) for s in strs])):
            if len(set([s[i] for s in strs])) != 1:
                break
            prefix_chars.append(strs[0][i])
        return ''.join(prefix_chars)
