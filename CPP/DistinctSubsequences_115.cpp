// 115. Distinct Subsequences
// Difficulty: Hard

// Given two strings s and t, return the number of distinct subsequences of s
// which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed
// integer.

// Example 1:
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit

// Example 2:
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

// Constraints:
//     1 <= s.length, t.length <= 1000
//     s and t consist of English letters.

#include <cstring>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int numDistinct(std::string s, std::string t) {
        int dp[1001][1001];
        std::memset(dp, -1, sizeof(dp));
        return recurse(s, t, 0, 0, dp);
    }

  private:
    int recurse(std::string &s, std::string &t, int i, int j,
                int dp[1001][1001]) {
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = (s[i] == t[j] ? recurse(s, t, i + 1, j + 1, dp) : 0) +
                          recurse(s, t, i + 1, j, dp);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, int>> tests = {
        {{"rabbbit", "rabbit"}, 3},
        {{"babgbag", "bag"}, 5},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numDistinct(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
