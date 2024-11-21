// 2257. Count Unguarded Cells in the Grid
// Difficulty: Medium

// You are given two integers m and n representing a 0-indexed m x n grid. You
// are also given two 2D integer arrays guards and walls where guards[i] =
// [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith
// guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east,
// south, or west) starting from their position unless obstructed by a wall or
// another guard. A cell is guarded if there is at least one guard that can see
// it.

// Return the number of unoccupied cells that are not guarded.

// Example 1:

// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls =
// [[0,1],[2,2],[1,4]] Output: 7 Explanation: The guarded and unguarded cells
// are shown in red and green respectively in the above diagram. There are a
// total of 7 unguarded cells, so we return 7.

// Example 2:

// Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
// Output: 4
// Explanation: The unguarded cells are shown in green in the above diagram.
// There are a total of 4 unguarded cells, so we return 4.

// Constraints:

//     1 <= m, n <= 105
//     2 <= m * n <= 105
//     1 <= guards.length, walls.length <= 5 * 104
//     2 <= guards.length + walls.length <= m * n
//     guards[i].length == walls[j].length == 2
//     0 <= rowi, rowj < m
//     0 <= coli, colj < n
//     All the positions in guards and walls are unique.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int countUnguarded(int m, int n,
                       const std::vector<std::vector<int>> &guards,
                       const std::vector<std::vector<int>> &walls) {
        std::vector<std::vector<int>> grid(m, std::vector(n, 0));

        for (const auto &w : walls) {
            grid[w[0]][w[1]] = 2;
        }
        for (const auto &g : guards) {
            grid[g[0]][g[1]] = 2;
        }
        for (const auto &g : guards) {
            int gi = g[0], gj = g[1];
            for (int i = gi + 1; i < m; i++) {
                if (grid[i][gj] == 2) {
                    break;
                }
                grid[i][gj] = 1;
            }
            for (int i = gi - 1; i >= 0; i--) {
                if (grid[i][gj] == 2) {
                    break;
                }
                grid[i][gj] = 1;
            }
            for (int j = gj + 1; j < n; j++) {
                if (grid[gi][j] == 2) {
                    break;
                }
                grid[gi][j] = 1;
            }
            for (int j = gj - 1; j >= 0; j--) {
                if (grid[gi][j] == 2) {
                    break;
                }
                grid[gi][j] = 1;
            }
        }

        int count = 0;
        for (const auto &r : grid) {
            for (const auto &c : r) {
                if (c == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<int, int, std::vector<std::vector<int>>,
                                     std::vector<std::vector<int>>>,
                          int>>
        tests = {
            {{4, 6, {{0, 0}, {1, 1}, {2, 3}}, {{0, 1}, {2, 2}, {1, 4}}}, 7},
            {{3, 3, {{1, 1}}, {{0, 1}, {1, 0}, {2, 1}, {1, 2}}}, 4},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.countUnguarded(std::get<0>(test), std::get<1>(test),
                                    std::get<2>(test), std::get<3>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
