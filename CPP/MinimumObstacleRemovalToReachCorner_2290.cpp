// 2290. Minimum Obstacle Removal to Reach Corner
// Difficulty: Hard

// You are given a 0-indexed 2D integer array grid of size m x n. Each cell has
// one of two values:

//     0 represents an empty cell,
//     1 represents an obstacle that may be removed.

// You can move up, down, left, or right from and to an empty cell.

// Return the minimum number of obstacles to remove so you can move from the
// upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

// Example 1:

// Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
// Output: 2
// Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a
// path from (0, 0) to (2, 2). It can be shown that we need to remove at least 2
// obstacles, so we return 2. Note that there may be other ways to remove 2
// obstacles to create a path.

// Example 2:

// Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
// Output: 0
// Explanation: We can move from (0, 0) to (2, 4) without removing any
// obstacles, so we return 0.

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 105
//     2 <= m * n <= 105
//     grid[i][j] is either 0 or 1.
//     grid[0][0] == grid[m - 1][n - 1] == 0

#include <algorithm>
#include <array>
#include <fmt/ranges.h>
#include <limits>
#include <queue>
#include <vector>

class Solution {
  public:
    int minimumObstacles(const std::vector<std::vector<int>> &grid) {
        const std::pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::vector<std::vector<int>> result(
            grid.size(),
            std::vector(grid[0].size(), std::numeric_limits<int>::max()));
        result[0][0] = grid[0][0];
        std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>,
                            std::greater<>>
            pq;
        pq.push({result[0][0], 0, 0});

        while (!pq.empty()) {
            const auto [obs, i, j] = pq.top();
            pq.pop();

            if (i == grid.size() && j == grid[0].size()) {
                return obs;
            }

            for (const auto &[dirI, dirJ] : dirs) {
                int newI = i + dirI, newJ = j + dirJ;

                if (isValid(grid, newI, newJ)) {
                    int newObs = obs + grid[newI][newJ];
                    if (newObs < result[newI][newJ]) {
                        result[newI][newJ] = newObs;
                        pq.push({newObs, newI, newJ});
                    }
                }
            }
        }

        return result.back().back();
    }

  private:
    bool isValid(const std::vector<std::vector<int>> &grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{0, 1, 1}, {1, 1, 0}, {1, 1, 0}}, 2},
        {{{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimumObstacles(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
