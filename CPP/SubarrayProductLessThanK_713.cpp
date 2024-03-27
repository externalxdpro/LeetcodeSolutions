// [713] Subarray Product Less Than K
// Difficulty: Medium

// Given an array of integers nums and an integer k, return the number of
// contiguous subarrays where the product of all the elements in the subarray is
// strictly less than k.

// Example 1:
// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly
// less than k.

// Example 2:
// Input: nums = [1,2,3], k = 0
// Output: 0

// Constraints:
//     1 <= nums.length <= 3 * 10^4
//     1 <= nums[i] <= 1000
//     0 <= k <= 10^6

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int numSubarrayProductLessThanK(std::vector<int> &nums, int k) {
        int       l = 0, r = 0;
        long long product = 1;
        int       result  = 0;
        for (; r < nums.size(); r++) {
            product *= nums[r];
            for (; product >= k && l <= r; l++) {
                product /= nums[l];
            }
            result += (r - l + 1);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{10, 5, 2, 6}, 100}, 8},
        {{{1, 2, 3}, 0}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.numSubarrayProductLessThanK(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
