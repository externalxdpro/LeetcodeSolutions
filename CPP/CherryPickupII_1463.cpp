// Difficulty: Hard
// You are given a rows x cols matrix grid representing a field of cherries
// where grid[i][j] represents the number of cherries that you can collect from
// the (i, j) cell.
// You have two robots that can collect cherries for you:
//     Robot #1 is located at the top-left corner (0, 0), and
//     Robot #2 is located at the top-right corner (0, cols - 1).

// Return the maximum number of cherries collection using both robots by
// following the rules below:
//     From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j),
//     or (i + 1, j + 1). When any robot passes through a cell, It picks up all
//     cherries, and the cell becomes an empty cell. When both robots stay in
//     the same cell, only one takes the cherries. Both robots cannot move
//     outside of the grid at any moment. Both robots should reach the bottom
//     row in grid.

// Example 1:
// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue
// respectively. Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12. Cherries
// taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of cherries: 12 + 12 = 24.

// Example 2:
// Input: grid =
// [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
// Output: 28
// Explanation: Path of robot #1 and #2 are described in color green and blue
// respectively. Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17. Cherries
// taken by Robot #2, (1 + 3 + 4 + 3) = 11. Total of cherries: 17 + 11 = 28.

// Constraints:
//     rows == grid.length
//     cols == grid[i].length
//     2 <= rows, cols <= 70
//     0 <= grid[i][j] <= 100

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int cherryPickup(std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<std::vector<int>>> memo(
            grid.size(),
            std::vector(grid[0].size(), std::vector(grid[0].size(), -1)));
        return dp(grid, 0, 0, grid[0].size() - 1, memo);
    }

  private:
    int dp(std::vector<std::vector<int>> &grid, int currRow, int col1, int col2,
           std::vector<std::vector<std::vector<int>>> &memo) {
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 ||
            col2 >= grid[0].size()) {
            return 0;
        }
        if (currRow >= grid.size()) {
            return 0;
        }

        if (memo[currRow][col1][col2] != -1) {
            return memo[currRow][col1][col2];
        }

        int result = grid[currRow][col1] + grid[currRow][col2];

        int max = 0;
        for (int l = col1 - 1; l <= col1 + 1; l++) {
            for (int r = col2 - 1; r <= col2 + 1; r++) {
                if (l < r) {
                    max = std::max(max, dp(grid, currRow + 1, l, r, memo));
                }
            }
        }

        result += max;
        memo[currRow][col1][col2] = result;
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}}, 24},
        {{{1, 0, 0, 0, 0, 0, 1},
          {2, 0, 0, 0, 0, 3, 0},
          {2, 0, 9, 0, 0, 0, 0},
          {0, 3, 0, 5, 4, 0, 0},
          {1, 0, 2, 3, 0, 0, 6}},
         28},
        {{{10, 0, 10, 4, 3, 3, 0},
          {4, 10, 1, 6, 7, 8, 3},
          {4, 3, 9, 9, 3, 10, 7},
          {6, 9, 8, 2, 8, 3, 10},
          {4, 7, 2, 5, 2, 1, 0},
          {1, 1, 6, 8, 4, 1, 8},
          {10, 3, 3, 6, 5, 1, 0},
          {10, 10, 1, 8, 1, 6, 8},
          {7, 8, 3, 6, 9, 6, 7}},
         136},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.cherryPickup(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
