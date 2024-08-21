// 664. Strange Printer
// Difficulty: Hard

// There is a strange printer with the following two special properties:
//     The printer can only print a sequence of the same character each time.
//     At each turn, the printer can print new characters starting from and
//     ending at any place and will cover the original existing characters.
// Given a string s, return the minimum number of turns the printer needed to
// print it.

// Example 1:
// Input: s = "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".

// Example 2:
// Input: s = "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of
// the string, which will cover the existing character 'a'.

// Constraints:
//     1 <= s.length <= 100
//     s consists of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int strangePrinter(std::string s) {
        std::string newStr;
        std::vector dp(101, std::vector(101, -1));
        for (int i = 0; i < (int)s.size(); i++) {
            if (i == (int)s.size() - 1 || s[i] != s[i + 1]) {
                newStr.push_back(s[i]);
            }
        }

        return recurse(newStr, 0, newStr.size(), dp);
    }

    int recurse(std::string &s, int i, int j,
                std::vector<std::vector<int>> &dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int result = i == j ? 0 : 1 + recurse(s, i + 1, j, dp);
        for (int k = i + 2; k < j; k++) {
            if (s[k] == s[i]) {
                result = std::min(result, recurse(s, i + 1, k, dp) +
                                              recurse(s, k, j, dp));
            }
        }
        return dp[i][j] = result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"aaabbb", 2},
        {"aba", 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.strangePrinter(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
