// 884. Uncommon Words from Two Sentences
// Difficulty: Easy

// A sentence is a string of single-space separated words where each word
// consists only of lowercase letters.
// A word is uncommon if it appears exactly once in one of the sentences, and
// does not appear in the other sentence.
// Given two sentences s1 and s2, return a list of all the uncommon words. You
// may return the answer in any order.

// Example 1:
// Input: s1 = "this apple is sweet", s2 = "this apple is sour"
// Output: ["sweet","sour"]
// Explanation:
// The word "sweet" appears only in s1, while the word "sour" appears only in
// s2.

// Example 2:
// Input: s1 = "apple apple", s2 = "banana"
// Output: ["banana"]

// Constraints:
//     1 <= s1.length, s2.length <= 200
//     s1 and s2 consist of lowercase English letters and spaces.
//     s1 and s2 do not have leading or trailing spaces.
//     All the words in s1 and s2 are separated by a single space.

#include <fmt/ranges.h>
#include <sstream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::string> uncommonFromSentences(std::string s1,
                                                   std::string s2) {
        std::stringstream                    ss1(s1), ss2(s2);
        std::string                          word;
        std::unordered_map<std::string, int> counts;
        while (ss1 >> word) {
            counts[word]++;
        }
        while (ss2 >> word) {
            counts[word]++;
        }

        std::vector<std::string> result;
        for (const auto &[word, count] : counts) {
            if (count == 1) {
                result.push_back(word);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>,
                          std::vector<std::string>>>
        tests = {
            {{"this apple is sweet", "this apple is sour"}, {"sour", "sweet"}},
            {{"apple apple", "banana"}, {"banana"}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.uncommonFromSentences(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
