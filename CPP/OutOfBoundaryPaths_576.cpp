// Difficulty: Medium
// There is an m x n grid with a ball. The ball is initially at the position
// [startRow, startColumn]. You are allowed to move the ball to one of the four
// adjacent cells in the grid (possibly out of the grid crossing the grid
// boundary). You can apply at most maxMove moves to the ball.

// Given the five integers m, n, maxMove, startRow, startColumn, return the
// number of paths to move the ball out of the grid boundary. Since the answer
// can be very large, return it modulo 109 + 7.

// Example 1:
// Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// Output: 6

// Example 2:
// Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
// Output: 12

// Constraints:
//     1 <= m, n <= 50
//     0 <= maxMove <= 50
//     0 <= startRow < m
//     0 <= startColumn < n

#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <numeric>
#include <vector>

class Solution {
  public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        std::vector<std::vector<std::vector<int>>> memo(
            m, std::vector(n, std::vector(maxMove + 1, -1)));
        return recurse(m, n, maxMove, startRow, startColumn, memo);
    }

  private:
    int recurse(int m, int n, int move, int currRow, int currCol,
                std::vector<std::vector<std::vector<int>>> &memo) {
        if (currRow == m || currRow == -1 || currCol == n || currCol == -1) {
            return 1L;
        }
        if (move == 0) {
            return 0L;
        }

        const long MOD = 1'000'000'007;

        if (memo[currRow][currCol][move] >= 0) {
            return memo[currRow][currCol][move];
        }

        memo[currRow][currCol][move] =
            ((recurse(m, n, move - 1, currRow + 1, currCol, memo) % MOD) +
             (recurse(m, n, move - 1, currRow - 1, currCol, memo) % MOD) +
             (recurse(m, n, move - 1, currRow, currCol + 1, memo) % MOD) +
             (recurse(m, n, move - 1, currRow, currCol - 1, memo) % MOD)) %
            MOD;

        return memo[currRow][currCol][move];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> tests = {
        {2, 2, 2, 0, 0},
        {1, 3, 3, 0, 1},
        {8, 6, 10, 4, 3},
    };

    Solution solution;
    for (auto &test : tests) {
        auto result =
            solution.findPaths(test[0], test[1], test[2], test[3], test[4]);
        fmt::print("{}: {}\n", test, result);
    }

    return 0;
}
