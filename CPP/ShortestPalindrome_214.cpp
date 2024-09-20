// 214. Shortest Palindrome
// Difficulty: Hard

// You are given a string s. You can convert s to a
// palindrome
// by adding characters in front of it.
// Return the shortest palindrome you can find by performing this
// transformation.

// Example 1:
// Input: s = "aacecaaa"
// Output: "aaacecaaa"

// Example 2:
// Input: s = "abcd"
// Output: "dcbabcd"

// Constraints:
//     0 <= s.length <= 5 * 10^4
//     s consists of lowercase English letters only.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string shortestPalindrome(std::string s) {
        if (s.empty()) {
            return s;
        }

        int l = 0;

        for (int r = s.size() - 1; r >= 0; r--) {
            if (s[l] == s[r]) {
                l++;
            }
        }

        if (l == s.size()) {
            return s;
        }
        std::string suffix = s.substr(l);
        std::string rev    = std::string(suffix.rbegin(), suffix.rend());
        return rev + shortestPalindrome(s.substr(0, l)) + suffix;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"aacecaaa", "aaacecaaa"},
        {"abcd", "dcbabcd"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.shortestPalindrome(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
