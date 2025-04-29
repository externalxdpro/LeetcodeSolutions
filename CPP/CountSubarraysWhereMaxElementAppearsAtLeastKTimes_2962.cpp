// 2962. Count Subarrays Where Max Element Appears at Least K Times
// Difficulty: Medium

// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at
// least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

// Example 1:

// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are:
// [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

// Example 2:

// Input: nums = [1,4,2,1], k = 3
// Output: 0
// Explanation: No subarray contains the element 4 at least 3 times.

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 106
//     1 <= k <= 105

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    long long countSubarrays(std::vector<int> &nums, int k) {
        int       max    = *std::ranges::max_element(nums);
        int       count  = 0;
        long long result = 0;
        int       l      = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == max) {
                count++;
            }
            while (count >= k) {
                count -= nums[l] == max;
                l++;
            }
            result += l;
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, long long>> tests =
        {
            {{{1, 3, 2, 3, 3}, 2}, 6},
            {{{1, 4, 2, 1}, 3}, 0},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countSubarrays(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
