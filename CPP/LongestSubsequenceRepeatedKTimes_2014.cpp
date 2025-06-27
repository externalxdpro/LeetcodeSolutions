// 2014. Longest Subsequence Repeated k Times
// Difficulty: Hard

// You are given a string s of length n, and an integer k. You are tasked to
// find the longest subsequence repeated k times in string s.

// A subsequence is a string that can be derived from another string by deleting
// some or no characters without changing the order of the remaining characters.

// A subsequence seq is repeated k times in the string s if seq * k is a
// subsequence of s, where seq * k represents a string constructed by
// concatenating seq k times.

//     For example, "bba" is repeated 2 times in the string "bababcba", because
//     the string "bbabba", constructed by concatenating "bba" 2 times, is a
//     subsequence of the string "bababcba".

// Return the longest subsequence repeated k times in string s. If multiple such
// subsequences are found, return the lexicographically largest one. If there is
// no such subsequence, return an empty string.

// Example 1:
// example 1

// Input: s = "letsleetcode", k = 2
// Output: "let"
// Explanation: There are two longest subsequences repeated 2 times: "let" and
// "ete". "let" is the lexicographically largest one.

// Example 2:

// Input: s = "bb", k = 2
// Output: "b"
// Explanation: The longest subsequence repeated 2 times is "b".

// Example 3:

// Input: s = "ab", k = 2
// Output: ""
// Explanation: There is no subsequence repeated 2 times. Empty string is
// returned.

// Constraints:

//     n == s.length
//     2 <= n, k <= 2000
//     2 <= n < k * 8
//     s consists of lowercase English letters.

#include <algorithm>
#include <array>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    std::string longestSubsequenceRepeatedK(std::string &s, int k) {
        std::array<int, 26> freq{};
        for (char c : s) {
            freq[c - 'a']++;
        }
        std::vector<char> valid;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                valid.push_back('a' + i);
            }
        }
        std::queue<std::string> q;
        for (char c : valid) {
            q.push(std::string{c});
        }

        std::string result;
        while (!q.empty()) {
            std::string front = q.front();
            q.pop();
            if (front.size() > result.size()) {
                result = front;
            }
            for (char n : valid) {
                std::string next = front + n;
                if (isValid(s, k, next)) {
                    q.push(next);
                }
            }
        }
        return result;
    }

  private:
    bool isValid(std::string &s, int k, std::string &curr) {
        int i = 0, matched = 0;
        for (char c : s) {
            if (c == curr[i]) {
                i++;
                if (i == curr.size()) {
                    i = 0;
                    matched++;
                    if (matched == k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, std::string>> tests = {
        {{"letsleetcode", 2}, "let"},
        {{"bb", 2}, "b"},
        {{"ab", 2}, ""},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.longestSubsequenceRepeatedK(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
