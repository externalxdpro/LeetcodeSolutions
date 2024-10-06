// 1813. Sentence Similarity III
// Difficulty: Medium

// You are given two strings sentence1 and sentence2, each representing a
// sentence composed of words. A sentence is a list of words that are separated
// by a single space with no leading or trailing spaces. Each word consists of
// only uppercase and lowercase English characters.

// Two sentences s1 and s2 are considered similar if it is possible to insert an
// arbitrary sentence (possibly empty) inside one of these sentences such that
// the two sentences become equal. Note that the inserted sentence must be
// separated from existing words by spaces.

// For example,

//     s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by
//     inserting "my name is" between "Hello" and "Jane" in s1. s1 = "Frog cool"
//     and s2 = "Frogs are cool" are not similar, since although there is a
//     sentence "s are" inserted into s1, it is not separated from "Frog" by a
//     space.

// Given two sentences sentence1 and sentence2, return true if sentence1 and
// sentence2 are similar. Otherwise, return false.

// Example 1:

// Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

// Output: true

// Explanation:

// sentence2 can be turned to sentence1 by inserting "name is" between "My" and
// "Haley".

// Example 2:

// Input: sentence1 = "of", sentence2 = "A lot of words"

// Output: false

// Explanation:

// No single sentence can be inserted inside one of the sentences to make it
// equal to the other.

// Example 3:

// Input: sentence1 = "Eating right now", sentence2 = "Eating"

// Output: true

// Explanation:

// sentence2 can be turned to sentence1 by inserting "right now" at the end of
// the sentence.

// Constraints:

//     1 <= sentence1.length, sentence2.length <= 100
//     sentence1 and sentence2 consist of lowercase and uppercase English
//     letters and spaces. The words in sentence1 and sentence2 are separated by
//     a single space.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool areSentencesSimilar(const std::string &s1, const std::string &s2) {
        if (s1.size() > s2.size()) {
            return areSentencesSimilar(s2, s1);
        }

        std::vector<std::string> words1 = split(s1), words2 = split(s2);
        int l = 0, r1 = words1.size() - 1, r2 = words2.size() - 1;

        while (l < words1.size() && words1[l] == words2[l]) {
            l++;
        }
        while (r1 >= 0 && words1[r1] == words2[r2]) {
            r1--, r2--;
        }
        return r1 < l;
    }

  private:
    std::vector<std::string> split(const std::string &str) {
        std::stringstream        ss(str);
        std::string              word;
        std::vector<std::string> result;
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> tests = {
        {{"My name is Haley", "My Haley"}, true},
        {{"of", "A lot of words"}, false},
        {{"Eating right now", "Eating"}, true},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.areSentencesSimilar(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
