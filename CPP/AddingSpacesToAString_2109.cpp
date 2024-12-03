// 2109. Adding Spaces to a String
// Difficulty: Medium

// You are given a 0-indexed string s and a 0-indexed integer array spaces that
// describes the indices in the original string where spaces will be added. Each
// space should be inserted before the character at the given index.

//     For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place
//     spaces before 'Y' and 'C', which are at indices 5 and 9 respectively.
//     Thus, we obtain "Enjoy Your Coffee".

// Return the modified string after the spaces have been added.

// Example 1:

// Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
// Output: "Leetcode Helps Me Learn"
// Explanation:
// The indices 8, 13, and 15 correspond to the underlined characters in
// "LeetcodeHelpsMeLearn". We then place spaces before those characters.

// Example 2:

// Input: s = "icodeinpython", spaces = [1,5,7,9]
// Output: "i code in py thon"
// Explanation:
// The indices 1, 5, 7, and 9 correspond to the underlined characters in
// "icodeinpython". We then place spaces before those characters.

// Example 3:

// Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
// Output: " s p a c i n g"
// Explanation:
// We are also able to place spaces before the first character of the string.

// Constraints:

//     1 <= s.length <= 3 * 105
//     s consists only of lowercase and uppercase English letters.
//     1 <= spaces.length <= 3 * 105
//     0 <= spaces[i] <= s.length - 1
//     All the values of spaces are strictly increasing.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string addSpaces(const std::string      &s,
                          const std::vector<int> &spaces) {
        std::string result(s.size() + spaces.size(), ' ');
        int         sI = 0, spacesI = 0;
        for (int i = 0; i < result.size(); i++) {
            if (spacesI < spaces.size() && sI == spaces[spacesI]) {
                spacesI++;
                continue;
            }
            result[i] = s[sI];
            sI++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::string, std::vector<int>>, std::string>>
        tests = {
            {{"LeetcodeHelpsMeLearn", {8, 13, 15}}, "Leetcode Helps Me Learn"},
            {{"icodeinpython", {1, 5, 7, 9}}, "i code in py thon"},
            {{"spacing", {0, 1, 2, 3, 4, 5, 6}}, " s p a c i n g"},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.addSpaces(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
