// 3097. Shortest Subarray With OR at Least K II
// Difficulty: Medium

// You are given an array nums of non-negative integers and an integer k.

// An array is called special if the bitwise OR of all of its elements is at
// least k.

// Return the length of the shortest special non-empty
// subarray
// of nums, or return -1 if no special subarray exists.

// Example 1:

// Input: nums = [1,2,3], k = 2

// Output: 1

// Explanation:

// The subarray [3] has OR value of 3. Hence, we return 1.

// Example 2:

// Input: nums = [2,1,8], k = 10

// Output: 3

// Explanation:

// The subarray [2,1,8] has OR value of 11. Hence, we return 3.

// Example 3:

// Input: nums = [1,2], k = 0

// Output: 1

// Explanation:

// The subarray [1] has OR value of 1. Hence, we return 1.

// Constraints:

//     1 <= nums.length <= 2 * 105
//     0 <= nums[i] <= 109
//     0 <= k <= 109

#include <fmt/ranges.h>
#include <functional>
#include <limits>
#include <vector>

class Solution {
  public:
    int minimumSubarrayLength(std::vector<int> &nums, int k) {
        int min   = std::numeric_limits<int>::max();
        int start = 0, end = 0;
        int bitCounts[32] = {0};

        std::function<void(int, int)> update = [&](int num, int delta) {
            for (int i = 0; i < 32; i++) {
                if ((num >> i) & 1) {
                    bitCounts[i] += delta;
                }
            }
        };
        std::function<int()> convertToNum = [&]() -> int {
            int result = 0;
            for (int i = 0; i < 32; i++) {
                if (bitCounts[i] != 0) {
                    result |= 1 << i;
                }
            }
            return result;
        };

        while (end < nums.size()) {
            update(nums[end], 1);

            while (start <= end && convertToNum() >= k) {
                min = std::min(min, end - start + 1);

                update(nums[start], -1);
                start++;
            }
            end++;
        }
        return min == std::numeric_limits<int>::max() ? -1 : min;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{1, 2, 3}, 2}, 1},  {{{2, 1, 8}, 10}, 3},      {{{1, 2}, 0}, 1},
        {{{1, 1, 1}, 2}, -1}, {{{1, 2, 32, 21}, 55}, 3},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimumSubarrayLength(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
