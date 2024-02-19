// Difficulty: Easy
// Given an integer n, return true if it is a power of two. Otherwise, return
// false.
// An integer n is a power of two, if there exists an integer x such that n ==
// 2x.

// Example 1:
// Input: n = 1
// Output: true
// Explanation: 20 = 1

// Example 2:
// Input: n = 16
// Output: true
// Explanation: 24 = 16

// Example 3:
// Input: n = 3
// Output: false

// Constraints:
//     -2^31 <= n <= 2^31 - 1

// Follow up: Could you solve it without loops/recursion?

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

// using log
class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }

        double log = std::log2(n);
        if ((int)log == log) {
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, bool>> tests = {
        {1, true},           {16, true},          {3, false},
        {268435455, false},  {0, false},          {1073741824, true},
        {2147483647, false}, {1073741825, false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.isPowerOfTwo(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
