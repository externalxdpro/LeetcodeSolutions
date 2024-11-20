// 2516. Take K of Each Character From Left and Right
// Difficulty: Medium

// You are given a string s consisting of the characters 'a', 'b', and 'c' and a
// non-negative integer k. Each minute, you may take either the leftmost
// character of s, or the rightmost character of s.

// Return the minimum number of minutes needed for you to take at least k of
// each character, or return -1 if it is not possible to take k of each
// character.

// Example 1:

// Input: s = "aabaaaacaabc", k = 2
// Output: 8
// Explanation:
// Take three characters from the left of s. You now have two 'a' characters,
// and one 'b' character. Take five characters from the right of s. You now have
// four 'a' characters, two 'b' characters, and two 'c' characters. A total of 3
// + 5 = 8 minutes is needed. It can be proven that 8 is the minimum number of
// minutes needed.

// Example 2:

// Input: s = "a", k = 1
// Output: -1
// Explanation: It is not possible to take one 'b' or 'c' so return -1.

// Constraints:

//     1 <= s.length <= 105
//     s consists of only the letters 'a', 'b', and 'c'.
//     0 <= k <= s.length

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int takeCharacters(const std::string &s, int k) {
        int counts[3] = {0};
        for (char c : s) {
            counts[c - 'a']++;
        }
        if (counts[0] < k || counts[1] < k || counts[2] < k) {
            return -1;
        }

        int window[3] = {0};
        int l = 0, max = 0;

        for (int r = 0; r < s.size(); r++) {
            window[s[r] - 'a']++;

            while (l <= r &&
                   (counts[0] - window[0] < k || counts[1] - window[1] < k ||
                    counts[2] - window[2] < k)) {
                window[s[l] - 'a']--;
                l++;
            }

            max = std::max(max, r - l + 1);
        }

        return s.size() - max;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, int>> tests = {
        {{"aabaaaacaabc", 2}, 8},
        {{"a", 1}, -1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.takeCharacters(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
