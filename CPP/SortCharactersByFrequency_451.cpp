// Difficulty: Medium
// Given a string s, sort it in decreasing order based on the frequency of the
// characters. The frequency of a character is the number of times it appears in
// the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
// answer.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and
// "aaaccc" are valid answers. Note that "cacaca" is incorrect, as the same
// characters must be together.

// Example 3:
// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// Constraints:
//     1 <= s.length <= 5 * 10^5
//     s consists of uppercase and lowercase English letters and digits.

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> occurences;
        for (char c : s) {
            occurences[c]++;
        }

        std::vector<std::string> strings;
        for (auto &[k, v] : occurences) {
            strings.push_back(std::string(v, k));
            v = 0;
        }

        std::ranges::sort(strings, [](std::string a, std::string b) {
            return a.size() > b.size();
        });

        return std::accumulate(strings.begin(), strings.end(), std::string());
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"tree", "eert"},
        {"cccaaa", "aaaccc"},
        {"Aabb", "bbaA"},
        {"raaeaedere", "eeeeaaarrd"}};

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.frequencySort(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
