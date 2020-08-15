#  https://leetcode.com/problems/roman-to-integer/description/


class Solution:
    conv = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }

    def romanToInt(self, roman):
        """
        :type roman: str
        :rtype: int
        """
        value = 0
        numbers = [self.conv.get(c) for c in roman]

        for num1, num2 in zip(numbers, numbers[1:]):
            if num1 >= num2:
                value += num1
            else:
                value -= num1

        return value + numbers[-1]


def test_romanToInteger():
    s = Solution()
    assert s.romanToInt("III") == 3
    assert s.romanToInt("IV") == 4
    assert s.romanToInt("IX") == 9
    assert s.romanToInt("LVIII") == 58
    assert s.romanToInt("MCMXCIV") == 1994

