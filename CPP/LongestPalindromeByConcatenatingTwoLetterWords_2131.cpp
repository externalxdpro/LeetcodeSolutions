// 2131. Longest Palindrome by Concatenating Two Letter Words
// Difficulty: Medium

// You are given an array of strings words. Each element of words consists of
// two lowercase English letters.

// Create the longest possible palindrome by selecting some elements from words
// and concatenating them in any order. Each element can be selected at most
// once.

// Return the length of the longest palindrome that you can create. If it is
// impossible to create any palindrome, return 0.

// A palindrome is a string that reads the same forward and backward.

// Example 1:

// Input: words = ["lc","cl","gg"]
// Output: 6
// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of
// length 6. Note that "clgglc" is another longest palindrome that can be
// created.

// Example 2:

// Input: words = ["ab","ty","yt","lc","cl","ab"]
// Output: 8
// Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" =
// "tylcclyt", of length 8. Note that "lcyttycl" is another longest palindrome
// that can be created.

// Example 3:

// Input: words = ["cc","ll","xx"]
// Output: 2
// Explanation: One longest palindrome is "cc", of length 2.
// Note that "ll" is another longest palindrome that can be created, and so is
// "xx".

// Constraints:

//     1 <= words.length <= 105
//     words[i].length == 2
//     words[i] consists of lowercase English letters.

#include <array>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int longestPalindrome(std::vector<std::string> &words) {
        std::array<std::array<int, 26>, 26> freq{};
        int                                 result = 0;
        for (std::string &word : words) {
            int a = word[0] - 'a', b = word[1] - 'a';
            if (freq[b][a] > 0) {
                result += 4;
                freq[b][a]--;
            } else {
                freq[a][b]++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i][i] > 0) {
                result += 2;
                break;
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, int>> tests = {
        {{"lc", "cl", "gg"}, 6},
        {{"ab", "ty", "yt", "lc", "cl", "ab"}, 8},
        {{"cc", "ll", "xx"}, 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.longestPalindrome(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
