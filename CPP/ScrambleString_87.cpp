// 87. Scramble String
// Difficulty: Hard

// Description

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool isScramble(std::string s1, std::string s2) {
        std::vector dp(40, std::vector(40, std::vector(40, -1)));
        return recurse(s1, s2, {0, 0}, s1.size(), dp);
    }

    bool recurse(std::string &s1, std::string &s2, std::pair<int, int> l,
                 int len, std::vector<std::vector<std::vector<int>>> &dp) {
        if (len == 0) {
            return (dp[l.first][l.second][len] = true);
        }
        if (dp[l.first][l.second][len] != -1) {
            return dp[l.first][l.second][len];
        }
        for (int i = l.first, j = l.second; i <= len + l.first; i++, j++) {
            if (i == l.first + len) {
                return (dp[l.first][l.second][len] = true);
            }
            if (s1[i] != s2[j]) {
                break;
            }
        }
        std::vector<int> count(26);
        for (int i = l.first, j = l.second; i < len + l.first; i++, j++) {
            count[s1[i] - 'a']++;
            count[s2[j] - 'a']--;
        }
        for (int x : count) {
            if (x) {
                return (dp[l.first][l.second][len] = false);
            }
        }
        for (int i = 1; i < len; i++) {
            if ((recurse(s1, s2, l, i, dp) &&
                 recurse(s1, s2, {l.first + i, l.second + i}, len - i, dp)) ||
                (recurse(s1, s2, {l.first + i, l.second}, len - i, dp) &&
                 recurse(s1, s2, {l.first, l.second + len - i}, i, dp))) {
                return (dp[l.first][l.second][len] = true);
            }
        }
        return (dp[l.first][l.second][len] = false);
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
