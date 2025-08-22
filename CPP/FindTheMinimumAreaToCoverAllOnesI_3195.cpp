// 3195. Find the Minimum Area to Cover All Ones I
// Difficulty: Medium

// You are given a 2D binary array grid. Find a rectangle with horizontal and
// vertical sides with the smallest area, such that all the 1's in grid lie
// inside this rectangle.

// Return the minimum possible area of the rectangle.

// Example 1:

// Input: grid = [[0,1,0],[1,0,1]]

// Output: 6

// Explanation:

// The smallest rectangle has a height of 2 and a width of 3, so it has an area
// of 2 * 3 = 6.

// Example 2:

// Input: grid = [[1,0],[0,0]]

// Output: 1

// Explanation:

// The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

// Constraints:

// 1 <= grid.length, grid[i].length <= 1000
// grid[i][j] is either 0 or 1.
// The input is generated such that there is at least one 1 in grid.

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <vector>

class Solution {
  public:
    int minimumArea(std::vector<std::vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int mini = n, maxi = 0, minj = m, maxj = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    mini = std::min(mini, i);
                    maxi = std::max(maxi, i);
                    minj = std::min(minj, j);
                    maxj = std::max(maxj, j);
                }
            }
        }

        return (maxi - mini + 1) * (maxj - minj + 1);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{0, 1, 0}, {1, 0, 1}}, 6},
        {{{1, 0}, {0, 0}}, 1},
        {{{1, 1}}, 2},
        {{{0}, {1}}, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimumArea(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
