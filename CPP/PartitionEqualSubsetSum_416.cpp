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

#include <bitset>
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
        std::bitset<10001> bit(1);
        for (int i : nums) {
            bit |= bit << i;
            if (bit[sum / 2]) {
                return bit[sum / 2];
            }
        }
        return bit[sum / 2];
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
