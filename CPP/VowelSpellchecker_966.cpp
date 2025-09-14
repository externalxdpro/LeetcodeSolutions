// 966. Vowel Spellchecker
// Difficulty: Medium

// Given a wordlist, we want to implement a spellchecker that converts a query
// word into a correct word.

// For a given query word, the spell checker handles two categories of spelling
// mistakes:

//     Capitalization: If the query matches a word in the wordlist
//     (case-insensitive), then the query word is returned with the same case as
//     the case in the wordlist.
//         Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
//         Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
//         Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
//     Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of
//     the query word with any vowel individually, it matches a word in the
//     wordlist (case-insensitive), then the query word is returned with the
//     same case as the match in the wordlist.
//         Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
//         Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no
//         match) Example: wordlist = ["YellOw"], query = "yllw": correct = ""
//         (no match)

// In addition, the spell checker operates under the following precedence rules:

//     When the query exactly matches a word in the wordlist (case-sensitive),
//     you should return the same word back. When the query matches a word up to
//     capitlization, you should return the first such match in the wordlist.
//     When the query matches a word up to vowel errors, you should return the
//     first such match in the wordlist. If the query has no matches in the
//     wordlist, you should return the empty string.

// Given some queries, return a list of words answer, where answer[i] is the
// correct word for query = queries[i].

// Example 1:

// Input: wordlist = ["KiTe","kite","hare","Hare"], queries =
// ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
// Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]

// Example 2:

// Input: wordlist = ["yellow"], queries = ["YellOw"]
// Output: ["yellow"]

// Constraints:

//     1 <= wordlist.length, queries.length <= 5000
//     1 <= wordlist[i].length, queries[i].length <= 7
//     wordlist[i] and queries[i] consist only of only English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
    std::unordered_set<std::string> words;
    std::unordered_map<std::string, std::string> lower, vowels;

  public:
    std::vector<std::string> spellchecker(std::vector<std::string> &wordlist,
                                          std::vector<std::string> &queries) {
        for (auto &w : wordlist) {
            words.insert(w);
            std::string l = toLower(w);
            if (!lower.contains(l)) {
                lower[l] = w;
            }
            std::string v = rmVowels(l);
            if (!vowels.contains(v)) {
                vowels[v] = w;
            }
        }

        std::vector<std::string> result(queries.size());
        int i = 0;
        for (auto &q : queries) {
            result[i++] = transform(q);
        }
        return result;
    }

  private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    std::string toLower(std::string &s) {
        std::string result;
        std::transform(s.begin(), s.end(), std::back_inserter(result),
                       [](char c) { return std::tolower(c); });
        return result;
    }

    std::string rmVowels(std::string &s) {
        std::string result;
        std::transform(s.begin(), s.end(), std::back_inserter(result),
                       [this](char c) { return isVowel(c) ? ' ' : c; });
        fmt::println("{} {}", s, result);
        return result;
    }

    std::string transform(std::string &s) {
        if (words.contains(s)) {
            return s;
        }
        std::string l = toLower(s);
        if (lower.contains(l)) {
            return lower[l];
        }
        std::string v = rmVowels(l);
        if (vowels.contains(v)) {
            return vowels[v];
        }
        return "";
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::vector<std::string>, std::vector<std::string>>,
                  std::vector<std::string>>>
        tests = {
            {{{"KiTe", "kite", "hare", "Hare"},
              {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti",
               "keet", "keto"}},
             {"kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "",
              "KiTe"}},
            {{{"yellow"}, {"YellOw"}}, {"yellow"}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.spellchecker(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
