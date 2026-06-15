// 131. Palindrome Partitioning
// Difficulty: Medium

// Given a string s, partition s such that every substring of the partition is a
// palindrome. Return all possible palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
    std::unordered_map<std::string, std::vector<std::vector<std::string>>> memo;

  public:
    std::vector<std::vector<std::string>> partition(const std::string &s) {
        if (s == "") {
            return {{}};
        }
        if (memo.contains(s)) {
            return memo[s];
        }
        std::vector<std::vector<std::string>> result;
        for (size_t i = 1; i <= s.size(); i++) {
            std::string pfx = s.substr(0, i);
            if (isPalindrome(pfx)) {
                std::vector<std::vector<std::string>> suffixes =
                    partition(s.substr(i));
                for (auto &sfx : suffixes) {
                    std::vector<std::string> tmp = {pfx};
                    tmp.insert(tmp.end(), sfx.begin(), sfx.end());
                    result.push_back(tmp);
                }
            }
        }
        return memo[s] = result;
    }

  private:
    bool isPalindrome(std::string_view s) {
        for (size_t i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>>
        tests = {
            {"aab", {{"a", "a", "b"}, {"aa", "b"}}},
            {"a", {{"a"}}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.partition(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
