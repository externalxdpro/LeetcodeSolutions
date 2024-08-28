// 1905. Count Sub Islands
// Difficulty: Medium

// You are given two m x n binary matrices grid1 and grid2 containing only 0's
// (representing water) and 1's (representing land). An island is a group of 1's
// connected 4-directionally (horizontal or vertical). Any cells outside of the
// grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1
// that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.

// Example 1:
// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
// grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]] Output:
// 3 Explanation: In the picture above, the grid on the left is grid1 and the
// grid on the right is grid2. The 1s colored red in grid2 are those considered
// to be part of a sub-island. There are three sub-islands.

// Example 2:
// Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]],
// grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]] Output:
// 2 Explanation: In the picture above, the grid on the left is grid1 and the
// grid on the right is grid2. The 1s colored red in grid2 are those considered
// to be part of a sub-island. There are two sub-islands.

// Constraints:
//     m == grid1.length == grid2.length
//     n == grid1[i].length == grid2[i].length
//     1 <= m, n <= 500
//     grid1[i][j] and grid2[i][j] are either 0 or 1.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int countSubIslands(std::vector<std::vector<int>> &grid1,
                        std::vector<std::vector<int>> &grid2) {
        int result = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    bool isSub = true;
                    traverse(grid1, grid2, i, j, isSub);
                    result += isSub;
                }
            }
        }
        return result;
    }

  private:
    void traverse(std::vector<std::vector<int>> &grid1,
                  std::vector<std::vector<int>> &grid2, int i, int j,
                  bool &isSub) {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() ||
            grid2[i][j] != 1) {
            return;
        }
        if (grid1[i][j] != grid2[i][j]) {
            isSub = false;
        }

        grid2[i][j] = 0;
        traverse(grid1, grid2, i + 1, j, isSub);
        traverse(grid1, grid2, i - 1, j, isSub);
        traverse(grid1, grid2, i, j + 1, isSub);
        traverse(grid1, grid2, i, j - 1, isSub);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>,
        int>>
        tests = {{{{{1, 1, 1, 0, 0},
                    {0, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 1, 0, 1, 1}},
                   {{1, 1, 1, 0, 0},
                    {0, 0, 1, 1, 1},
                    {0, 1, 0, 0, 0},
                    {1, 0, 1, 1, 0},
                    {0, 1, 0, 1, 0}}},
                  3},
                 {{{{1, 0, 1, 0, 1},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1},
                    {1, 0, 1, 0, 1}},
                   {{0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1},
                    {0, 1, 0, 1, 0},
                    {0, 1, 0, 1, 0},
                    {1, 0, 0, 0, 1}}},
                  2}};

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countSubIslands(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
