// 1593. Split a String Into the Max Number of Unique Substrings
// Difficulty: Medium

// Given a string s, return the maximum number of unique substrings that the
// given string can be split into.

// You can split string s into any list of non-empty substrings, where the
// concatenation of the substrings forms the original string. However, you must
// split the substrings such that all of them are unique.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc'].
// Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a'
// and 'b' multiple times.

// Example 2:

// Input: s = "aba"
// Output: 2
// Explanation: One way to split maximally is ['a', 'ba'].

// Example 3:

// Input: s = "aa"
// Output: 1
// Explanation: It is impossible to split the string any further.

// Constraints:

//     1 <= s.length <= 16

//     s contains only lower case English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <functional>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int maxUniqueSplit(const std::string &s) {
        std::unordered_set<std::string> seen;
        std::function<int(int)>         recurse = [&](int l) -> int {
            if (l == s.size()) {
                return 0;
            }

            int max = 0;
            for (int r = l + 1; r <= s.size(); r++) {
                std::string sub = s.substr(l, r - l);
                if (!seen.contains(sub)) {
                    seen.insert(sub);
                    max = std::max(max, recurse(r) + 1);
                    seen.erase(sub);
                }
            }
            return max;
        };

        return recurse(0);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"ababccc", 5},
        {"aba", 2},
        {"aa", 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxUniqueSplit(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
