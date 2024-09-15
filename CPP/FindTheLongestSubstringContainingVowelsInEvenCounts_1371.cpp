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

#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int findTheLongestSubstring(std::string s) {
        std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int window = s.size(); window > 0; window--) {
            std::unordered_map<char, int> count;
            for (int i = 0; i < window; i++) {
                count[s[i]]++;
            }

            if (isValid(vowels, count)) {
                return window;
            }

            int start = 0, end = window - 1;

            while (end < s.size() - 1) {
                count[s[start]]--;
                if (count[s[start]] < 0) {
                    count[s[start]] = 0;
                }
                start++, end++;
                count[s[end]]++;
                if (isValid(vowels, count)) {
                    return window;
                }
            }
        }

        return 0;
    }

  private:
    bool isValid(std::vector<char>             &vowels,
                 std::unordered_map<char, int> &count) {
        for (char v : vowels) {
            if (count[v] % 2 != 0) {
                return false;
            }
        }
        return true;
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
