// 921. Minimum Add to Make Parentheses Valid
// Difficulty: Medium

// A parentheses string is valid if and only if:

//     It is the empty string,
//     It can be written as AB (A concatenated with B), where A and B are valid
//     strings, or It can be written as (A), where A is a valid string.

// You are given a parentheses string s. In one move, you can insert a
// parenthesis at any position of the string.

//     For example, if s = "()))", you can insert an opening parenthesis to be
//     "(()))" or a closing parenthesis to be "())))".

// Return the minimum number of moves required to make s valid.

// Example 1:

// Input: s = "())"
// Output: 1

// Example 2:

// Input: s = "((("
// Output: 3

// Constraints:

//     1 <= s.length <= 1000
//     s[i] is either '(' or ')'.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minAddToMakeValid(const std::string &s) {
        int open = 0, closing = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    closing++;
                }
            }
        }
        return closing + open;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"())", 1},
        {"(((", 3},
        {"()))((", 4},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minAddToMakeValid(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
