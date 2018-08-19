// http://www.codewars.com/kata/find-the-smallest-integer-in-the-array/
//
// Given an array of integers your solution should find the smallest integer.
//
// For example:
//
// Given [34, 15, 88, 2] your solution will return 2
// Given [34, -345, -1, 100] your solution will return -345
// You can assume, for the purpose of this kata, that the supplied array will not be empty.
#include <algorithm>
#include <iostream>
#include <vector>

int findSmallest(std::vector<int> l)
{
    return *std::min_element(std::begin(l), std::end(l));
}

int main(int argc, char *argv[])
{
    std::vector<int> arr{1, 3, -20, 3, 4, 5};
    std::cout << findSmallest(arr) << std::endl;
    return 0;
}
