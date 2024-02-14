// Difficulty: Hard
// Given a string containing just the characters '(' and ')', return the length
// of the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".

// Example 2:
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".

// Example 3:
// Input: s = ""
// Output: 0

// Constraints:
//     0 <= s.length <= 3 * 104
//     s[i] is '(', or ')'.

#include <algorithm>
#include <fmt/ranges.h>
#include <stack>
#include <vector>

class Solution {
  public:
    int longestValidParentheses(std::string s) {
        std::stack<int>  stk;
        std::vector<int> valid(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')' && !stk.empty()) {
                valid[i]         = 1;
                valid[stk.top()] = 1;
                stk.pop();
            }
        }

        int result = 0;
        int temp   = 0;
        for (int i = 0; i < valid.size(); i++) {
            if (valid[i] == 0) {
                result = std::max(result, temp);
                temp   = 0;
            } else if (valid[i] == 1) {
                result = std::max(result, ++temp);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"(()", 2},
        {")()())", 4},
        {"", 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.longestValidParentheses(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
