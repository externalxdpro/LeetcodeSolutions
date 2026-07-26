// 213. House Robber II
// Difficulty: Medium

// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed. All houses at this place are
// arranged in a circle. That means the first house is the neighbor of the last
// one. Meanwhile, adjacent houses have a security system connected, and it will
// automatically contact the police if two adjacent houses were broken into on
// the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the
// police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money =
// 2), because they are adjacent houses. Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int rob(std::vector<int> &nums) {
        size_t n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        std::vector<int> arr(n - 1);
        for (size_t i = 0; i < n - 1; i++) {
            arr[i] = nums[i];
        }
        int a = solve(arr);
        for (size_t i = 1; i < n; i++) {
            arr[i - 1] = nums[i];
        }
        int b = solve(arr);
        return std::max(a, b);
    }

  private:
    int solve(std::vector<int> &nums) {
        size_t n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        std::vector<int> memo(n);
        memo[0] = nums[0];
        memo[1] = std::max(nums[0], nums[1]);

        for (size_t i = 2; i < n; i++) {
            memo[i] = std::max(nums[i] + memo[i - 2], memo[i - 1]);
        }
        return memo[n - 1];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 3, 2}, 3},
        {{1, 2, 3, 1}, 4},
        {{1, 2, 3}, 3},
        {{1}, 1},
        {{6, 6, 4, 8, 4, 3, 3, 10}, 27},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.rob(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
