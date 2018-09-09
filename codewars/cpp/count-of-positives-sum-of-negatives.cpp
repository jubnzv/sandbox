// https://www.codewars.com/kata/576bb71bbbcf0951d5000044/train/cpp

#include <algorithm>
#include <vector>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    if (input.empty()) {
        return {};
    }
    std::vector<int> res = { 0, 0 };
    std::for_each(input.begin(), input.end(),
        [&](int i) {
            (i > 0) ? (res[0] += 1) : (res[1] += i);
        });
    return res;
}
