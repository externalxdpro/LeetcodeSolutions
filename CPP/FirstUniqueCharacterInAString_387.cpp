// Difficulty: Easy
// Given a string s, find the first non-repeating character in it and return its
// index. If it does not exist, return -1.

// Example 1:
// Input: s = "leetcode"
// Output: 0

// Example 2:
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// Input: s = "aabb"
// Output: -1

// Constraints:
//     1 <= s.length <= 10^5
//     s consists of only lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> map;
        for (char i : s) {
            map[i]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"leetcode", 0},
        {"loveleetcode", 2},
        {"aabb", -1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.firstUniqChar(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
