// 417. Pacific Atlantic Water Flow
// Difficulty: Medium

// There is an m x n rectangular island that borders both the Pacific Ocean and
// Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
// and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n
// integer matrix heights where heights[r][c] represents the height above sea
// level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring
// cells directly north, south, east, and west if the neighboring cell's height
// is less than or equal to the current cell's height. Water can flow from any
// cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci]
// denotes that rain water can flow from cell (ri, ci) to both the Pacific and
// Atlantic oceans.

// Example 1:

// Input: heights =
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]] Output:
// [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]] Explanation: The following cells
// can flow to the Pacific and Atlantic oceans, as shown below: [0,4]: [0,4] ->
// Pacific Ocean
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the
// Pacific and Atlantic oceans.

// Example 2:

// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and
// Atlantic oceans.

// Constraints:

//     m == heights.length
//     n == heights[r].length
//     1 <= m, n <= 200
//     0 <= heights[r][c] <= 105

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    const std::pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;

  public:
    std::vector<std::vector<int>>
    pacificAtlantic(std::vector<std::vector<int>> &heights) {
        m = heights.size(), n = heights[0].size();
        std::vector<std::vector<int>> result;

        std::vector<std::vector<bool>> vis1(m, std::vector(n, false));
        std::vector<std::vector<bool>> vis2(m, std::vector(n, false));
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, vis1);
            dfs(heights, i, n - 1, vis2);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, vis1);
            dfs(heights, m - 1, j, vis2);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

  private:
    void dfs(std::vector<std::vector<int>> &heights, int i, int j,
             std::vector<std::vector<bool>> &visited) {
        visited[i][j] = true;
        for (auto &d : dirs) {
            int di = i + d.first, dj = j + d.second;
            if (di >= 0 && dj >= 0 && di < m && dj < n &&
                heights[di][dj] >= heights[i][j] && !visited[di][dj]) {
                dfs(heights, di, dj, visited);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>>
        tests = {
            {{{1, 2, 2, 3, 5},
              {3, 2, 3, 4, 4},
              {2, 4, 5, 3, 1},
              {6, 7, 1, 4, 5},
              {5, 1, 1, 2, 4}},
             {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}}},
            {{{1}}, {{0, 0}}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.pacificAtlantic(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
