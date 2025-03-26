// 2033. Minimum Operations to Make a Uni-Value Grid
// Difficulty: Medium

// You are given a 2D integer grid of size m x n and an integer x. In one
// operation, you can add x to or subtract x from any element in the grid.

// A uni-value grid is a grid where all the elements of it are equal.

// Return the minimum number of operations to make the grid uni-value. If it is
// not possible, return -1.

// Example 1:

// Input: grid = [[2,4],[6,8]], x = 2
// Output: 4
// Explanation: We can make every element equal to 4 by doing the following:
// - Add x to 2 once.
// - Subtract x from 6 once.
// - Subtract x from 8 twice.
// A total of 4 operations were used.

// Example 2:

// Input: grid = [[1,5],[2,3]], x = 1
// Output: 5
// Explanation: We can make every element equal to 3.

// Example 3:

// Input: grid = [[1,2],[3,4]], x = 2
// Output: -1
// Explanation: It is impossible to make every element equal.

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 105
//     1 <= m * n <= 105
//     1 <= x, grid[i][j] <= 104

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minOperations(std::vector<std::vector<int>> &grid, int x) {
        std::vector<int> nums;
        nums.reserve(grid.size() * grid[0].size());
        for (auto &r : grid) {
            nums.insert(nums.end(), r.begin(), r.end());
        }
        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2,
                         nums.end());

        int final  = nums[nums.size() / 2];
        int result = 0;
        for (int i : nums) {
            if (i % x != final % x) {
                return -1;
            }
            result += std::abs(final - i) / x;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<std::vector<int>>, int>, int>>
        tests = {
            {{{{2, 4}, {6, 8}}, 2}, 4},
            {{{{1, 5}, {2, 3}}, 1}, 5},
            {{{{1, 2}, {3, 4}}, 2}, -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minOperations(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
