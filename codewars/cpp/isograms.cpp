// https://www.codewars.com/kata/54ba84be607a92aa900000f1/train/cpp
//
// An isogram is a word that has no repeating letters, consecutive or
// non-consecutive. Implement a function that determines whether a string that
// contains only letters is an isogram. Assume the empty string is an isogram.
// Ignore letter case.

// isIsogram "Dermatoglyphics" == true
// isIsogram "moose" == false
// isIsogram "aba" == false

#include <bitset>
#include <iostream>

bool is_isogram(std::string s) {
    constexpr auto len = length(s);
    if (len == 0)
        return true;

    std::bitset<len> bs;
    for (unsigned char c: s) {
        if (bs.test(c))
            return false;
        bs.set(c);
    }

    return true;
}

int main(int argc, char *argv[])
{
    std::cout << isIsogram("Dermatoglyphics") << std::endl;
    std::cout << isIsogram("moose") << std::endl;
    std::cout << isIsogram("aba") << std::endl;
    return 0;
}
