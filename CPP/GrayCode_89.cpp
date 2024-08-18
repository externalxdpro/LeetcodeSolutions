// 89. Gray Code
// Difficulty: Medium

// An n-bit gray code sequence is a sequence of 2n integers where:
//     Every integer is in the inclusive range [0, 2n - 1],
//     The first integer is 0,
//     An integer appears no more than once in the sequence,
//     The binary representation of every pair of adjacent integers differs by
//     exactly one bit, and The binary representation of the first and last
//     integers differs by exactly one bit.
// Given an integer n, return any valid n-bit gray code sequence.

// Example 1:
// Input: n = 2
// Output: [0,1,3,2]
// Explanation:
// The binary representation of [0,1,3,2] is [00,01,11,10].
// - 00 and 01 differ by one bit
// - 01 and 11 differ by one bit
// - 11 and 10 differ by one bit
// - 10 and 00 differ by one bit
// [0,2,3,1] is also a valid gray code sequence, whose binary representation is
// [00,10,11,01].
// - 00 and 10 differ by one bit
// - 10 and 11 differ by one bit
// - 11 and 01 differ by one bit
// - 01 and 00 differ by one bit

// Example 2:
// Input: n = 1
// Output: [0,1]

// Constraints:
//     1 <= n <= 16

#include <algorithm>
#include <cmath>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> grayCode(int n) {
        if (n == 1) {
            return {0, 1};
        }
        std::vector<int> curr = grayCode(n - 1);
        int              pow  = std::pow(2, n - 1);
        for (int i = curr.size() - 1; i >= 0; i--) {
            curr.push_back(curr[i] + pow);
        }
        return curr;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::vector<int>>> tests = {
        {2, {0, 1, 3, 2}},
        {1, {0, 1}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.grayCode(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
