// 87. Scramble String
// Difficulty: Hard

// Description

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool isScramble(std::string s1, std::string s2) {
        int         n = s1.size();
        std::vector dp(n + 1, std::vector(n, std::vector(n, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                for (int j = 0; j < n - len + 1; j++) {
                    for (int newLen = 1; newLen < len; newLen++) {
                        const std::vector<int> dp1 = dp[newLen][i];
                        const std::vector<int> dp2 =
                            dp[len - newLen][i + newLen];
                        dp[len][i][j] |= dp1[j] && dp2[j + newLen];
                        dp[len][i][j] |= dp1[j + len - newLen] && dp2[j];
                    }
                }
            }
        }

        return dp[n][0][0];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> tests = {
        {{"great", "rgeat"}, true},
        {{"abcde", "caebd"}, false},
        {{"a", "a"}, true},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.isScramble(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
