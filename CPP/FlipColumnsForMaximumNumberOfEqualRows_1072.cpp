// 1072. Flip Columns For Maximum Number of Equal Rows
// Difficulty: Medium

// You are given an m x n binary matrix matrix.

// You can choose any number of columns in the matrix and flip every cell in
// that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

// Return the maximum number of rows that have all values equal after some
// number of flips.

// Example 1:

// Input: matrix = [[0,1],[1,1]]
// Output: 1
// Explanation: After flipping no values, 1 row has all values equal.

// Example 2:

// Input: matrix = [[0,1],[1,0]]
// Output: 2
// Explanation: After flipping values in the first column, both rows have equal
// values.

// Example 3:

// Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
// Output: 2
// Explanation: After flipping values in the first two columns, the last two
// rows have equal values.

// Constraints:

//     m == matrix.length
//     n == matrix[i].length
//     1 <= m, n <= 300
//     matrix[i][j] is either 0 or 1.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maxEqualRowsAfterFlips(std::vector<std::vector<int>> &matrix) {
        int max = 0;

        for (const auto &row : matrix) {
            std::vector<int> flipped(matrix[0].size());
            int              count = 0;

            for (int col = 0; col < matrix[0].size(); col++) {
                flipped[col] = 1 - row[col];
            }

            for (const auto &newRow : matrix) {
                if (newRow == row || newRow == flipped) {
                    count++;
                }
            }
            max = std::max(max, count);
        }
        return max;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{0, 1}, {1, 1}}, 1},
        {{{0, 1}, {1, 0}}, 2},
        {{{0, 0, 0}, {0, 0, 1}, {1, 1, 0}}, 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxEqualRowsAfterFlips(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
