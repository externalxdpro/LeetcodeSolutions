// 3197. Find the Minimum Area to Cover All Ones II
// Difficulty: Hard

// You are given a 2D binary array grid. You need to find 3 non-overlapping
// rectangles having non-zero areas with horizontal and vertical sides such that
// all the 1's in grid lie inside these rectangles.

// Return the minimum possible sum of the area of these rectangles.

// Note that the rectangles are allowed to touch.

// Example 1:

// Input: grid = [[1,0,1],[1,1,1]]

// Output: 5

// Explanation:

// The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
// The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
// The 1 at (1, 1) is covered by a rectangle of area 1.
// Example 2:

// Input: grid = [[1,0,1,0],[0,1,0,1]]

// Output: 5

// Explanation:

// The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
// The 1 at (1, 1) is covered by a rectangle of area 1.
// The 1 at (1, 3) is covered by a rectangle of area 1.

// Constraints:

// 1 <= grid.length, grid[i].length <= 30
// grid[i][j] is either 0 or 1.
// The input is generated such that there are at least three 1's in grid.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minimumSum(std::vector<std::vector<int>> &grid) {
        return std::min(totalArea(grid), totalArea(rotate(grid)));
    }

  private:
    std::vector<std::vector<int>>
    rotate(const std::vector<std::vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<int>> result(m, std::vector(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[m - j - 1][i] = grid[i][j];
            }
        }
        return result;
    }

    int minArea(const std::vector<std::vector<int>> &grid, int u, int d, int l,
                int r) {
        int n = grid.size(), m = grid[0].size();
        int mini = n, maxi = 0, minj = m, maxj = 0;
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    mini = std::min(mini, i);
                    maxi = std::max(maxi, i);
                    minj = std::min(minj, j);
                    maxj = std::max(maxj, j);
                }
            }
        }
        return mini != n ? (maxi - mini + 1) * (maxj - minj + 1) : INT_MAX / 3;
    }

    int totalArea(const std::vector<std::vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int result = n * m;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int type1 = minArea(grid, 0, i, 0, m - 1) +
                            minArea(grid, i + 1, n - 1, 0, j) +
                            minArea(grid, i + 1, n - 1, j + 1, m - 1);
                int type2 = minArea(grid, 0, i, 0, j) +
                            minArea(grid, 0, i, j + 1, m - 1) +
                            minArea(grid, i + 1, n - 1, 0, m - 1);
                result = std::min({result, type1, type2});
            }
        }
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int type3 = minArea(grid, 0, i, 0, m - 1) +
                            minArea(grid, i + 1, j, 0, m - 1) +
                            minArea(grid, j + 1, n - 1, 0, m - 1);
                result = std::min(result, type3);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 0, 1}, {1, 1, 1}}, 5},
        {{{1, 0, 1, 0}, {0, 1, 0, 1}}, 5},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimumSum(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
