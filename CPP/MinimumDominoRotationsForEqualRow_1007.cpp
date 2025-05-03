// 1007. Minimum Domino Rotations For Equal Row
// Difficulty: Medium

// In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom
// halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 -
// one on each half of the tile.)

// We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

// Return the minimum number of rotations so that all the values in tops are the
// same, or all the values in bottoms are the same.

// If it cannot be done, return -1.

// Example 1:

// Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// Output: 2
// Explanation:
// The first figure represents the dominoes as given by tops and bottoms: before
// we do any rotations. If we rotate the second and fourth dominoes, we can make
// every value in the top row equal to 2, as indicated by the second figure.

// Example 2:

// Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
// Output: -1
// Explanation:
// In this case, it is not possible to rotate the dominoes to make one row of
// values equal.

// Constraints:

//     2 <= tops.length <= 2 * 104
//     bottoms.length == tops.length
//     1 <= tops[i], bottoms[i] <= 6

#include <algorithm>
#include <fmt/ranges.h>
#include <optional>
#include <vector>

class Solution {
  public:
    int minDominoRotations(std::vector<int> &tops, std::vector<int> &bottoms) {
        if (tops.size() != bottoms.size()) {
            return -1;
        }
        int topCounts[7] = {0}, bottomCounts[7] = {0}, sameCounts[7] = {0};
        for (int i = 0; i < tops.size(); i++) {
            topCounts[tops[i]]++;
            bottomCounts[bottoms[i]]++;
            sameCounts[tops[i]] += tops[i] == bottoms[i];
        }
        std::optional<int> result = std::nullopt;
        for (int n = 1; n <= 6; n++) {
            if (topCounts[n] + bottomCounts[n] - sameCounts[n] == tops.size()) {
                result = std::min({result.value_or(1000000),
                                   (int)tops.size() - topCounts[n],
                                   (int)tops.size() - bottomCounts[n]});
            }
        }
        return result.value_or(-1);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, std::vector<int>>, int>>
        tests = {
            {{{2, 1, 2, 4, 2, 2}, {5, 2, 6, 2, 3, 2}}, 2},
            {{{3, 5, 1, 2, 3}, {3, 6, 3, 3, 4}}, -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minDominoRotations(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
