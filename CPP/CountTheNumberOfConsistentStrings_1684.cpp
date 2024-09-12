// 1684. Count the Number of Consistent Strings
// Difficulty: Easy

// You are given a string allowed consisting of distinct characters and an array
// of strings words. A string is consistent if all characters in the string
// appear in the string allowed.
// Return the number of consistent strings in the array words.

// Example 1:
// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
// Explanation: Strings "aaab" and "baa" are consistent since they only contain
// characters 'a' and 'b'.

// Example 2:
// Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
// Output: 7
// Explanation: All strings are consistent.

// Example 3:
// Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
// Output: 4
// Explanation: Strings "cc", "acd", "ac", and "d" are consistent.

// Constraints:
//     1 <= words.length <= 10^4
//     1 <= allowed.length <= 26
//     1 <= words[i].length <= 10
//     The characters in allowed are distinct.
//     words[i] and allowed contain only lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int countConsistentStrings(std::string               allowed,
                               std::vector<std::string> &words) {
        std::unordered_set<char> set(allowed.begin(), allowed.end());
        int                      result = 0;
        for (std::string &word : words) {
            for (char c : word) {
                if (!set.contains(c)) {
                    goto cont;
                }
            }
            result++;
        cont:
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::string, std::vector<std::string>>, int>>
        tests = {
            {{"ab", {"ad", "bd", "aaab", "baa", "badab"}}, 2},
            {{"abc", {"a", "b", "c", "ab", "ac", "bc", "abc"}}, 7},
            {{"cad", {"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"}}, 4},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countConsistentStrings(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
