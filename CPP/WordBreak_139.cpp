// 139. Word Break
// Difficulty: Medium

// Given a string s and a dictionary of strings wordDict, return true if s can
// be segmented into a space - separated sequence of one or more dictionary
// words.

// Note that the same word in the dictionary may be reused multiple times in the
// segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple
// pen apple". Note that you are allowed to reuse a dictionary word. Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool wordBreak(const std::string &s, std::vector<std::string> &wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        std::unordered_map<std::string, bool> memo;
        return recurse(s, dict, memo);
    }

  private:
    bool recurse(const std::string &s, std::unordered_set<std::string> &dict,
                 std::unordered_map<std::string, bool> &memo) {
        if (s.empty()) {
            return true;
        }
        if (memo.contains(s)) {
            return false;
        }

        std::string curr;
        for (size_t i = 0; i < s.size(); i++) {
            curr.push_back(s[i]);
            if (dict.contains(curr) && recurse(s.substr(i + 1), dict, memo)) {
                return true;
            }
        }
        return memo[s] = false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::string, std::vector<std::string>>, bool>>
        tests = {
            {{"leetcode", {"leet", "code"}}, true},
            {{"applepenapple", {"apple", "pen"}}, true},
            {{"catsandog", {"cats", "dog", "sand", "and", "cat"}}, false},
            {{"goalspecial", {"go", "goal", "goals", "special"}}, true},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.wordBreak(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
