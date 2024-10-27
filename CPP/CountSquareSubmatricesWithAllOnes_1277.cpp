// 1277. Count Square Submatrices with All Ones
// Difficulty: Medium

// Given a m * n matrix of ones and zeros, return how many square submatrices
// have all ones.

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation:
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.

// Example 2:

// Input: matrix =
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation:
// There are 6 squares of side 1.
// There is 1 square of side 2.
// Total number of squares = 6 + 1 = 7.

// Constraints:

//     1 <= arr.length <= 300
//     1 <= arr[0].length <= 300
//     0 <= arr[i][j] <= 1

#include <algorithm>
#include <fmt/ranges.h>
#include <functional>
#include <vector>

class Solution {
  public:
    int countSquares(std::vector<std::vector<int>> &matrix) {
        std::vector<std::vector<int>> memo(matrix.size(),
                                           std::vector(matrix[0].size(), -1));
        std::function<int(int, int)>  recurse = [&](int i, int j) -> int {
            if (i >= matrix.size() || j >= matrix[0].size()) {
                return 0;
            }
            if (matrix[i][j] == 0) {
                return 0;
            }
            if (memo[i][j] != -1) {
                return memo[i][j];
            }

            int right    = recurse(i, j + 1);
            int down     = recurse(i + 1, j);
            int diagonal = recurse(i + 1, j + 1);

            return memo[i][j] = 1 + std::min({right, down, diagonal});
        };

        int result = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                result += recurse(i, j);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}}, 15},
        {{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}}, 7},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countSquares(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
