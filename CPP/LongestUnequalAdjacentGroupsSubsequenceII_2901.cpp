// 2901. Longest Unequal Adjacent Groups Subsequence II
// Difficulty: Medium

// You are given a string array words, and an array groups, both arrays having
// length n.

// The hamming distance between two strings of equal length is the number of
// positions at which the corresponding characters are different.

// You need to select the longest

// from an array of indices [0, 1, ..., n - 1], such that for the subsequence
// denoted as [i0, i1, ..., ik-1] having length k, the following holds:

//     For adjacent indices in the subsequence, their corresponding groups are
//     unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 <
//     k. words[ij] and words[ij+1] are equal in length, and the hamming
//     distance between them is 1, where 0 < j + 1 < k, for all indices in the
//     subsequence.

// Return a string array containing the words corresponding to the indices (in
// order) in the selected subsequence. If there are multiple answers, return any
// of them.

// Note: strings in words may be unequal in length.

// Example 1:

// Input: words = ["bab","dab","cab"], groups = [1,2,2]

// Output: ["bab","cab"]

// Explanation: A subsequence that can be selected is [0,2].

//     groups[0] != groups[2]
//     words[0].length == words[2].length, and the hamming distance between them
//     is 1.

// So, a valid answer is [words[0],words[2]] = ["bab","cab"].

// Another subsequence that can be selected is [0,1].

//     groups[0] != groups[1]
//     words[0].length == words[1].length, and the hamming distance between them
//     is 1.

// So, another valid answer is [words[0],words[1]] = ["bab","dab"].

// It can be shown that the length of the longest subsequence of indices that
// satisfies the conditions is 2.

// Example 2:

// Input: words = ["a","b","c","d"], groups = [1,2,3,4]

// Output: ["a","b","c","d"]

// Explanation: We can select the subsequence [0,1,2,3].

// It satisfies both conditions.

// Hence, the answer is [words[0],words[1],words[2],words[3]] =
// ["a","b","c","d"].

// It has the longest length among all subsequences of indices that satisfy the
// conditions.

// Hence, it is the only answer.

// Constraints:

//     1 <= n == words.length == groups.length <= 1000
//     1 <= words[i].length <= 10
//     1 <= groups[i] <= n
//     words consists of distinct strings.
//     words[i] consists of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::string>
    getWordsInLongestSubsequence(std::vector<std::string> &words,
                                 std::vector<int>         &groups) {
        std::vector<int> memo(words.size(), 1);
        std::vector<int> prev(words.size(), -1);
        int              max = 0;
        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (hamming(words[i], words[j]) == 1 && memo[j] + 1 > memo[i] &&
                    groups[i] != groups[j]) {
                    memo[i] = memo[j] + 1;
                    prev[i] = j;
                }
            }
            if (memo[i] > memo[max]) {
                max = i;
            }
        }

        std::vector<std::string> result;
        for (int i = max; i >= 0; i = prev[i]) {
            result.push_back(words[i]);
        }
        std::ranges::reverse(result);
        return result;
    }

  private:
    bool hamming(std::string &s1, std::string &s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<std::string>, std::vector<int>>,
                          std::vector<std::string>>>
        tests = {
            {{{"bab", "dab", "cab"}, {1, 2, 2}}, {"bab", "dab"}},
            {{{"a", "b", "c", "d"}, {1, 2, 3, 4}}, {"a", "b", "c", "d"}},
            {{{"bdb","aaa","ada"}, {2,1,3}}, {"aaa","ada"}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.getWordsInLongestSubsequence(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
