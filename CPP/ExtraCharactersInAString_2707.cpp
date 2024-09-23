// 2707. Extra Characters in a String
// Difficulty: Medium

// You are given a 0-indexed string s and a dictionary of words dictionary. You
// have to break s into one or more non-overlapping substrings such that each
// substring is present in dictionary. There may be some extra characters in s
// which are not present in any of the substrings.
// Return the minimum number of extra characters left over if you break up s
// optimally.

// Example 1:
// Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
// Output: 1
// Explanation: We can break s in two substrings: "leet" from index 0 to 3 and
// "code" from index 5 to 8. There is only 1 unused character (at index 4), so
// we return 1.

// Example 2:
// Input: s = "sayhelloworld", dictionary = ["hello","world"]
// Output: 3
// Explanation: We can break s in two substrings: "hello" from index 3 to 7 and
// "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in
// any substring and thus are considered as extra characters. Hence, we
// return 3.

// Constraints:
//     1 <= s.length <= 50
//     1 <= dictionary.length <= 50
//     1 <= dictionary[i].length <= 50
//     dictionary[i] and s consists of only lowercase English letters
//     dictionary contains distinct words

#include <fmt/ranges.h>
#include <functional>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int minExtraChar(std::string s, std::vector<std::string> &dictionary) {
        std::unordered_set<std::string> dict(dictionary.begin(),
                                             dictionary.end());
        int                             memo[51];
        std::memset(memo, -1, sizeof(memo));

        std::function<int(int)> dp = [&](int i) -> int {
            if (i == s.size()) {
                return 0;
            }
            if (memo[i] != -1) {
                return memo[i];
            }
            int res = dp(i + 1) + 1;
            for (int j = i; j < s.size(); j++) {
                std::string curr = s.substr(i, j - i + 1);
                if (dict.contains(curr)) {
                    res = std::min(res, dp(j + 1));
                }
            }

            return memo[i] = res;
        };

        return dp(0);
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::string, std::vector<std::string>>, int>>
        tests = {
            {{"leetscode", {"leet", "code", "leetcode"}}, 1},
            {{"sayhelloworld", {"hello", "world"}}, 3},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minExtraChar(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
