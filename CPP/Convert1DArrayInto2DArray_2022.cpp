// 2022. Convert 1D Array Into 2D Array
// Difficulty: Easy

// You are given a 0-indexed 1-dimensional (1D) integer array original, and two
// integers, m and n. You are tasked with creating a 2-dimensional (2D) array
// with  m rows and n columns using all the elements from original.
// The elements from indices 0 to n - 1 (inclusive) of original should form the
// first row of the constructed 2D array, the elements from indices n to 2 * n -
// 1 (inclusive) should form the second row of the constructed 2D array, and so
// on.
// Return an m x n 2D array constructed according to the above procedure, or an
// empty 2D array if it is impossible.

// Example 1:
// Input: original = [1,2,3,4], m = 2, n = 2
// Output: [[1,2],[3,4]]
// Explanation: The constructed 2D array should contain 2 rows and 2 columns.
// The first group of n=2 elements in original, [1,2], becomes the first row in
// the constructed 2D array. The second group of n=2 elements in original,
// [3,4], becomes the second row in the constructed 2D array.

// Example 2:
// Input: original = [1,2,3], m = 1, n = 3
// Output: [[1,2,3]]
// Explanation: The constructed 2D array should contain 1 row and 3 columns.
// Put all three elements in original into the first row of the constructed 2D
// array.

// Example 3:
// Input: original = [1,2], m = 1, n = 1
// Output: []
// Explanation: There are 2 elements in original.
// It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D
// array.

// Constraints:
//     1 <= original.length <= 5 * 10^4
//     1 <= original[i] <= 10^5
//     1 <= m, n <= 4 * 10^4

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int> &original,
                                                   int m, int n) {
        if (m * n != original.size()) {
            return {};
        }
        int                           origI = 0;
        std::vector<std::vector<int>> result(m, std::vector(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[origI];
                origI++;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int>,
                          std::vector<std::vector<int>>>>
        tests = {
            {{{1, 2, 3, 4}, 2, 2}, {{1, 2}, {3, 4}}},
            {{{1, 2, 3}, 1, 3}, {{1, 2, 3}}},
            {{{1, 2}, 1, 1}, {}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.construct2DArray(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
