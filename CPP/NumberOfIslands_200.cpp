// [200] Number of Islands
// Medium

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and
// '0's (water), return the number of islands. An island is surrounded by water
// and is formed by connecting adjacent lands horizontally or vertically. You
// may assume all four edges of the grid are all surrounded by water.

// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// Constraints:
//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 300
//     grid[i][j] is '0' or '1'.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }

  private:
    bool inside(std::vector<std::vector<char>> &grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    void dfs(std::vector<std::vector<char>> &grid, int i, int j) {
        if (!inside(grid, i, j) || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = ' ';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<char>>, int>> tests = {
        {{{'1', '1', '1', '1', '0'},
          {'1', '1', '0', '1', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '0', '0', '0'}},
         1},
        {{{'1', '1', '0', '0', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '1', '0', '0'},
          {'0', '0', '0', '1', '1'}},
         3},
        {{{'1', '1'}}, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numIslands(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
