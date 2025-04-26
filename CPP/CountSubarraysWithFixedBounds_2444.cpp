// 2444. Count Subarrays With Fixed Bounds
// Difficulty: Hard

// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following
// conditions:

//     The minimum value in the subarray is equal to minK.
//     The maximum value in the subarray is equal to maxK.

// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

// Example 2:

// Input: nums = [1,1,1,1], minK = 1, maxK = 1
// Output: 10
// Explanation: Every subarray of nums is a fixed-bound subarray. There are 10
// possible subarrays.

// Constraints:

//     2 <= nums.length <= 105
//     1 <= nums[i], minK, maxK <= 106

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    long long countSubarrays(std::vector<int> &nums, int minK, int maxK) {
        long long result = 0;
        int       minI = -1, maxI = -1;
        int       l = 0;
        for (int r = 0; r < nums.size(); r++) {
            int curr = nums[r];
            if (curr < minK || curr > maxK) {
                l = r + 1;
                continue;
            }
            if (curr == minK) {
                minI = r;
            }
            if (curr == maxK) {
                maxI = r;
            }
            result += std::max(std::min(minI, maxI) - l + 1, 0);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int>, int>> tests =
        {
            {{{1, 3, 5, 2, 7, 5}, 1, 5}, 2},
            {{{1, 1, 1, 1}, 1, 1}, 10},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countSubarrays(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
