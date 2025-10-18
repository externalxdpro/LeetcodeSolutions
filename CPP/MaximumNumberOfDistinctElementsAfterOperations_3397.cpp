// 3397. Maximum Number of Distinct Elements After Operations
// Difficulty: Medium

// You are given an integer array nums and an integer k.

// You are allowed to perform the following operation on each element of the
// array at most once:

//     Add an integer in the range [-k, k] to the element.

// Return the maximum possible number of distinct elements in nums after
// performing the operations.

// Example 1:

// Input: nums = [1,2,2,3,3,4], k = 2

// Output: 6

// Explanation:

// nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first
// four elements.

// Example 2:

// Input: nums = [4,4,4,4], k = 1

// Output: 3

// Explanation:

// By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 109
//     0 <= k <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maxDistinctElements(std::vector<int> &nums, int k) {
        std::ranges::sort(nums);
        int result = 0;
        int prev = INT_MIN;
        for (int i : nums) {
            int curr = std::min(std::max(i - k, prev + 1), i + k);
            if (curr > prev) {
                result++;
                prev = curr;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{1, 2, 2, 3, 3, 4}, 2}, 6},
        {{{4, 4, 4, 4}, 1}, 3},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxDistinctElements(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
