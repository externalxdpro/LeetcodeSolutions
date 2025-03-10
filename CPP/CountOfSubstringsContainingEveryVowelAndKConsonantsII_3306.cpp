// 3306. Count of Substrings Containing Every Vowel and K Consonants II
// Difficulty: Medium

// You are given a string word and a non-negative integer k.

// Return the total number of substrings

// of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once
// and exactly k consonants.

// Example 1:

// Input: word = "aeioqq", k = 1

// Output: 0

// Explanation:

// There is no substring with every vowel.

// Example 2:

// Input: word = "aeiou", k = 0

// Output: 1

// Explanation:

// The only substring with every vowel and zero consonants is word[0..4], which
// is "aeiou".

// Example 3:

// Input: word = "ieaouqqieaouqq", k = 1

// Output: 3

// Explanation:

// The substrings with every vowel and one consonant are:

//     word[0..5], which is "ieaouq".
//     word[6..11], which is "qieaou".
//     word[7..12], which is "ieaouq".

// Constraints:

//     5 <= word.length <= 2 * 105
//     word consists only of lowercase English letters.
//     0 <= k <= word.length - 5

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    long long countOfSubstrings(std::string word, int k) {
        long long                     result = 0;
        int                           l = 0, r = 0;
        std::unordered_map<char, int> vowels;
        int                           consonants = 0;

        std::vector<int> nextIs(word.size());
        int              nextI = word.size();
        for (int i = word.size() - 1; i >= 0; i--) {
            nextIs[i] = nextI;
            if (!isVowel(word[i])) {
                nextI = i;
            }
        }

        while (r < word.size()) {
            char right = word[r];
            if (isVowel(right)) {
                vowels[right]++;
            } else {
                consonants++;
            }
            while (consonants > k) {
                char left = word[l];
                if (isVowel(left)) {
                    vowels[left]--;
                    if (vowels[left] == 0) {
                        vowels.erase(left);
                    }
                } else {
                    consonants--;
                }
                l++;
            }
            while (l < word.size() && vowels.size() == 5 && consonants == k) {
                result += nextIs[r] - r;
                char left = word[l];
                if (isVowel(left)) {
                    vowels[left]--;
                    if (vowels[left] == 0) {
                        vowels.erase(left);
                    }
                } else {
                    consonants--;
                }
                l++;
            }
            r++;
        }

        return result;
    }

  private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, long long>> tests = {
        {{"aeioqq", 1}, 0},
        {{"aeiou", 0}, 1},
        {{"ieaouqqieaouqq", 1}, 3},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countOfSubstrings(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
