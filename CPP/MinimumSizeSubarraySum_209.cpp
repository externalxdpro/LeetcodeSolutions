// 209. Minimum Size Subarray Sum
// Difficulty: Medium

// Given an array of positive integers nums and a positive integer target,
// return the minimal length of a subarray whose sum is greater than or equal to
// target. If there is no such subarray, return 0 instead.

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem
// constraint. Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104

// Follow up: If you have figured out the O(n) solution, try coding another
// solution of which the time complexity is O(n log(n)).

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <vector>

class Solution {
  public:
    int minSubArrayLen(int target, std::vector<int> &nums) {
        int l = 0, sum = 0;
        int result = std::numeric_limits<int>::max();
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum >= target) {
                result = std::min(result, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return result == std::numeric_limits<int>::max() ? 0 : result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<int>>, int>> tests = {
        {{7, {2, 3, 1, 2, 4, 3}}, 2},
        {{4, {1, 4, 4}}, 1},
        {{11, {1, 1, 1, 1, 1, 1, 1, 1}}, 0},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.minSubArrayLen(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
