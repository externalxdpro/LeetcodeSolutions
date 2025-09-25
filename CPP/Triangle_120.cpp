// 120. Triangle
// Difficulty: Medium

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More
// formally, if you are on index i on the current row, you may move to either
// index i or index i + 1 on the next row.

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
// above).

// Example 2:

// Input: triangle = [[-10]]
// Output: -10

// Constraints:

//     1 <= triangle.length <= 200
//     triangle[0].length == 1
//     triangle[i].length == triangle[i - 1].length + 1
//     -104 <= triangle[i][j] <= 104

// Follow up: Could you do this using only O(n) extra space, where n is the
// total number of rows in the triangle?

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minimumTotal(std::vector<std::vector<int>> &triangle) {
        std::vector<std::vector<int>> memo(triangle.size(),
                                           std::vector(triangle.size(), -1));
        return recurse(triangle, 0, 0, memo);
    }

  private:
    int recurse(std::vector<std::vector<int>> &triangle, int i, int j,
                std::vector<std::vector<int>> &memo) {
        if (i >= (int)triangle.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int l = recurse(triangle, i + 1, j, memo);
        int r = recurse(triangle, i + 1, j + 1, memo);
        return memo[i][j] = triangle[i][j] + std::min(l, r);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, 11},
        {{{-10}}, -10},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimumTotal(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
