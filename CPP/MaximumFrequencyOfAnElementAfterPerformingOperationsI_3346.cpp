// 3346. Maximum Frequency of an Element After Performing Operations I
// Difficulty: Medium

// You are given an integer array nums and two integers k and numOperations.

// You must perform an operation numOperations times on nums, where in each
// operation you:

//     Select an index i that was not selected in any previous operations.
//     Add an integer in the range [-k, k] to nums[i].

// Return the maximum possible

// of any element in nums after performing the operations.

// Example 1:

// Input: nums = [1,4,5], k = 1, numOperations = 2

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

//     Adding 0 to nums[1]. nums becomes [1, 4, 5].
//     Adding -1 to nums[2]. nums becomes [1, 4, 4].

// Example 2:

// Input: nums = [5,11,20,20], k = 5, numOperations = 1

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

//     Adding 0 to nums[1].

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 105
//     0 <= k <= 105
//     0 <= numOperations <= nums.length

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int maxFrequency(std::vector<int> &nums, int k, int numOperations) {
        int n = nums.size();
        std::ranges::sort(nums);
        std::unordered_map<int, int> freqs;
        for (int num : nums) {
            freqs[num]++;
        }

        int l = 0, r = 0;
        int result = 0;
        for (int m = 0; m < n; m++) {
            while (nums[m] - nums[l] > k) {
                l++;
            }
            while (r < n - 1 && nums[r + 1] - nums[m] <= k) {
                r++;
            }

            int total = r - l + 1;
            result = std::max(result,
                              std::min(total - freqs[nums[m]], numOperations) +
                                  freqs[nums[m]]);
        }

        l = 0, r = 0;
        for (; r < n; r++) {
            int m = nums[l] + (nums[r] - nums[l]) / 2;

            while (m - nums[l] > k || nums[r] - m > k) {
                l++;
                m = nums[l] + (nums[r] - nums[l]) / 2;
            }
            result = std::max(result, std::min(r - l + 1, numOperations));
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int>, int>> tests =
        {
            {{{1, 4, 5}, 1, 2}, 2},
            {{{5, 11, 20, 20}, 5, 1}, 2},
            {{{88, 53}, 27, 2}, 2},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxFrequency(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
