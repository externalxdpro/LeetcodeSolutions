// 1625. Lexicographically Smallest String After Applying Operations
// Difficulty: Medium

// You are given a string s of even length consisting of digits from 0 to 9, and
// two integers a and b.

// You can apply either of the following two operations any number of times and
// in any order on s:

//     Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back
//     to 0. For example, if s = "3456" and a = 5, s becomes "3951". Rotate s to
//     the right by b positions. For example, if s = "3456" and b = 1, s becomes
//     "6345".

// Return the lexicographically smallest string you can obtain by applying the
// above operations any number of times on s.

// A string a is lexicographically smaller than a string b (of the same length)
// if in the first position where a and b differ, string a has a letter that
// appears earlier in the alphabet than the corresponding letter in b. For
// example, "0158" is lexicographically smaller than "0190" because the first
// position they differ is at the third letter, and '5' comes before '9'.

// Example 1:

// Input: s = "5525", a = 9, b = 2
// Output: "2050"
// Explanation: We can apply the following operations:
// Start:  "5525"
// Rotate: "2555"
// Add:    "2454"
// Add:    "2353"
// Rotate: "5323"
// Add:    "5222"
// Add:    "5121"
// Rotate: "2151"
// Add:    "2050"​​​​​
// There is no way to obtain a string that is lexicographically smaller than
// "2050".

// Example 2:

// Input: s = "74", a = 5, b = 1
// Output: "24"
// Explanation: We can apply the following operations:
// Start:  "74"
// Rotate: "47"
// ​​​​​​​Add:    "42"
// ​​​​​​​Rotate: "24"​​​​​​​​​​​​
// There is no way to obtain a string that is lexicographically smaller than
// "24".

// Example 3:

// Input: s = "0011", a = 4, b = 2
// Output: "0011"
// Explanation: There are no sequence of operations that will give us a
// lexicographically smaller string than "0011".

// Constraints:

//     2 <= s.length <= 100
//     s.length is even.
//     s consists of digits from 0 to 9 only.
//     1 <= a <= 9
//     1 <= b <= s.length - 1

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::string findLexSmallestString(std::string s, int a, int b) {
        std::queue<std::string> q{{s}};
        std::unordered_set<std::string> visited{s};
        std::string result = s;

        while (!q.empty()) {
            std::string curr = q.front();
            q.pop();
            result = std::min(result, curr);

            std::string added = curr;
            for (size_t i = 1; i < added.size(); i += 2) {
                added[i] = (added[i] - '0' + a) % 10 + '0';
            }
            if (visited.insert(added).second) {
                q.push(added);
            }

            std::string rotated =
                curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
            if (visited.insert(rotated).second) {
                q.push(rotated);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::string, int, int>, std::string>>
        tests = {
            {{"5525", 9, 2}, "2050"},
            {{"74", 5, 1}, "24"},
            {{"0011", 4, 2}, "0011"},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findLexSmallestString(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
