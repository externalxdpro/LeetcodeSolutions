// 3356. Zero Array Transformation II
// Difficulty: Medium

// You are given an integer array nums of length n and a 2D array queries where
// queries[i] = [li, ri, vali].

// Each queries[i] represents the following action on nums:

//     Decrement the value at each index in the range [li, ri] in nums by at
//     most vali. The amount by which each value is decremented can be chosen
//     independently for each index.

// A Zero Array is an array with all its elements equal to 0.

// Return the minimum possible non-negative value of k, such that after
// processing the first k queries in sequence, nums becomes a Zero Array. If no
// such k exists, return -1.

// Example 1:

// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

// Output: 2

// Explanation:

//     For i = 0 (l = 0, r = 2, val = 1):
//         Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
//         The array will become [1, 0, 1].
//     For i = 1 (l = 0, r = 2, val = 1):
//         Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
//         The array will become [0, 0, 0], which is a Zero Array. Therefore,
//         the minimum value of k is 2.

// Example 2:

// Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

// Output: -1

// Explanation:

//     For i = 0 (l = 1, r = 3, val = 2):
//         Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
//         The array will become [4, 1, 0, 0].
//     For i = 1 (l = 0, r = 2, val = 1):
//         Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
//         The array will become [3, 0, 0, 0], which is not a Zero Array.

// Constraints:

//     1 <= nums.length <= 105
//     0 <= nums[i] <= 5 * 105
//     1 <= queries.length <= 105
//     queries[i].length == 3
//     0 <= li <= ri < nums.length
//     1 <= vali <= 5

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minZeroArray(std::vector<int>              &nums,
                     std::vector<std::vector<int>> &queries) {
        int l = 0, r = queries.size();
        if (!canForm(nums, queries, r)) {
            return -1;
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (canForm(nums, queries, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

  private:
    bool canForm(std::vector<int> &nums, std::vector<std::vector<int>> &queries,
                 int k) {
        int              sum = 0;
        std::vector<int> diff(nums.size() + 1);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];

            diff[l] += val;
            diff[r + 1] -= val;
        }
        for (int i = 0; i < nums.size(); i++) {
            sum += diff[i];
            if (sum < nums[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::pair<std::vector<int>, std::vector<std::vector<int>>>, int>>
        tests = {
            {{{2, 0, 2}, {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}}}, 2},
            {{{4, 3, 2, 1}, {{1, 3, 2}, {0, 2, 1}}}, -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minZeroArray(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
