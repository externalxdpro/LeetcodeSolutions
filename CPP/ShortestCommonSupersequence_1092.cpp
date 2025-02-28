// 1092. Shortest Common Supersequence
// Difficulty: Hard

// Given two strings str1 and str2, return the shortest string that has both
// str1 and str2 as subsequences. If there are multiple valid strings, return
// any of them.

// A string s is a subsequence of string t if deleting some number of characters
// from t (possibly 0) results in the string s.

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation:
// str1 = "abac" is a subsequence of "cabac" because we can delete the first
// "c". str2 = "cab" is a subsequence of "cabac" because we can delete the last
// "ac". The answer provided is the shortest such string that satisfies these
// properties.

// Example 2:

// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"

// Constraints:

//     1 <= str1.length, str2.length <= 1000
//     str1 and str2 consist of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string shortestCommonSupersequence(std::string str1,
                                            std::string str2) {
        int dp[1001][1001];
        for (int i = 0; i <= str1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= str2.size(); j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= str1.size(); i++) {
            for (int j = 1; j <= str2.size(); j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        std::string result;
        int         i = str1.size(), j = str2.size();
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result.push_back(str1[i - 1]);
                i--, j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                result.push_back(str1[i - 1]);
                i--;
            } else {
                result.push_back(str2[j - 1]);
                j--;
            }
        }
        while (i > 0) {
            result.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            result.push_back(str2[j - 1]);
            j--;
        }

        return std::string(result.rbegin(), result.rend());
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, std::string>>
        tests = {
            {{"abac", "cab"}, "cabac"},
            {{"aaaaaaaa", "aaaaaaaa"}, "aaaaaaaa"},

        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.shortestCommonSupersequence(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
