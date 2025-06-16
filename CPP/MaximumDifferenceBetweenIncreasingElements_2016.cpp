// 2016. Maximum Difference Between Increasing Elements
// Difficulty: Easy

// Given a 0-indexed integer array nums of size n, find the maximum difference
// between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j <
// n and nums[i] < nums[j].

// Return the maximum difference. If no such i and j exists, return -1.

// Example 1:

// Input: nums = [7,1,5,4]
// Output: 4
// Explanation:
// The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1
// = 4. Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1
// = 6, but i > j, so it is not valid.

// Example 2:

// Input: nums = [9,4,3,2]
// Output: -1
// Explanation:
// There is no i and j such that i < j and nums[i] < nums[j].

// Example 3:

// Input: nums = [1,5,2,10]
// Output: 9
// Explanation:
// The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 -
// 1 = 9.

// Constraints:

//     n == nums.length
//     2 <= n <= 1000
//     1 <= nums[i] <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maximumDifference(std::vector<int> &nums) {
        int min = nums[0];
        int result = -1;
        for (int i : nums) {
            min = std::min(min, i);
            if (min < i) {
                result = std::max(result, i - min);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{7, 1, 5, 4}, 4},
        {{9, 4, 3, 2}, -1},
        {{1, 5, 2, 10}, 9},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumDifference(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
