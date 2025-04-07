// 416. Partition Equal Subset Sum
// Difficulty: Medium

// Given an integer array nums, return true if you can partition the array into
// two subsets such that the sum of the elements in both subsets is equal or
// false otherwise.

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

// Constraints:

//     1 <= nums.length <= 200
//     1 <= nums[i] <= 100

#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
  public:
    bool canPartition(std::vector<int> &nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        std::vector<std::vector<int>> memo(nums.size(),
                                           std::vector(sum / 2 + 1, -1));
        return recurse(nums, 0, sum / 2, memo);
    }

  private:
    bool recurse(std::vector<int> &nums, int i, int target,
                 std::vector<std::vector<int>> &memo) {
        if (target == 0) {
            return true;
        }
        if (i == nums.size() || target < 0) {
            return false;
        }
        if (memo[i][target] != -1) {
            return memo[i][target];
        }
        bool take = recurse(nums, i + 1, target - nums[i], memo);
        bool skip = recurse(nums, i + 1, target, memo);

        return memo[i][target] = take || skip;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, bool>> tests = {
        {{1, 5, 11, 5}, true},
        {{1, 2, 3, 5}, false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.canPartition(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
