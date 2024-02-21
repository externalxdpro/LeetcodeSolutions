// Difficulty: Medium
// Given two integers left and right that represent the range [left, right],
// return the bitwise AND of all numbers in this range, inclusive.

// Example 1:
// Input: left = 5, right = 7
// Output: 4

// Example 2:
// Input: left = 0, right = 0
// Output: 0

// Example 3:
// Input: left = 1, right = 2147483647
// Output: 0

// Constraints:
//     0 <= left <= right <= 2^31 - 1

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int rangeBitwiseAnd(int left, int right) {
        std::string leftBin, rightBin;
        while (left != 0) {
            leftBin = (char)((left % 2) + '0') + leftBin;
            left /= 2;
        }
        while (right != 0) {
            rightBin = (char)((right % 2) + '0') + rightBin;
            right /= 2;
        }
        if (leftBin.empty()) {
            leftBin = "0";
        }
        if (rightBin.empty()) {
            rightBin = "0";
        }

        fmt::print("{} {}\n", leftBin, rightBin);

        if (leftBin.size() != rightBin.size()) {
            return 0;
        }

        std::string common;
        for (int i = 0; i < leftBin.size() && leftBin[i] == rightBin[i]; i++) {
            common += leftBin[i];
        }
        int size = common.size();
        for (int i = 0; i < leftBin.size() - size; i++) {
            common += '0';
        }

        int       result     = 0;
        long long multiplier = 1;
        for (int i = common.size() - 1; i >= 0; i--) {
            result += multiplier * (common[i] - '0');
            multiplier *= 2;
        }

        fmt::print("{}\n", common);
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, int>> tests = {
        {{5, 7}, 4}, {{0, 0}, 0}, {{1, 2147483647}, 0},
        {{1, 1}, 1}, {{2, 2}, 2}, {{2147483646, 2147483647}, 2147483646},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.rangeBitwiseAnd(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
