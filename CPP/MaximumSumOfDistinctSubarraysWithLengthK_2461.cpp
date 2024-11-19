// 2461. Maximum Sum of Distinct Subarrays With Length K
// Difficulty: Medium

// You are given an integer array nums and an integer k. Find the maximum
// subarray sum of all the subarrays of nums that meet the following conditions:

//     The length of the subarray is k, and
//     All the elements of the subarray are distinct.

// Return the maximum subarray sum of all the subarrays that meet the
// conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is
// repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is
// repeated. We return 15 because it is the maximum subarray sum of all the
// subarrays that meet the conditions

// Example 2:

// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is
// repeated. We return 0 because no subarrays meet the conditions.

// Constraints:

//     1 <= k <= nums.length <= 105
//     1 <= nums[i] <= 105

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    long long maximumSubarraySum(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> lastI;
        long long                    sum    = 0;
        long long                    result = 0;
        int                          l = 0, r = 0;

        while (r < nums.size()) {
            int prev = lastI.contains(nums[r]) ? lastI[nums[r]] : -1;

            while (l <= prev || r - l + 1 > k) {
                sum -= nums[l];
                l++;
            }
            lastI[nums[r]] = r;
            sum += nums[r];
            if (r - l + 1 == k) {
                result = std::max(result, sum);
            }
            r++;
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{1, 5, 4, 2, 9, 9, 9}, 3}, 15},
        {{{4, 4, 4}, 3}, 0},
        {{{1, 1, 1, 1, 1, 1}, 2}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumSubarraySum(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
