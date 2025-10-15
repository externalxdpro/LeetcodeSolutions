// 3350. Adjacent Increasing Subarrays Detection II
// Difficulty: Medium

// Given an array nums of n integers, your task is to find the maximum value of
// k for which there exist two adjacent

// of length k each, such that both subarrays are strictly increasing.
// Specifically, check if there are two subarrays of length k starting at
// indices a and b (a < b), where:

//     Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly
//     increasing. The subarrays must be adjacent, meaning b = a + k.

// Return the maximum possible value of k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [2,5,7,8,9,2,3,4,3,1]

// Output: 3

// Explanation:

//     The subarray starting at index 2 is [7, 8, 9], which is strictly
//     increasing. The subarray starting at index 5 is [2, 3, 4], which is also
//     strictly increasing. These two subarrays are adjacent, and 3 is the
//     maximum possible value of k for which two such adjacent strictly
//     increasing subarrays exist.

// Example 2:

// Input: nums = [1,2,3,4,4,4,4,5,6,7]

// Output: 2

// Explanation:

//     The subarray starting at index 0 is [1, 2], which is strictly increasing.
//     The subarray starting at index 2 is [3, 4], which is also strictly
//     increasing. These two subarrays are adjacent, and 2 is the maximum
//     possible value of k for which two such adjacent strictly increasing
//     subarrays exist.

// Constraints:

//     2 <= nums.length <= 2 * 105
//     -109 <= nums[i] <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maxIncreasingSubarrays(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> inc;
        for (int i = 0; i < n; i++) {
            int j = 1;
            for (; i + j < n; j++) {
                if (nums[i + j] <= nums[i + j - 1]) {
                    break;
                }
            }
            i += j - 1;
            inc.push_back(j);
        }

        int result = 0;
        if (inc.size() == 1) {
            result = std::max(result, inc[0] / 2);
        }
        for (size_t i = 0; i < inc.size() - 1; i++) {
            result = std::max(result, inc[i] / 2);
            result = std::max(result, inc[i + 1] / 2);
            result = std::max(result, std::min(inc[i], inc[i + 1]));
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, 3},
        {{1, 2, 3, 4, 4, 4, 4, 5, 6, 7}, 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxIncreasingSubarrays(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
