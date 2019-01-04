// https://leetcode.com/problems/reverse-integer/

//Given a 32-bit signed integer, reverse digits of an integer.

//Example 1:

//Input: 123
//Output:  321
//Example 2:

//Input: -123
//Output: -321
//Example 3:

//Input: 120
//Output: 21
//Note:
//Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        try {
            string ds = to_string(abs(x));
            std::reverse(ds.begin(), ds.end());
            return x < 0 ? -1 * stoi(ds) : stoi(ds);
        }
        catch(out_of_range) {
            return 0;
        }
    }
};


int main(void) {
    Solution s;
    cout << s.reverse(19) << endl;
    cout << s.reverse(-42) << endl;
    cout << s.reverse(420) << endl;
    cout << s.reverse(-190) << endl;
    return 0;
}
