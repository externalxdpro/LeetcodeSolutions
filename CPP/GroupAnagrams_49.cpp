// Difficulty: Medium
// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:
//     1 <= strs.length <= 10^4
//     0 <= strs[i].length <= 100
//     strs[i] consists of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (std::string str : strs) {
            groups[hash(str)].push_back(str);
        }

        for (auto &[k, v] : groups) {
            result.push_back(v);
        }

        return result;
    }

  private:
    std::string hash(std::string str) {
        std::vector<int> count(26);
        for (char c : str) {
            count[c - 'a']++;
        }

        std::string result;
        for (int i = 0; i < count.size(); i++) {
            result += (char)(i + 'a');
            result += std::to_string(count[i]);
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::string>,
                          std::vector<std::vector<std::string>>>>
        tests = {
            {{"eat", "tea", "tan", "ate", "nat", "bat"},
             {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}},
            {{"bdddddddddd", "bbbbbbbbbbc"},
             {{"bbbbbbbbbbc"}, {"bdddddddddd"}}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.groupAnagrams(test);
        for (auto &i : result) {
            std::ranges::sort(i);
        }
        std::ranges::sort(result);

        for (auto &i : ans) {
            std::ranges::sort(i);
        }
        std::ranges::sort(ans);

        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
