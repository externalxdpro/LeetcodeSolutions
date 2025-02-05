// 1790. Check if One String Swap Can Make Strings Equal
// Difficulty: Easy

// You are given two strings s1 and s2 of equal length. A string swap is an
// operation where you choose two indices in a string (not necessarily
// different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at
// most one string swap on exactly one of the strings. Otherwise, return false.

// Example 1:

// Input: s1 = "bank", s2 = "kanb"
// Output: true
// Explanation: For example, swap the first character with the last character of
// s2 to make "bank".

// Example 2:

// Input: s1 = "attack", s2 = "defend"
// Output: false
// Explanation: It is impossible to make them equal with one string swap.

// Example 3:

// Input: s1 = "kelb", s2 = "kelb"
// Output: true
// Explanation: The two strings are already equal, so no string swap operation
// is required.

// Constraints:

//     1 <= s1.length, s2.length <= 100
//     s1.length == s2.length
//     s1 and s2 consist of only lowercase English letters.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        std::vector<std::pair<char, char>> unequal;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (unequal.empty()) {
                    unequal.emplace_back(s1[i], s2[i]);
                } else {
                    unequal.emplace_back(s2[i], s1[i]);
                }
            }
            if (unequal.size() > 2) {
                return false;
            }
        }
        return unequal.size() == 0 ||
               (unequal.size() == 2 && unequal[0] == unequal[1]);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> tests = {
        {{"bank", "kanb"}, true},
        {{"attack", "defend"}, false},
        {{"kelb", "kelb"}, true},
        {{"caa", "aaz"}, false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.areAlmostEqual(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
