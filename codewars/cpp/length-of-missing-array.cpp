// https://www.codewars.com/kata/length-of-missing-array
#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
int getLengthOfMissingArray(std::vector<std::vector<T>> array_of_arrays)
{
    if (array_of_arrays.empty())
        return 0;
    std::vector<ssize_t> sizes;
    for (auto const &v : array_of_arrays) {
        if (v.empty())
            return 0;
        sizes.push_back(v.size());
    }
    std::sort(sizes.begin(), sizes.end());
    for (ssize_t i = 1; i < sizes.size(); ++i) {
        if (sizes[i] != sizes[i - 1] + 1)
            return sizes[i] - 1;
    }
    return 0;
}

