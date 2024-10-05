// 567. Permutation in String
// Difficulty: Medium

// Given two strings s1 and s2, return true if s2 contains a
// permutation
// of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of
// s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// Constraints:

//     1 <= s1.length, s2.length <= 104
//     s1 and s2 consist of lowercase English letters.

#include <algorithm>
#include <array>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool checkInclusion(const std::string &s1, const std::string &s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        std::array<int, 26> counts{};
        for (char c : s1) {
            counts[c - 'a']++;
        }

        std::array<int, 26> currCounts{};
        for (int i = 0; i < s1.size(); i++) {
            currCounts[s2[i] - 'a']++;
        }
        if (currCounts == counts) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            currCounts[s2[i - s1.size()] - 'a']--;
            currCounts[s2[i] - 'a']++;
            if (currCounts == counts) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> tests = {
        {{"ab", "eidbaooo"}, true},
        {{"ab", "eidboaoo"}, false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.checkInclusion(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
