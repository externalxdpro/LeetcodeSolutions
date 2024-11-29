// 2577. Minimum Time to Visit a Cell In a Grid
// Difficulty: Hard

// You are given a m x n matrix grid consisting of non-negative integers where
// grid[row][col] represents the minimum time required to be able to visit the
// cell (row, col), which means you can visit the cell (row, col) only when the
// time you visit it is greater than or equal to grid[row][col].

// You are standing in the top-left cell of the matrix in the 0th second, and
// you must move to any adjacent cell in the four directions: up, down, left,
// and right. Each move you make takes 1 second.

// Return the minimum time required in which you can visit the bottom-right cell
// of the matrix. If you cannot visit the bottom-right cell, then return -1.

// Example 1:

// Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
// Output: 7
// Explanation: One of the paths that we can take is the following:
// - at t = 0, we are on the cell (0,0).
// - at t = 1, we move to the cell (0,1). It is possible because grid[0][1]
// <= 1.
// - at t = 2, we move to the cell (1,1). It is possible because grid[1][1]
// <= 2.
// - at t = 3, we move to the cell (1,2). It is possible because grid[1][2]
// <= 3.
// - at t = 4, we move to the cell (1,1). It is possible because grid[1][1]
// <= 4.
// - at t = 5, we move to the cell (1,2). It is possible because grid[1][2]
// <= 5.
// - at t = 6, we move to the cell (1,3). It is possible because grid[1][3]
// <= 6.
// - at t = 7, we move to the cell (2,3). It is possible because grid[2][3]
// <= 7. The final time is 7. It can be shown that it is the minimum time
// possible.

// Example 2:

// Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
// Output: -1
// Explanation: There is no path from the top left to the bottom-right cell.

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     2 <= m, n <= 1000
//     4 <= m * n <= 105
//     0 <= grid[i][j] <= 105
//     grid[0][0] == 0

#include <algorithm>
#include <array>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int minimumTime(const std::vector<std::vector<int>> &grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        const std::pair<int, int> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::vector<std::vector<bool>> visited(
            grid.size(), std::vector(grid[0].size(), false));

        std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>,
                            std::greater<>>
            pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if (i == grid.size() - 1 && j == grid[0].size() - 1) {
                return t;
            }
            if (visited[i][j]) {
                continue;
            }
            visited[i][j] = true;

            for (const auto &[dirI, dirJ] : dirs) {
                int nextI = i + dirI, nextJ = j + dirJ;
                if (!isValid(grid, nextI, nextJ)) {
                    continue;
                }

                int wait  = (grid[nextI][nextJ] - t) % 2 == 0;
                int nextT = std::max(grid[nextI][nextJ] + wait, t + 1);
                pq.push({nextT, nextI, nextJ});
            }
        }
        return -1;
    }

  private:
    bool isValid(const std::vector<std::vector<int>> &grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}}, 7},
        {{{0, 2, 4}, {3, 2, 1}, {1, 0, 4}}, -1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimumTime(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
