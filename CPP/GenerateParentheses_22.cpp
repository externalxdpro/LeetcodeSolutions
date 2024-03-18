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
        std::vector<std::string> result;
        dp(n, 0, "", result);
        return result;
    }

  private:
    void dp(int left, int open, std::string curr,
            std::vector<std::string> &result) {
        if (left == 0 && open == 0) {
            result.push_back(curr);
        }
        if (left > 0) {
            dp(left - 1, open + 1, curr + '(', result);
        }
        if (open > 0) {
            dp(left, open - 1, curr + ')', result);
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
