// Difficulty: Easy
// Given an array of strings words, return the first palindromic string in the
// array. If there is no such string, return an empty string "".
// A string is palindromic if it reads the same forward and backward.

// Example 1:
// Input: words = ["abc","car","ada","racecar","cool"]
// Output: "ada"
// Explanation: The first string that is palindromic is "ada".
// Note that "racecar" is also palindromic, but it is not the first.

// Example 2:
// Input: words = ["notapalindrome","racecar"]
// Output: "racecar"
// Explanation: The first and only string that is palindromic is "racecar".

// Example 3:
// Input: words = ["def","ghi"]
// Output: ""
// Explanation: There are no palindromic strings, so the empty string is
// returned.

// Constraints:
//     1 <= words.length <= 100
//     1 <= words[i].length <= 100
//     words[i] consists only of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

// class Solution {
//   public:
//     std::string firstPalindrome(std::vector<std::string> &words) {
//         for (auto s : words) {
//             if (isPalindrome(s)) {
//                 return s;
//             }
//         }
//         return "";
//     }

//   private:
//     bool isPalindrome(std::string s) {
//         int l = 0, r = s.size() - 1;
//         while (l < r) {
//             if (s[l] != s[r]) {
//                 return false;
//             }
//             l++;
//             r--;
//         }

//         return true;
//     }
// };

class Solution {
  public:
    std::string firstPalindrome(std::vector<std::string> &words) {
        auto first = std::ranges::find_if(words, [](std::string &word) {
            return std::equal(word.cbegin(), word.cbegin() + word.size() / 2,
                              word.crbegin());
        });

        if (first != words.end()) {
            return *first;
        }
        return "";
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, std::string>> tests = {
        {{"abc", "car", "ada", "racecar", "cool"}, "ada"},
        {{"notapalindrome", "racecar"}, "racecar"},
        {{"def", "ghi"}, ""},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.firstPalindrome(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
