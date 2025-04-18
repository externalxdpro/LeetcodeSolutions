// Difficulty: Medium
// The count-and-say sequence is a sequence of digit strings defined by the
// recursive formula:
//     countAndSay(1) = "1"
//     countAndSay(n) is the way you would "say" the digit string from
//     countAndSay(n-1), which is then converted into a different digit string.

// To determine how you "say" a digit string, split it into the minimal number
// of substrings such that each substring contains exactly one unique digit.
// Then for each substring, say the number of digits, then say the digit.
// Finally, concatenate every said digit.

// For example, the saying and conversion for digit string "3322251":

// Given a positive integer n, return the nth term of the count-and-say
// sequence.

// Example 1:
// Input: n = 1
// Output: "1"
// Explanation: This is the base case.

// Example 2:
// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        std::vector<std::pair<char, int>> counts;
        std::string                       s = "11";
        for (int i = 3; i <= n; i++) {
            char prev = s[0];
            counts    = {{prev, 1}};
            for (int i = 1; i < s.size(); i++) {
                if (s[i] == prev) {
                    counts.back().second++;
                } else {
                    counts.emplace_back(s[i], 1);
                    prev = s[i];
                }
            }
            s = toString(counts);
        }
        return s;
    }

  private:
    std::string toString(std::vector<std::pair<char, int>> &counts) {
        std::string result;
        result.reserve(counts.size() << 1);
        for (auto &[c, count] : counts) {
            result += std::to_string(count) + c;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::string>> tests = {
        {4, "1211"},
        {1, "1"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countAndSay(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
