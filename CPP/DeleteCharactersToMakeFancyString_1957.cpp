// 1957. Delete Characters to Make Fancy String
// Difficulty: Easy

// A fancy string is a string where no three consecutive characters are equal.

// Given a string s, delete the minimum possible number of characters from s to
// make it fancy.

// Return the final string after the deletion. It can be shown that the answer
// will always be unique.

// Example 1:

// Input: s = "leeetcode"
// Output: "leetcode"
// Explanation:
// Remove an 'e' from the first group of 'e's to create "leetcode".
// No three consecutive characters are equal, so return "leetcode".

// Example 2:

// Input: s = "aaabaaaa"
// Output: "aabaa"
// Explanation:
// Remove an 'a' from the first group of 'a's to create "aabaaaa".
// Remove two 'a's from the second group of 'a's to create "aabaa".
// No three consecutive characters are equal, so return "aabaa".

// Example 3:

// Input: s = "aab"
// Output: "aab"
// Explanation: No three consecutive characters are equal, so return "aab".

// Constraints:

//     1 <= s.length <= 105
//     s consists only of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string makeFancyString(const std::string &s) {
        std::string result;
        result.reserve(s.size());

        for (char c : s) {
            if (result.size() >= 2 && c == result.back() &&
                c == *(result.rbegin() + 1)) {
                continue;
            }
            result.push_back(c);
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"leeetcode", "leetcode"},
        {"aaabaaaa", "aabaa"},
        {"aab", "aab"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.makeFancyString(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}