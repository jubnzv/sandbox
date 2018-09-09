// http://www.codewars.com/kata/56efc695740d30f963000557/train/cpp
#include <iostream>
#include <string>

std::string to_alternating_case(const std::string &str)
{
    std::string res(str);

    for (int i = 0; i < str.length(); i += 1)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            res[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            res[i] = str[i] + 32;
        }
    }

    return res;
}