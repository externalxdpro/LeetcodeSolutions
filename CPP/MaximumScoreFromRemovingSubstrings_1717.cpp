// 1717. Maximum Score From Removing Substrings
// Difficulty: Medium

// You are given a string s and two integers x and y. You can perform two types
// of operations any number of times.
//     Remove substring "ab" and gain x points.
//         For example, when removing "ab" from "cabxbae" it becomes "cxbae".
//     Remove substring "ba" and gain y points.
//         For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on
// s.

// Example 1:
// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5
// points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4
// points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points
// are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are
// added to the score. Total score = 5 + 4 + 5 + 5 = 19.

// Example 2:
// Input: s = "aabbaaxybbaabb", x = 5, y = 4
// Output: 20

// Constraints:
//     1 <= s.length <= 10^5
//     1 <= x, y <= 10^4
//     s consists of lowercase English letters.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maximumGain(std::string s, int x, int y) {
        int pos, score = 0;

        while (true) {
            bool greater = true;
            int  pos     = x > y ? s.find("ab") : s.find("ba");
            if (pos == std::string::npos) {
                pos     = x < y ? s.find("ab") : s.find("ba");
                greater = false;
                if (pos == std::string::npos) {
                    break;
                }
            }

            s.erase(pos, 2);
            score += greater ? std::max(x, y) : std::min(x, y);
        }

        return score;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::string, int, int>, int>> tests = {
        {{"cdbcbbaaabab", 4, 5}, 19},
        {{"aabbaaxybbaabb", 5, 4}, 20},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumGain(std::get<0>(test), std::get<1>(test),
                                           std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
