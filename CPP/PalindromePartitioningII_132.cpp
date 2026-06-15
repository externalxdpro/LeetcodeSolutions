// 132. Palindrome Partitioning II
// Difficulty: Hard

// Given a string s, partition s such that every substring of the partition is a
// palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
// cut. Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase English letters only.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minCut(const std::string &s) {
        size_t n = s.size();
        std::vector<int> cuts(n);
        std::vector<std::vector<bool>> memo(n, std::vector(n, false));

        for (size_t i = 0; i < n; i++) {
            int min = i;
            for (size_t j = 0; j <= i; j++) {
                if (s[i] == s[j] && (j + 2 >= i || memo[j + 1][i - 1])) {
                    memo[j][i] = true;
                    if (j == 0) {
                        min = 0;
                    } else {
                        min = std::min(min, cuts[j - 1] + 1);
                    }
                }
            }
            cuts[i] = min;
        }

        return cuts[n - 1];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"aab", 1},
        {"a", 0},
        {"ab", 1},
        {"aaabaa", 1},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.minCut(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
