#  Given a string containing only three types of characters: '(', ')' and '*',
#  write a function to check whether this string is valid. We define the
#  validity of a string by these rules:
#
#     Any left parenthesis '(' must have a corresponding right parenthesis ')'.
#     Any right parenthesis ')' must have a corresponding left parenthesis '('.
#     Left parenthesis '(' must go before the corresponding right parenthesis ')'.
#     '*' could be treated as a single right parenthesis ')' or a single left
#     parenthesis '(' or an empty string.
#     An empty string is also valid.
#
# Example 1:
#
# Input: "()"
# Output: True
#
# Example 2:
#
# Input: "(*)"
# Output: True
#
# Example 3:
#
# Input: "(*))"
# Output: True
#
# Note:
#
#     The string size will be in the range [1, 100].


class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        if n == 0:
            return True
        if n == 1:
            return True if s[0] == '*' else False
        stack = list([set([0])])
        for i in range(1, n + 1):
            c = s[i-1]
            if c == '(':
                stack.append(set([v+1 for v in stack[i-1]]))
            elif c == ')':
                stack.append(set([v-1 for v in stack[i-1] if v > 0]))
            elif c == '*':
                stack.append(set([v+1 for v in stack[i-1]]) |
                             set([v-1 for v in stack[i-1] if v > 0]) |
                             stack[i-1])
        return 0 in stack[n]


if __name__ == '__main__':
    s = Solution()
    print(s.checkValidString('()'))
    print(s.checkValidString('(*)'))
    print(s.checkValidString('(*)'))
