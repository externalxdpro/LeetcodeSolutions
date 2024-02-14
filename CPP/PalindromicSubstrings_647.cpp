// Difficulty: Medium
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Constraints:
//     1 <= s.length <= 1000
//     s consists of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <vector>

// Brute-force
// class Solution {
//   public:
//     int countSubstrings(std::string s) {
//         int                                count = 0;
//         std::map<std::pair<int, int>, int> memo;
//         for (int i = 0; i < s.size(); i++) {
//             for (int len = 1; len <= s.size() - i; len++) {
//                 std::string temp = s.substr(i, len);

//                 if (memo.contains({i, len})) {
//                     count += memo[{i, len}];
//                 }

//                 bool palindrome = isPalindrome(temp);
//                 count += palindrome;
//                 memo[{i, len}] = palindrome;
//             }
//         }

//         return count;
//     }

//   private:
//     bool isPalindrome(std::string s) {
//         int l = 0;
//         int r = s.size() - 1;

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
    int countSubstrings(std::string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 || r < s.size()) {
                if (s[l] == s[r]) {
                }

                l--;
                r++;
            }
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"abc", 3},
        {"aaa", 6},
        {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
         500500},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countSubstrings(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
