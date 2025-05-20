// 3355. Zero Array Transformation I
// Difficulty: Medium

// You are given an integer array nums of length n and a 2D array queries, where
// queries[i] = [li, ri].

// For each queries[i]:

//     Select a

//     of indices within the range [li, ri] in nums.
//     Decrement the values at the selected indices by 1.

// A Zero Array is an array where all elements are equal to 0.

// Return true if it is possible to transform nums into a Zero Array after
// processing all the queries sequentially, otherwise return false.

// Example 1:

// Input: nums = [1,0,1], queries = [[0,2]]

// Output: true

// Explanation:

//     For i = 0:
//         Select the subset of indices as [0, 2] and decrement the values at
//         these indices by 1. The array will become [0, 0, 0], which is a Zero
//         Array.

// Example 2:

// Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

// Output: false

// Explanation:

//     For i = 0:
//         Select the subset of indices as [1, 2, 3] and decrement the values at
//         these indices by 1. The array will become [4, 2, 1, 0].
//     For i = 1:
//         Select the subset of indices as [0, 1, 2] and decrement the values at
//         these indices by 1. The array will become [3, 1, 0, 0], which is not
//         a Zero Array.

// Constraints:

//     1 <= nums.length <= 105
//     0 <= nums[i] <= 105
//     1 <= queries.length <= 105
//     queries[i].length == 2
//     0 <= li <= ri < nums.length

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool isZeroArray(std::vector<int>              &nums,
                     std::vector<std::vector<int>> &queries) {
        std::vector<int> delta(nums.size() + 1);
        for (auto &q : queries) {
            delta[q[0]]++;
            delta[q[1] + 1]--;
        }
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += delta[i];
            if (curr < nums[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::pair<std::vector<int>, std::vector<std::vector<int>>>, bool>>
        tests = {
            {{{1, 0, 1}, {{0, 2}}}, true},
            {{{4, 3, 2, 1}, {{1, 3}, {0, 2}}}, false},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.isZeroArray(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
