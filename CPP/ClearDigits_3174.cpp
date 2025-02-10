// 3174. Clear Digits
// Difficulty: Easy

// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

//     Delete the first digit and the closest non-digit character to its left.

// Return the resulting string after removing all digits.

// Example 1:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no digit in the string.

// Example 2:

// Input: s = "cb34"

// Output: ""

// Explanation:

// First, we apply the operation on s[2], and s becomes "c4".

// Then we apply the operation on s[1], and s becomes "".

// Constraints:

//     1 <= s.length <= 100
//     s consists only of lowercase English letters and digits.
//     The input is generated such that it is possible to delete all digits.

#include <algorithm>
#include <fmt/ranges.h>
#include <stack>
#include <vector>

class Solution {
  public:
    std::string clearDigits(std::string &s) {
        std::string     result;
        std::stack<int> nonDigits;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                nonDigits.pop();
            } else {
                nonDigits.push(i);
            }
        }
        while (!nonDigits.empty()) {
            result.push_back(s[nonDigits.top()]);
            nonDigits.pop();
        }
        std::ranges::reverse(result);
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"abc", "abc"},
        {"cb34", ""},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.clearDigits(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
