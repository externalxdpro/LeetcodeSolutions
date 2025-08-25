// 498. Diagonal Traverse
// Difficulty: Medium

// Given an m x n matrix mat, return an array of all the elements of the array
// in a diagonal order.

// Example 1:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]

// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]

// Constraints:

//     m == mat.length
//     n == mat[i].length
//     1 <= m, n <= 104
//     1 <= m * n <= 104
//     -105 <= mat[i][j] <= 105

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int step = 1;
        std::vector<int> result;
        for (int i = 0, j = 0; i <= n && j <= m;) {
            if (i == n - 2 && j == m) {
                break;
            } else if (i == -1) {
                if (j < m) {
                    i++;
                } else {
                    i += 2;
                    j--;
                }
                step = -1;
            } else if (j == -1) {
                if (i < n) {
                    j++;
                } else {
                    j += 2;
                    i--;
                }
                step = 1;
            } else if (j == m) {
                i += 2;
                j--;
                step = -1;
            } else if (i == n) {
                j += 2;
                i--;
                step = 1;
            } else {
                result.push_back(mat[i][j]);
                i -= step, j += step;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<int>>>
        tests = {
            {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 4, 7, 5, 3, 6, 8, 9}},
            {{{1, 2}, {3, 4}}, {1, 2, 3, 4}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findDiagonalOrder(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
