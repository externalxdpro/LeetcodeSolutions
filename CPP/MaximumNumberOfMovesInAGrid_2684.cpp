// 2684. Maximum Number of Moves in a Grid
// Difficulty: Medium

// You are given a 0-indexed m x n matrix grid consisting of positive integers.

// You can start at any cell in the first column of the matrix, and traverse the
// grid in the following way:

//     From a cell (row, col), you can move to any of the cells: (row - 1, col +
//     1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell
//     you move to, should be strictly bigger than the value of the current
//     cell.

// Return the maximum number of moves that you can perform.

// Example 1:

// Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
// Output: 3
// Explanation: We can start at the cell (0, 0) and make the following moves:
// - (0, 0) -> (0, 1).
// - (0, 1) -> (1, 2).
// - (1, 2) -> (2, 3).
// It can be shown that it is the maximum number of moves that can be made.

// Example 2:

// Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
// Output: 0
// Explanation: Starting from any cell in the first column we cannot perform any
// moves.

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     2 <= m, n <= 1000
//     4 <= m * n <= 105
//     1 <= grid[i][j] <= 106

#include <algorithm>
#include <fmt/ranges.h>
#include <functional>
#include <vector>

class Solution {
  public:
    int maxMoves(const std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<int>> dp(grid.size(),
                                         std::vector(grid[0].size(), -1));
        std::function<bool(int, int)> inBounds = [&](int i, int j) -> bool {
            return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
        };
        std::function<int(int, int)> recurse = [&](int i, int j) -> int {
            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            int result = 0;
            if (inBounds(i - 1, j + 1) && grid[i - 1][j + 1] > grid[i][j]) {
                result = std::max(result, recurse(i - 1, j + 1) + 1);
            }
            if (inBounds(i, j + 1) && grid[i][j + 1] > grid[i][j]) {
                result = std::max(result, recurse(i, j + 1) + 1);
            }
            if (inBounds(i + 1, j + 1) && grid[i + 1][j + 1] > grid[i][j]) {
                result = std::max(result, recurse(i + 1, j + 1) + 1);
            }
            return dp[i][j] = result;
        };

        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            result = std::max(result, recurse(i, 0));
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}}, 3},
        {{{3, 2, 4}, {2, 1, 9}, {1, 1, 7}}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxMoves(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
