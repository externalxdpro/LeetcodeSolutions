// 2503. Maximum Number of Points From Grid Queries
// Difficulty: Hard

// You are given an m x n integer matrix grid and an array queries of size k.

// Find an array answer of size k such that for each integer queries[i] you
// start in the top left cell of the matrix and repeat the following process:

//     If queries[i] is strictly greater than the value of the current cell that
//     you are in, then you get one point if it is your first time visiting this
//     cell, and you can move to any adjacent cell in all 4 directions: up,
//     down, left, and right. Otherwise, you do not get any points, and you end
//     this process.

// After the process, answer[i] is the maximum number of points you can get.
// Note that for each query you are allowed to visit the same cell multiple
// times.

// Return the resulting array answer.

// Example 1:

// Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
// Output: [5,8,1]
// Explanation: The diagrams above show which cells we visit to get points for
// each query.

// Example 2:

// Input: grid = [[5,2,1],[1,1,2]], queries = [3]
// Output: [0]
// Explanation: We can not get any points because the value of the top left cell
// is already greater than or equal to 3.

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     2 <= m, n <= 1000
//     4 <= m * n <= 105
//     k == queries.length
//     1 <= k <= 104
//     1 <= grid[i][j], queries[i] <= 106

#include <algorithm>
#include <array>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> maxPoints(std::vector<std::vector<int>> &grid,
                               std::vector<int>              &queries) {
        std::vector<std::pair<int, int>> qs(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            qs[i] = {i, queries[i]};
        }
        std::ranges::sort(qs,
                          [](auto &a, auto &b) { return a.second < b.second; });
        std::vector<int> result(queries.size());
        std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>,
                            std::greater<>>
                                       pq;
        std::vector<std::vector<bool>> visited(
            grid.size(), std::vector(grid[0].size(), false));
        int currPoints = 0;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        for (auto [qi, qval] : qs) {
            while (!pq.empty() && pq.top()[0] < qval) {
                auto [val, i, j] = pq.top();
                pq.pop();
                currPoints++;
                if (inBounds(grid, i + 1, j) && !visited[i + 1][j]) {
                    pq.push({grid[i + 1][j], i + 1, j});
                    visited[i + 1][j] = true;
                }
                if (inBounds(grid, i - 1, j) && !visited[i - 1][j]) {
                    pq.push({grid[i - 1][j], i - 1, j});
                    visited[i - 1][j] = true;
                }
                if (inBounds(grid, i, j + 1) && !visited[i][j + 1]) {
                    pq.push({grid[i][j + 1], i, j + 1});
                    visited[i][j + 1] = true;
                }
                if (inBounds(grid, i, j - 1) && !visited[i][j - 1]) {
                    pq.push({grid[i][j - 1], i, j - 1});
                    visited[i][j - 1] = true;
                }
            }
            result[qi] = currPoints;
        }
        return result;
    }

  private:
    bool inBounds(std::vector<std::vector<int>> &grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::vector<std::vector<int>>, std::vector<int>>,
                  std::vector<int>>>
        tests = {
            {{{{1, 2, 3}, {2, 5, 7}, {3, 5, 1}}, {5, 6, 2}}, {5, 8, 1}},
            {{{{5, 2, 1}, {1, 1, 2}}, {3}}, {0}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxPoints(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
