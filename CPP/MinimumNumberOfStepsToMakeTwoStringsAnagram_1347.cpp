// Difficulty: Medium
// You are given two strings of the same length s and t. In one step you can
// choose any character of t and replace it with another character.
// Return the minimum number of steps to make t an anagram of s.
// An Anagram of a string is a string that contains the same characters with a
// different (or the same) ordering.

// Example 1:
// Input: s = "bab", t = "aba"
// Output: 1
// Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of
// s.

// Example 2:
// Input: s = "leetcode", t = "practice"
// Output: 5
// Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters
// to make t anagram of s.

// Example 3:
// Input: s = "anagram", t = "mangaar"
// Output: 0
// Explanation: "anagram" and "mangaar" are anagrams.

// Constraints:
//     1 <= s.length <= 5 * 10^4
//     s.length == t.length
//     s and t consist of lowercase English letters only.

#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

int minSteps(std::string s, std::string t) {
    std::unordered_map<char, int> sMap;
    std::unordered_map<char, int> tMap;

    for (int i = 0; i < s.size(); i++) {
        sMap[s[i]]++;
        tMap[t[i]]++;
    }

    if (sMap == tMap) {
        return 0;
    }

    int contains = 0;
    int notContains = 0;
    for (auto i : sMap) {
        if (tMap.contains(i.first)) {
            contains += std::abs(i.second - tMap[i.first]);
        } else {
            notContains += i.second;
        }
    }

    for (auto i : tMap) {
        if (sMap.contains(i.first)) {
            contains += std::abs(i.second - sMap[i.first]);
        } else {
            notContains += i.second;
        }
    }

    contains % 2 == 0 ? contains /= 2 : contains = contains / 2 + 1;
    return (contains + notContains) / 2;
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"bab", "aba"},
        {"leetcode", "practice"},
        {"anagram", "mangaar"},
        {"gctcxyuluxjuxnsvmomavutrrfb", "qijrjrhqqjxjtprybrzpyfyqtzf"},
    };

    for (auto test : tests) {
        fmt::print("{}: {}\n", test, minSteps(test.first, test.second));
    }

    return 0;
}
