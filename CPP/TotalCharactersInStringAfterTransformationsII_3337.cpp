// 3337. Total Characters in String After Transformations II
// Difficulty: Hard

// You are given a string s consisting of lowercase English letters, an integer
// t representing the number of transformations to perform, and an array nums of
// size 26. In one transformation, every character in s is replaced according to
// the following rules:

//     Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the
//     alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a'
//     transforms into the next 3 consecutive characters ahead of it, which
//     results in "bcd". The transformation wraps around the alphabet if it
//     exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character
//     'y' transforms into the next 3 consecutive characters ahead of it, which
//     results in "zab".

// Return the length of the resulting string after exactly t transformations.

// Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: s = "abcyy", t = 2, nums =
// [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]

// Output: 7

// Explanation:

//     First Transformation (t = 1):
//         'a' becomes 'b' as nums[0] == 1
//         'b' becomes 'c' as nums[1] == 1
//         'c' becomes 'd' as nums[2] == 1
//         'y' becomes 'z' as nums[24] == 1
//         'y' becomes 'z' as nums[24] == 1
//         String after the first transformation: "bcdzz"

//     Second Transformation (t = 2):
//         'b' becomes 'c' as nums[1] == 1
//         'c' becomes 'd' as nums[2] == 1
//         'd' becomes 'e' as nums[3] == 1
//         'z' becomes 'ab' as nums[25] == 2
//         'z' becomes 'ab' as nums[25] == 2
//         String after the second transformation: "cdeabab"

//     Final Length of the string: The string is "cdeabab", which has 7
//     characters.

// Example 2:

// Input: s = "azbk", t = 1, nums =
// [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]

// Output: 8

// Explanation:

//     First Transformation (t = 1):
//         'a' becomes 'bc' as nums[0] == 2
//         'z' becomes 'ab' as nums[25] == 2
//         'b' becomes 'cd' as nums[1] == 2
//         'k' becomes 'lm' as nums[10] == 2
//         String after the first transformation: "bcabcdlm"

//     Final Length of the string: The string is "bcabcdlm", which has 8
//     characters.

// Constraints:

//     1 <= s.length <= 105
//     s consists only of lowercase English letters.
//     1 <= t <= 109
//     nums.length == 26
//     1 <= nums[i] <= 25

#include <array>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    using Matrix = std::array<std::array<int, 26>, 26>;

    const int MOD = 1e9 + 7;

  public:
    int lengthAfterTransformations(std::string &s, int t,
                                   std::vector<int> &nums) {
        std::vector<long long> freq(26);
        for (char c : s) {
            freq[c - 'a']++;
        }
        Matrix base{};
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                base[i][(i + j) % 26]++;
            }
        }

        Matrix    mt     = pow(base, t);
        long long result = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) {
                continue;
            }
            for (int j = 0; j < 26; j++) {
                result = (result + freq[i] * mt[i][j]) % MOD;
            }
        }
        return result;
    }

  private:
    Matrix pow(Matrix m, int exp) {
        Matrix result{};
        for (int i = 0; i < 26; i++) {
            result[i][i] = 1;
        }
        Matrix base = m;
        while (exp) {
            if (exp % 2 == 1) {
                result = mul(result, base);
            }
            base = mul(base, base);
            exp >>= 1;
        }
        return result;
    }

    Matrix mul(Matrix &a, Matrix &b) {
        Matrix c{};
        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < 26; k++) {
                long long aik = a[i][k];
                if (!aik) {
                    continue;
                }
                for (int j = 0; j < 26; j++) {
                    c[i][j] = (c[i][j] + aik * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::string, int, std::vector<int>>, int>>
        tests = {
            {{"abcyy", 2, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2}},
             7},
            {{"azbk", 1, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                          2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},
             8},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.lengthAfterTransformations(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
