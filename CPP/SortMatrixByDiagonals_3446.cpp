// 3446. Sort Matrix by Diagonals
// Difficulty: Medium

// You are given an n x n square matrix of integers grid. Return the matrix such
// that:

//     The diagonals in the bottom-left triangle (including the middle diagonal)
//     are sorted in non-increasing order. The diagonals in the top-right
//     triangle are sorted in non-decreasing order.

// Example 1:

// Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

// Output: [[8,2,3],[9,6,7],[4,5,1]]

// Explanation:

// The diagonals with a black arrow (bottom-left triangle) should be sorted in
// non-increasing order:

//     [1, 8, 6] becomes [8, 6, 1].
//     [9, 5] and [4] remain unchanged.

// The diagonals with a blue arrow (top-right triangle) should be sorted in
// non-decreasing order:

//     [7, 2] becomes [2, 7].
//     [3] remains unchanged.

// Example 2:

// Input: grid = [[0,1],[1,2]]

// Output: [[2,1],[1,0]]

// Explanation:

// The diagonals with a black arrow must be non-increasing, so [0, 2] is changed
// to [2, 0]. The other diagonals are already in the correct order.

// Example 3:

// Input: grid = [[1]]

// Output: [[1]]

// Explanation:

// Diagonals with exactly one element are already in order, so no changes are
// needed.

// Constraints:

//     grid.length == grid[i].length == n
//     1 <= n <= 10
//     -105 <= grid[i][j] <= 105

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    sortMatrix(std::vector<std::vector<int>> &grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            std::vector<int> curr;
            for (int j = 0; i + j < n; j++) {
                curr.push_back(grid[i + j][j]);
            }
            std::ranges::sort(curr, [](int a, int b) { return a > b; });
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = curr[j];
            }
        }

        for (int j = 1; j < n; j++) {
            std::vector<int> curr;
            for (int i = 0; i + j < n; i++) {
                curr.push_back(grid[i][i + j]);
            }
            std::ranges::sort(curr);
            for (int i = 0; i + j < n; i++) {
                grid[i][i + j] = curr[i];
            }
        }

        return grid;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>>
        tests = {
            {{{1, 7, 3}, {9, 8, 2}, {4, 5, 6}},
             {{8, 2, 3}, {9, 6, 7}, {4, 5, 1}}},
            {{{0, 1}, {1, 2}}, {{2, 1}, {1, 0}}},
            {{{1}}, {{1}}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.sortMatrix(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
