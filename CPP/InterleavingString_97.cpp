// 97. Interleaving String
// Difficulty: Medium

// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of
// s1 and s2.
// An interleaving of two strings s and t is a configuration where s and t are
// divided into n and m substrings respectively, such that:
//     s = s1 + s2 + ... + sn
//     t = t1 + t2 + ... + tm
//     |n - m| <= 1
//     The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 +
//     s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

// Example 1:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Explanation: One way to obtain s3 is:
// Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
// Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" =
// "aadbbcbcac". Since s3 can be obtained by interleaving s1 and s2, we return
// true.

// Example 2:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Explanation: Notice how it is impossible to interleave s2 with any other
// string to obtain s3.

// Example 3:
// Input: s1 = "", s2 = "", s3 = ""
// Output: true

// Constraints:
//     0 <= s1.length, s2.length <= 100
//     0 <= s3.length <= 200
//     s1, s2, and s3 consist of lowercase English letters.

// Follow up: Could you solve it using only O(s2.length) additional memory
// space?

#include <array>
#include <fmt/ranges.h>
#include <optional>
#include <vector>

class Solution {
  public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        std::vector dp(s1.size() + 1, std::vector<std::optional<bool>>(
                                          s2.size() + 1, std::nullopt));
        return recurse(s1, s2, s3, 0, 0, dp);
    }

    bool recurse(std::string &s1, std::string &s2, std::string &s3, int i1,
                 int i2, std::vector<std::vector<std::optional<bool>>> &dp) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        if (i1 == s1.size() && i2 == s2.size()) {
            return true;
        }
        if (dp[i1][i2] != std::nullopt) {
            return dp[i1][i2].value();
        }

        int  i3     = i1 + i2;
        bool result = false;
        if (i1 < s1.size() && s1[i1] == s3[i3]) {
            result |= recurse(s1, s2, s3, i1 + 1, i2, dp);
        }
        if (i2 < s2.size() && s2[i2] == s3[i3]) {
            result |= recurse(s1, s2, s3, i1, i2 + 1, dp);
        }
        return (dp[i1][i2] = result).value();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::array<std::string, 3>, bool>> tests = {
        {{"aabcc", "dbbca", "aadbbcbcac"}, true},
        {{"aabcc", "dbbca", "aadbbbaccc"}, false},
        {{"", "", ""}, true},
        {{"", "", "a"}, false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.isInterleave(test[0], test[1], test[2]);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
