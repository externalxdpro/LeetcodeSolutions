// 1190. Reverse Substrings Between Each Pair of Parentheses
// Difficulty: Medium

// You are given a string s that consists of lower case English letters and
// brackets.
// Reverse the strings in each pair of matching parentheses, starting from the
// innermost one.
// Your result should not contain any brackets.

// Example 1:
// Input: s = "(abcd)"
// Output: "dcba"

// Example 2:
// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is
// reversed.

// Example 3:
// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally,
// the whole string.

// Constraints:
//     1 <= s.length <= 2000
//     s only contains lower case English characters and parentheses.
//     It is guaranteed that all parentheses are balanced.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string reverseParentheses(std::string s) {
        int l = -1, r = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                l = i;
            }
        }
        for (int i = l; i < s.size(); i++) {
            if (s[i] == ')') {
                r = i;
                break;
            }
        }
        if (l == -1 || r == -1) {
            return s;
        }

        std::string substr = std::string(s.begin() + l + 1, s.begin() + r);
        return reverseParentheses(s.substr(0, l) +
                                  std::string(substr.rbegin(), substr.rend()) +
                                  s.substr(r + 1));
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"(abcd)", "dcba"},
        {"(u(love)i)", "iloveu"},
        {"(ed(et(oc))el)", "leetcode"},
        {"ta()usw((((a))))", "tauswa"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.reverseParentheses(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
