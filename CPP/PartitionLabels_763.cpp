// 763. Partition Labels
// Difficulty: Medium

// You are given a string s. We want to partition the string into as many parts
// as possible so that each letter appears in at most one part. For example, the
// string "ababcc" can be partitioned into ["abab", "cc"], but partitions such
// as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

// Note that the partition is done so that after concatenating all the parts in
// order, the resultant string should be s.

// Return a list of integers representing the size of these parts.

// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
// splits s into less parts.

// Example 2:

// Input: s = "eccbbbbdec"
// Output: [10]

// Constraints:

//     1 <= s.length <= 500
//     s consists of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> last(26, 0);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        int              l = 0, r = 0;
        std::vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            r = std::max(r, last[s[i] - 'a']);
            if (i == r) {
                result.push_back(i - l + 1);
                l = i + 1;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::vector<int>>> tests = {
        {"ababcbacadefegdehijhklij", {9, 7, 8}},
        {"eccbbbbdec", {10}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.partitionLabels(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
