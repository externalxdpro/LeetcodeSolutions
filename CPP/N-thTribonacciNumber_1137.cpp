// [1137] N-th Tribonacci Number
// Easy

// The Tribonacci sequence Tn is defined as follows:
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

// Example 1:
// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4

// Example 2:
// Input: n = 25
// Output: 1389537

// Constraints:
//     0 <= n <= 37
//     The answer is guaranteed to fit within a 32-bit integer, ie. answer <=
//     2^31 - 1.

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

// Recursive
class Solution {
  public:
    int tribonacci(int n) {
        std::unordered_map<int, int> memo;
        return recurse(n, memo);
    }

  private:
    int recurse(int n, std::unordered_map<int, int> &memo) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        if (memo[n]) {
            return memo[n];
        }

        memo[n] =
            recurse(n - 1, memo) + recurse(n - 2, memo) + recurse(n - 3, memo);
        return memo[n];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {4, 4},
        {25, 1389537},
        {37, 2082876103},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.tribonacci(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
