// 3392. Count Subarrays of Length Three With a Condition
// Difficulty: Easy

// Given an integer array nums, return the number of

// of length 3 such that the sum of the first and third numbers equals exactly
// half of the second number.

// Example 1:

// Input: nums = [1,2,1,4,1]

// Output: 1

// Explanation:

// Only the subarray [1,4,1] contains exactly 3 elements where the sum of the
// first and third numbers equals half the middle number.

// Example 2:

// Input: nums = [1,1,1]

// Output: 0

// Explanation:

// [1,1,1] is the only subarray of length 3. However, its first and third
// numbers do not add to half the middle number.

// Constraints:

//     3 <= nums.length <= 100
//     -100 <= nums[i] <= 100

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int countSubarrays(std::vector<int> &nums) {
        int result = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i + 1] % 2 == 0 &&
                nums[i] + nums[i + 2] == nums[i + 1] / 2) {
                result++;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 1, 4, 1}, 1},
        {{1, 1, 1}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countSubarrays(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
