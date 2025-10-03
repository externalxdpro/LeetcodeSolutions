// 407. Trapping Rain Water II
// Difficulty: Hard

// Given an m x n integer matrix heightMap representing the height of each unit
// cell in a 2D elevation map, return the volume of water it can trap after
// raining.

// Example 1:

// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.

// Example 2:

// Input: heightMap =
// [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]] Output: 10

// Constraints:

//     m == heightMap.length
//     n == heightMap[i].length
//     1 <= m, n <= 200
//     0 <= heightMap[i][j] <= 2 * 104

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int trapRainWater(std::vector<std::vector<int>> &heightMap) {
        const std::pair<int, int> dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int m = heightMap.size(), n = heightMap[0].size();
        std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,
                            std::greater<>>
            bounds;

        std::vector<std::vector<bool>> visited(m, std::vector(n, false));

        for (int i = 0; i < m; i++) {
            bounds.emplace(heightMap[i][0], i, 0);
            bounds.emplace(heightMap[i][n - 1], i, n - 1);
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            bounds.emplace(heightMap[0][j], 0, j);
            bounds.emplace(heightMap[m - 1][j], m - 1, j);
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int result = 0;
        while (!bounds.empty()) {
            auto [h, i, j] = bounds.top();
            bounds.pop();

            for (int d = 0; d < 4; d++) {
                std::pair dir = dirs[d];
                int di = i + dir.first, dj = j + dir.second;
                if (!inBounds(heightMap, di, dj) || visited[di][dj]) {
                    continue;
                }
                int dh = heightMap[di][dj];
                if (dh < h) {
                    result += h - dh;
                }
                bounds.emplace(std::max(h, dh), di, dj);
                visited[di][dj] = true;
            }
        }

        return result;
    }

  private:
    bool inBounds(std::vector<std::vector<int>> &grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}}, 4},
        {{{3, 3, 3, 3, 3},
          {3, 2, 2, 2, 3},
          {3, 2, 1, 2, 3},
          {3, 2, 2, 2, 3},
          {3, 3, 3, 3, 3}},
         10},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.trapRainWater(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
