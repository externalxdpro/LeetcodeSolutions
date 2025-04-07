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
#include <vector>

class Solution {
  public:
    bool canPartition(std::vector<int> &nums) {
        std::vector<std::vector<int>> memo(200, std::vector(20001, -1));
        return recurse(nums, 0, 0, 0, memo);
    }

    bool recurse(std::vector<int> &nums, int i, int lsum, int rsum,
                 std::vector<std::vector<int>> &memo) {
        if (i == nums.size()) {
            return lsum == rsum;
        }
        if (memo[i][lsum] != -1) {
            return memo[i][lsum];
        }
        bool l = recurse(nums, i + 1, lsum + nums[i], rsum, memo);
        bool r = recurse(nums, i + 1, lsum, rsum + nums[i], memo);

        return memo[i][lsum] = l | r;
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
