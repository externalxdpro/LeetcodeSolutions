// 73. Set Matrix Zeroes
// Difficulty: Medium

// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0's.

// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Constraints:

//     m == matrix.length
//     n == matrix[0].length
//     1 <= m, n <= 200
//     -231 <= matrix[i][j] <= 231 - 1

// Follow up:

//     A straightforward solution using O(mn) space is probably a bad idea.
//     A simple improvement uses O(m + n) space, but still not the best
//     solution. Could you devise a constant space solution?

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        namespace rng = std::ranges;
        int  m = matrix.size(), n = matrix[0].size();
        bool row = rng::any_of(matrix[0], [](int cell) { return cell == 0; });
        bool col = rng::any_of(matrix, [](auto &row) { return row[0] == 0; });
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                matrix[i].assign(n, 0);
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                rng::for_each(matrix, [&](auto &row) { row[j] = 0; });
            }
        }
        if (row) {
            matrix[0].assign(n, 0);
        }
        if (col) {
            rng::for_each(matrix, [&](auto &row) { row[0] = 0; });
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::vector<std::vector<int>>> tests = {
        {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
        {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
        {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}},
    };

    Solution solution;
    for (auto &test : tests) {
        fmt::print("{}: ", test);
        solution.setZeroes(test);
        fmt::println("{}", test);
    }

    return 0;
}
