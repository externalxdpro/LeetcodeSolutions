// [22] Generate Parentheses
// Difficulty: Medium

// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

// Constraints:
//     1 <= n <= 8

#include <algorithm>
#include <fmt/ranges.h>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<std::string> generateParenthesis(int n) {
        std::unordered_set<std::string> result;
        dp(n, n, 0, "", result);

        return std::vector(result.begin(), result.end());
    }

  private:
    void dp(int n, int left, int open, std::string curr,
            std::unordered_set<std::string> &result) {
        if (open == n) {
            while (open != 0) {
                curr += ')';
                open--;
            }
            result.insert(curr);
            return;
        }
        if (left == 0) {
            while (open != 0) {
                curr += ')';
                open--;
            }
            result.insert(curr);
            return;
        }

        dp(n, left - 1, open + 1, curr + '(', result);
        if (open >= 1) {
            dp(n, left, open - 1, curr + ')', result);
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::vector<std::string>>> tests = {
        {3, {"((()))", "(()())", "(())()", "()(())", "()()()"}},
        {1, {"()"}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.generateParenthesis(test);
        std::ranges::sort(ans);
        std::ranges::sort(result);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
