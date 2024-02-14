// Difficulty: Medium
// Given two strings text1 and text2, return the length of their longest common
// subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string
// with some characters (can be none) deleted without changing the relative
// order of the remaining characters.
//     For example, "ace" is a subsequence of "abcde".

// A common subsequence of two strings is a subsequence that is common to both
// strings.

// Example 1:
// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.

// Example 2:
// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.

// Example 3:
// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

// Constraints:
//     1 <= text1.length, text2.length <= 1000
//     text1 and text2 consist of only lowercase English characters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

// Recursive, no memo
// class Solution {
//   public:
//     int longestCommonSubsequence(std::string text1, std::string text2) {
//         return dp(text1, text2, text1.size() - 1, text2.size() - 1);
//     }

//   private:
//     int dp(std::string &text1, std::string &text2, int i, int j) {
//         if (i == -1 || j == -1) {
//             return 0;
//         }

//         if (text1[i] == text2[j]) {
//             return 1 + dp(text1, text2, i - 1, j - 1);
//         }

//         return std::max(dp(text1, text2, i - 1, j), dp(text1, text2, i, j -
//         1));
//     }
// };

// Recursive w/ memo
class Solution {
  public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        std::vector<std::vector<int>> memo(text1.size(),
                                           std::vector<int>(text2.size(), -1));
        return dp(text1, text2, text1.size() - 1, text2.size() - 1, memo);
    }

  private:
    int dp(std::string &text1, std::string &text2, int i, int j,
           std::vector<std::vector<int>> &memo) {
        if (i == -1 || j == -1) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + dp(text1, text2, i - 1, j - 1, memo);
            return memo[i][j];
        }

        memo[i][j] = std::max(dp(text1, text2, i - 1, j, memo),
                              dp(text1, text2, i, j - 1, memo));
        return memo[i][j];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"abcde", "ace"},
        {"abc", "abc"},
        {"abc", "def"},
    };

    Solution solution;
    for (auto &test : tests) {
        auto result =
            solution.longestCommonSubsequence(test.first, test.second);
        fmt::print("{}: {}\n", test, result);
    }

    return 0;
}
