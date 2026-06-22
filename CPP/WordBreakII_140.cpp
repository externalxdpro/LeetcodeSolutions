// 140. Word Break II
// Difficulty: Hard

// Given a string s and a dictionary of strings wordDict, add spaces in s to
// construct a sentence where each word is a valid dictionary word. Return all
// such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the
// segmentation.

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict =
// ["apple","pen","applepen","pine","pineapple"] Output: ["pine apple pen
// apple","pineapple pen apple","pine applepen apple"] Explanation: Note that
// you are allowed to reuse a dictionary word. Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []

// Constraints:

// 1 <= s.length <= 20
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 10
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.
// Input is generated in a way that the length of the answer doesn't exceed 105.

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<std::string> wordBreak(std::string s,
                                       std::vector<std::string> &wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        std::unordered_map<std::string, std::vector<std::string>> memo;
        return dp(s, dict, memo);
    }

  private:
    std::vector<std::string>
    dp(const std::string &s, std::unordered_set<std::string> &dict,
       std::unordered_map<std::string, std::vector<std::string>> &memo) {
        if (memo.contains(s)) {
            return memo[s];
        }

        if (s.empty()) {
            return {""};
        }

        std::vector<std::string> result;
        std::string curr;
        for (size_t i = 0; i < s.size(); i++) {
            curr.push_back(s[i]);
            if (dict.contains(curr)) {
                std::vector<std::string> sublist =
                    dp(s.substr(i + 1), dict, memo);
                for (std::string &sub : sublist) {
                    result.push_back(curr + (sub.empty() ? "" : " ") + sub);
                }
            }
        }

        return memo[s] = result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::vector<std::string>>,
                          std::vector<std::string>>>
        tests = {
            {{"catsanddog", {"cat", "cats", "and", "sand", "dog"}},
             {"cats and dog", "cat sand dog"}},
            {{"pineapplepenapple",
              {"apple", "pen", "applepen", "pine", "pineapple"}},
             {"pine apple pen apple", "pineapple pen apple",
              "pine applepen apple"}},
            {{"catsandog", {"cats", "dog", "sand", "and", "cat"}}, {}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.wordBreak(test.first, test.second);
        std::unordered_set ansSet(ans.begin(), ans.end());
        std::unordered_set resultSet(result.begin(), result.end());
        fmt::println("{} {}: {}", resultSet == ansSet ? "✅" : "❌", test,
                     result);
    }

    return 0;
}
