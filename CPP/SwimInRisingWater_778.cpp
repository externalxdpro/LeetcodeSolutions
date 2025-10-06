// 778. Swim in Rising Water
// Difficulty: Hard

// You are given an n x n integer matrix grid where each value grid[i][j]
// represents the elevation at that point (i, j).

// It starts raining, and water gradually rises over time. At time t, the water
// level is t, meaning any cell with elevation less than equal to t is submerged
// or reachable.

// You can swim from a square to another 4-directionally adjacent square if and
// only if the elevation of both squares individually are at most t. You can
// swim infinite distances in zero time. Of course, you must stay within the
// boundaries of the grid during your swim.

// Return the minimum time until you can reach the bottom right square (n - 1, n
// - 1) if you start at the top left square (0, 0).

// Example 1:

// Input: grid = [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a
// higher elevation than t = 0. You cannot reach point (1, 1) until time 3. When
// the depth of water is 3, we can swim anywhere inside the grid.

// Example 2:

// Input: grid =
// [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation: The final route is shown.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

// Constraints:

//     n == grid.length
//     n == grid[i].length
//     1 <= n <= 50
//     0 <= grid[i][j] < n2
//     Each value grid[i][j] is unique.

#include <fmt/ranges.h>
#include <vector>

class Solution {
    const std::pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  public:
    int swimInWater(std::vector<std::vector<int>> &grid) {
        int n = grid.size();
        int result = INT_MAX;
        int l = 0, r = n * n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            std::vector<std::vector<bool>> visited(n, std::vector(n, false));
            if (grid[0][0] <= m && dfs(grid, 0, 0, m, visited)) {
                result = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return result;
    }

    bool dfs(std::vector<std::vector<int>> &grid, int i, int j, int t,
             std::vector<std::vector<bool>> &visited) {
        int n = grid.size();
        visited[i][j] = true;
        if (i == n - 1 && j == n - 1) {
            return true;
        }

        for (auto &d : dirs) {
            int di = i + d.first, dj = j + d.second;
            if (di >= 0 && di < n && dj >= 0 && dj < n && !visited[di][dj] &&
                grid[di][dj] <= t) {
                if (dfs(grid, di, dj, t, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{0, 2}, {1, 3}}, 3},
        {{{0, 1, 2, 3, 4},
          {24, 23, 22, 21, 5},
          {12, 13, 14, 15, 16},
          {11, 17, 18, 19, 20},
          {10, 9, 8, 7, 6}},
         16},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.swimInWater(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
