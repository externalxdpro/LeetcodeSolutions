// 796. Rotate String
// Difficulty: Easy

// Given two strings s and goal, return true if and only if s can become goal
// after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost
// position.

//     For example, if s = "abcde", then it will be "bcdea" after one shift.

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true

// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false

// Constraints:

//     1 <= s.length, goal.length <= 100
//     s and goal consist of lowercase English letters.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool rotateString(std::string s, std::string goal) {
        for (auto it = s.begin(); it != s.end(); it++) {
            if (goal == std::string(it, s.end()) + std::string(s.begin(), it)) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> tests = {
        {{"abcde", "cdeab"}, true},
        {{"abcde", "abced"}, false},
        {{"aba", "aba"}, true},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.rotateString(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
