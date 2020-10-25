// https://leetcode.com/contest/weekly-contest-211/problems/largest-substring-between-two-equal-characters/
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(const string &s) {
        auto sz=s.size();
        if (sz==1) return -1;
        if (sz==2) return s[0]==s[1] ? 0 : -1;
        int r=-1;
        map<char, int> m;
        for (int i=0; i<sz; ++i) {
            auto f = m.find(s[i]);
            if (f == m.end()) {
                m[s[i]] = i;
            } else {
                r = max(i - f->second, r);
                m[s[i]] = min(i, f->second);
            }
        }
        return r == -1 ? -1 : --r;
    }
};

int main(int argc, char *argv[])
{
    auto s = Solution();
    {
        std::string ss = "abca";
        std::cout << s.maxLengthBetweenEqualCharacters(ss) << std::endl;
    }
    {
        std::string ss = "aa";
        std::cout << s.maxLengthBetweenEqualCharacters(ss) << std::endl;
    }
    {
        std::string ss = "cbxyz";
        std::cout << s.maxLengthBetweenEqualCharacters(ss) << std::endl;
    }
    {
        std::string ss = "cabbac";
        std::cout << s.maxLengthBetweenEqualCharacters(ss) << std::endl;
    }
    return 0;
}
