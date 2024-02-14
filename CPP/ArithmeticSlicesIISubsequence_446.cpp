// Difficulty: Hard
// Given an integer array nums, return the number of all the arithmetic
// subsequences of nums.

// A sequence of numbers is called arithmetic if it consists of at least three
// elements and if the difference between any two consecutive elements is the
// same.
//     For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are
//     arithmetic sequences. For example, [1, 1, 2, 5, 7] is not an arithmetic
//     sequence.

// A subsequence of an array is a sequence that can be formed by removing some
// elements (possibly none) of the array.
//     For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].

// The test cases are generated so that the answer fits in 32-bit integer.

// Example 1:
// Input: nums = [2,4,6,8,10]
// Output: 7
// Explanation: All arithmetic subsequence slices are:
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]

// Example 2:
// Input: nums = [7,7,7,7,7]
// Output: 16
// Explanation: Any subsequence of this array is arithmetic.

// Constraints:
//     1  <= nums.length <= 1000
//     -2^31 <= nums[i] <= 2^31 - 1

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

int numberOfArithmeticSlices(std::vector<int> &nums) {
    auto dp = std::vector<std::vector<int>>(nums.size(),
                                            std::vector<int>(nums.size(), 0));
    std::unordered_map<long, std::vector<int>> map;

    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]].push_back(i);
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            long key = 2L * nums[i] - nums[j];
            for (int val : map[key]) {
                if (val < i) {
                    dp[i][j] += dp[val][i] + 1;
                } else {
                    break;
                }
            }
            sum += dp[i][j];
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {

    std::vector<std::vector<int>> tests = {
        {2, 4, 6, 8, 10},
        {7, 7, 7, 7, 7},
        {-2147483648, 0, -2147483648},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    for (auto test : tests) {
        fmt::print("{}: {}\n", test, numberOfArithmeticSlices(test));
    }

    return 0;
}
