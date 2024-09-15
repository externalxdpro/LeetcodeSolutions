// 1371. Find the Longest Substring Containing Vowels in Even Counts
// Difficulty: Medium

// Given the string s, return the size of the longest substring containing each
// vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must
// appear an even number of times.

// Example 1:
// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each
// of the vowels: e, i and o and zero of the vowels: a and u.

// Example 2:
// Input: s = "leetcodeisgreat"
// Output: 5
// Explanation: The longest substring is "leetc" which contains two e's.

// Example 3:
// Input: s = "bcbcbc"
// Output: 6
// Explanation: In this case, the given string "bcbcbc" is the longest because
// all vowels: a, e, i, o and u appear zero times.

// Constraints:
//     1 <= s.length <= 5 x 10^5
//     s contains only lowercase English letters.

#include <cstring>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int findTheLongestSubstring(std::string s) {
        const int charMap[] = {1, 0, 0, 0, 2, 0, 0, 0,  4, 0, 0, 0, 0,
                               0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0};
        int       mp[32];
        std::memset(mp, -1, sizeof(mp));

        int prefixXOR = 0;
        int result    = 0;
        mp[0]         = 0;

        for (int i = 0; i < s.size(); i++) {
            prefixXOR ^= charMap[s[i] - 'a'];
            if (mp[prefixXOR] == -1) {
                mp[prefixXOR] = i + 1;
            } else {
                result = std::max(result, i - mp[prefixXOR] + 1);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"eleetminicoworoep", 13},
        {"leetcodeisgreat", 5},
        {"bcbcbc", 6},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findTheLongestSubstring(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
