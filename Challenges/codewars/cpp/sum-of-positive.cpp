// http://www.codewars.com/kata/sum-of-positive/train/cpp
//
// You get an array of numbers, return the sum of all of the positives ones.
// Example [1,-4,7,12] => 1 + 7 + 12 = 20
// Note: if there is nothing to sum, the sum is default to 0.
#include <iostream>
#include <vector>

int positive_sum (const std::vector<int> arr){
    int sum_pos = 0;
    for (auto& n : arr) {
        if (n > 0) sum_pos += n;
    }
    return sum_pos;
}

int main(int argc, char *argv[])
{
    std::vector<int> arr{10, 20, 30};
    auto sum = positive_sum(arr);
    std::cout << sum << std::endl;
    return 0;
}
