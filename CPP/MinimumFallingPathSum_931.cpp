// Difficulty: Medium
// Given an n x n array of integers matrix, return the minimum sum of any
// falling path through matrix.

// A falling path starts at any element in the first row and chooses the element
// in the next row that is either directly below or diagonally left/right.
// Specifically, the next element from position (row, col) will be (row + 1, col
// - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1:
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.

// Example 2:
// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

// Recursive
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         std::vector<int> sums(matrix.size(), 0);
//         for (int i = 0; i < matrix.size(); i++) {
//             sums[i] = recurse(matrix, 0, i);
//         }
//         return std::ranges::min(sums);
//     }
// private:
//     int recurse(std::vector<std::vector<int>> &matrix, int rowIndex, int
//     colIndex) {
//         if (colIndex < 0 || colIndex >= matrix[rowIndex].size()) {
//             return INT_MAX;
//         }
//         if (rowIndex == matrix.size() - 1) {
//             return matrix[rowIndex][colIndex];
//         }

//         int result = matrix[rowIndex][colIndex] +
//                     std::min({recurse(matrix, rowIndex + 1, colIndex - 1),
//                             recurse(matrix, rowIndex + 1, colIndex),
//                             recurse(matrix, rowIndex + 1, colIndex + 1)});
//         return result;
//     }
// };

// Recursive
// class Solution {
//   public:
//     int minFallingPathSum(vector<vector<int>> &matrix) {
//         std::vector<int>              sums(matrix.size(), 0);
//         std::vector<std::vector<int>> memo(
//             matrix.size(), std::vector<int>(matrix.size(), INT_MAX));
//         for (int i = 0; i < matrix.size(); i++) {
//             sums[i] = recurse(matrix, 0, i, memo);
//         }
//         return std::ranges::min(sums);
//     }

//   private:
//     int recurse(std::vector<std::vector<int>> &matrix, int rowIndex,
//                 int colIndex, std::vector<std::vector<int>> &memo) {
//         if (rowIndex == matrix.size() - 1) {
//             memo[rowIndex][colIndex] = matrix[rowIndex][colIndex];
//             return memo[rowIndex][colIndex];
//         }

//         std::vector<int> sums(3, INT_MAX);
//         if (colIndex - 1 >= 0) {
//             if (memo[rowIndex + 1][colIndex - 1] != INT_MAX) {
//                 sums[0] = memo[rowIndex + 1][colIndex - 1];
//             } else {
//                 sums[0] = recurse(matrix, rowIndex + 1, colIndex - 1, memo);
//             }
//         }

//         if (memo[rowIndex + 1][colIndex] != INT_MAX) {
//             sums[1] = memo[rowIndex + 1][colIndex];
//         } else {
//             sums[1] = recurse(matrix, rowIndex + 1, colIndex, memo);
//         }

//         if (colIndex + 1 < matrix[rowIndex + 1].size()) {
//             if (memo[rowIndex + 1][colIndex + 1] != INT_MAX) {
//                 sums[2] = memo[rowIndex + 1][colIndex + 1];
//             } else {
//                 sums[2] = recurse(matrix, rowIndex + 1, colIndex + 1, memo);
//             }
//         }

//         memo[rowIndex][colIndex] =
//             matrix[rowIndex][colIndex] + std::ranges::min(sums);
//         return memo[rowIndex][colIndex];
//     }
// };

// Bottom-up
class Solution {
  public:
    int minFallingPathSum(std::vector<std::vector<int>> &matrix) {
        std::vector<std::vector<int>> sums(matrix.size(),
                                           std::vector<int>(matrix.size()));
        sums.back() = matrix.back();

        for (int i = matrix.size() - 2; i >= 0; i--) {
            for (int j = 0; j < matrix[i].size(); j++) {
                std::vector<int> temp(3, INT_MAX);
                if (j != 0) {
                    temp[0] = sums[i + 1][j - 1];
                }
                temp[1] = sums[i + 1][j];
                if (j != matrix[i].size() - 1) {
                    temp[2] = sums[i + 1][j + 1];
                }
                sums[i][j] = matrix[i][j] + std::ranges::min(temp);
            }
        }

        return std::ranges::min(sums[0]);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::vector<std::vector<int>>> tests = {
        {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}},
        {{-19, 57}, {-40, -5}},
    };

    Solution solution;
    for (auto test : tests) {
        fmt::print("{}: {}\n", test, solution.minFallingPathSum(test));
    }

    return 0;
}
