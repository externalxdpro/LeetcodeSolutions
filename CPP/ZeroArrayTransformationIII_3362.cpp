// 3362. Zero Array Transformation III
// Difficulty: Medium

// You are given an integer array nums of length n and a 2D array queries where
// queries[i] = [li, ri].

// Each queries[i] represents the following action on nums:

//     Decrement the value at each index in the range [li, ri] in nums by at
//     most 1. The amount by which the value is decremented can be chosen
//     independently for each index.

// A Zero Array is an array with all its elements equal to 0.

// Return the maximum number of elements that can be removed from queries, such
// that nums can still be converted to a zero array using the remaining queries.
// If it is not possible to convert nums to a zero array, return -1.

// Example 1:

// Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

// Output: 1

// Explanation:

// After removing queries[2], nums can still be converted to a zero array.

//     Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
//     Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.

// Example 2:

// Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

// Output: 2

// Explanation:

// We can remove queries[2] and queries[3].

// Example 3:

// Input: nums = [1,2,3,4], queries = [[0,3]]

// Output: -1

// Explanation:

// nums cannot be converted to a zero array even after using all the queries.

// Constraints:

//     1 <= nums.length <= 105
//     0 <= nums[i] <= 105
//     1 <= queries.length <= 105
//     queries[i].length == 2
//     0 <= li <= ri < nums.length

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int maxRemoval(std::vector<int>              &nums,
                   std::vector<std::vector<int>> &queries) {
        std::ranges::sort(queries);
        std::priority_queue<int> pq;
        std::vector<int>         delta(nums.size() + 1);
        int                      curr = 0;
        int                      j    = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += delta[i];
            while (j < queries.size() && queries[j][0] == i) {
                pq.push(queries[j][1]);
                j++;
            }
            while (curr < nums[i] && !pq.empty() && pq.top() >= i) {
                curr++;
                delta[pq.top() + 1]--;
                pq.pop();
            }
            if (curr < nums[i]) {
                return -1;
            }
        }
        return pq.size();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::pair<std::vector<int>, std::vector<std::vector<int>>>, int>>
        tests = {
            {{{2, 0, 2}, {{0, 2}, {0, 2}, {1, 1}}}, 1},
            {{{1, 1, 1, 1}, {{1, 3}, {0, 2}, {1, 3}, {1, 2}}}, 2},
            {{{1, 2, 3, 4}, {{0, 3}}}, -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxRemoval(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
