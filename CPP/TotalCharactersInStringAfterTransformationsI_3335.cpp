// 3335. Total Characters in String After Transformations I
// Difficulty: Medium

// You are given a string s and an integer t, representing the number of
// transformations to perform. In one transformation, every character in s is
// replaced according to the following rules:

//     If the character is 'z', replace it with the string "ab".
//     Otherwise, replace it with the next character in the alphabet. For
//     example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.

// Return the length of the resulting string after exactly t transformations.

// Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: s = "abcyy", t = 2

// Output: 7

// Explanation:

//     First Transformation (t = 1):
//         'a' becomes 'b'
//         'b' becomes 'c'
//         'c' becomes 'd'
//         'y' becomes 'z'
//         'y' becomes 'z'
//         String after the first transformation: "bcdzz"
//     Second Transformation (t = 2):
//         'b' becomes 'c'
//         'c' becomes 'd'
//         'd' becomes 'e'
//         'z' becomes "ab"
//         'z' becomes "ab"
//         String after the second transformation: "cdeabab"
//     Final Length of the string: The string is "cdeabab", which has 7
//     characters.

// Example 2:

// Input: s = "azbk", t = 1

// Output: 5

// Explanation:

//     First Transformation (t = 1):
//         'a' becomes 'b'
//         'z' becomes "ab"
//         'b' becomes 'c'
//         'k' becomes 'l'
//         String after the first transformation: "babcl"
//     Final Length of the string: The string is "babcl", which has 5
//     characters.

// Constraints:

//     1 <= s.length <= 105
//     s consists only of lowercase English letters.
//     1 <= t <= 105

#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
    const int MOD = 1e9 + 7;

  public:
    int lengthAfterTransformations(std::string s, int t) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }
        while (t--) {
            int z = freq[25];
            for (int i = 25; i > 0; i--) {
                freq[i] = freq[i - 1];
            }
            freq[0] = z % MOD;
            freq[1] += z % MOD;
        }
        return std::accumulate(freq, freq + 26, 0LL) % MOD;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, int>> tests = {
        {{"abcyy", 2}, 7},
        {{"azbk", 1}, 5},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.lengthAfterTransformations(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
