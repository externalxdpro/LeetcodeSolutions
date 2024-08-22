// 476. Number Complement
// Difficulty: Easy

// The complement of an integer is the integer you get when you flip all the 0's
// to 1's and all the 1's to 0's in its binary representation.
//     For example, The integer 5 is "101" in binary and its complement is "010"
//     which is the integer 2.
// Given an integer num, return its complement.

// Example 1:
// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits),
// and its complement is 010. So you need to output 2.

// Example 2:
// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and
// its complement is 0. So you need to output 0.

// Constraints:
//     1 <= num < 231

// Note: This question is the same as 1009:
// https://leetcode.com/problems/complement-of-base-10-integer/

#include <bitset>
#include <cmath>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int findComplement(int num) {
        int len  = 31 - std::bitset<31>(num).to_string().find('1');
        int temp = std::bitset<31>(std::string(len, '1')).to_ulong();
        return num ^ temp;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {5, 2},
        {1, 0},
        {2147483647, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findComplement(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
