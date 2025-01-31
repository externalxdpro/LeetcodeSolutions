// 827. Making A Large Island
// Difficulty: Hard

// You are given an n x n binary matrix grid. You are allowed to change at most
// one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with
// area = 3.

// Example 2:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island
// with area = 4.

// Example 3:

// Input: grid = [[1,1],[1,1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.

// Constraints:

//     n == grid.length
//     n == grid[i].length
//     1 <= n <= 500
//     grid[i][j] is either 0 or 1.

#include <algorithm>
#include <fmt/ranges.h>
#include <set>
#include <vector>

class Solution {
  public:
    int largestIsland(std::vector<std::vector<int>> &grid) {
        int                 n       = grid.size();
        std::pair<int, int> DIRS[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        std::vector<std::vector<std::pair<int, int>>> sizes(
            n, std::vector(n, std::pair(-1, -1)));

        int id = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1 || sizes[i][j].first != -1) {
                    continue;
                }
                std::set<std::pair<int, int>> visited;
                int currSize = size(grid, i, j, visited);
                for (auto [i, j] : visited) {
                    sizes[i][j] = {id, currSize};
                }
                id++;
            }
        }

        int result = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    std::vector<int> ids;
                    int              newSize = 1;
                    for (auto [di, dj] : DIRS) {
                        int ni = i + di, nj = j + dj;
                        if (isValid(grid, ni, nj) &&
                            std::find(ids.begin(), ids.end(),
                                      sizes[ni][nj].first) == ids.end()) {
                            newSize += sizes[ni][nj].second;
                            ids.push_back(sizes[ni][nj].first);
                        }
                    }
                    result = std::max(result, newSize);
                }
            }
        }

        if (result == -1) {
            return n * n;
        }
        return result;
    }

  private:
    int size(std::vector<std::vector<int>> &grid, int i, int j,
             std::set<std::pair<int, int>> &visited) {
        if (!isValid(grid, i, j)) {
            return 0;
        }
        if (visited.contains({i, j})) {
            return 0;
        }
        visited.emplace(i, j);

        int sum = 1;
        sum += size(grid, i - 1, j, visited);
        sum += size(grid, i, j - 1, visited);
        sum += size(grid, i + 1, j, visited);
        sum += size(grid, i, j + 1, visited);
        return sum;
    }

    bool isValid(std::vector<std::vector<int>> &grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
               grid[i][j] == 1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 0}, {0, 1}}, 3},
        {{{1, 1}, {1, 0}}, 4},
        {{{1, 1}, {1, 1}}, 4},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.largestIsland(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
