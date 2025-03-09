// 3208. Alternating Groups II
// Difficulty: Medium

// There is a circle of red and blue tiles. You are given an array of integers
// colors and an integer k. The color of tile i is represented by colors[i]:

//     colors[i] == 0 means that tile i is red.
//     colors[i] == 1 means that tile i is blue.

// An alternating group is every k contiguous tiles in the circle with
// alternating colors (each tile in the group except the first and last one has
// a different color from its left and right tiles).

// Return the number of alternating groups.

// Note that since colors represents a circle, the first and the last tiles are
// considered to be next to each other.

// Example 1:

// Input: colors = [0,1,0,1,0], k = 3

// Output: 3

// Explanation:

// Alternating groups:

// Example 2:

// Input: colors = [0,1,0,0,1,0,1], k = 6

// Output: 2

// Explanation:

// Alternating groups:

// Example 3:

// Input: colors = [1,1,0,1], k = 4

// Output: 0

// Explanation:

// Constraints:

//     3 <= colors.length <= 105
//     0 <= colors[i] <= 1
//     3 <= k <= colors.length

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int numberOfAlternatingGroups(std::vector<int> &colors, int k) {
        colors.insert(colors.end(), colors.begin(), colors.begin() + k - 1);
        int l = 0, r = 1;
        int result = 0;
        while (r < colors.size()) {
            if (colors[r] == colors[r - 1]) {
                l = r;
                r++;
                continue;
            }
            r++;
            if (r - l < k) {
                continue;
            }
            result++;
            l++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{0, 1, 0, 1, 0}, 3}, 3},
        {{{0, 1, 0, 0, 1, 0, 1}, 6}, 2},
        {{{1, 1, 0, 1}, 4}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.numberOfAlternatingGroups(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
