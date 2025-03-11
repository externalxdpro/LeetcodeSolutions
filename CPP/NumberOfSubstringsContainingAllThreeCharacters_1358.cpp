// 1358. Number of Substrings Containing All Three Characters
// Difficulty: Medium

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all
// these characters a, b and c.

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the
// characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab",
// "bcabc", "cab", "cabc" and "abc" (again).

// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the
// characters a, b and c are "aaacb", "aacb" and "acb".

// Example 3:

// Input: s = "abc"
// Output: 1

// Constraints:

//     3 <= s.length <= 5 x 10^4
//     s only consists of a, b or c characters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int numberOfSubstrings(std::string s) {
        int l = 0, r = 0;
        int result  = 0;
        int freq[3] = {0};

        while (r < s.size()) {
            freq[s[r] - 'a']++;
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                result += s.size() - r;
                freq[s[l] - 'a']--;
                l++;
            }
            r++;
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"abcabc", 10},
        {"aaacb", 3},
        {"abc", 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numberOfSubstrings(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
