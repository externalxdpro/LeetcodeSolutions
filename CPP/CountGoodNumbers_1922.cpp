// 1922. Count Good Numbers
// Difficulty: Medium

// A digit string is good if the digits (0-indexed) at even indices are even and
// the digits at odd indices are prime (2, 3, 5, or 7).

//     For example, "2582" is good because the digits (2 and 8) at even
//     positions are even and the digits (5 and 2) at odd positions are prime.
//     However, "3245" is not good because 3 is at an even index but is not
//     even.

// Given an integer n, return the total number of good digit strings of length
// n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain
// leading zeros.

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

// Example 2:

// Input: n = 4
// Output: 400

// Example 3:

// Input: n = 50
// Output: 564908303

// Constraints:

//     1 <= n <= 1015

#include <fmt/ranges.h>
#include <vector>

class Solution {
    const int MOD = 1e9 + 7;

  public:
    int countGoodNumbers(long long n) {
        return exp(5, (n + 1) / 2) * exp(4, n / 2) % MOD;
    }

  private:
    long long exp(int x, long long y) {
        long long result = 1, curr = x;
        while (y) {
            if (y % 2 == 1) {
                result = result * curr % MOD;
            }
            curr = curr * curr % MOD;
            y /= 2;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<long long, int>> tests = {
        {1, 5},
        {4, 400},
        {50, 564908303},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countGoodNumbers(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
