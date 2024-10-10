// 962. Maximum Width Ramp
// Difficulty: Medium

// A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i]
// <= nums[j]. The width of such a ramp is j - i.

// Given an integer array nums, return the maximum width of a ramp in nums. If
// there is no ramp in nums, return 0.

// Example 1:

// Input: nums = [6,0,8,2,1,5]
// Output: 4
// Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] =
// 0 and nums[5] = 5.

// Example 2:

// Input: nums = [9,8,1,0,1,9,4,0,4,1]
// Output: 7
// Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] =
// 1 and nums[9] = 1.

// Constraints:

//     2 <= nums.length <= 5 * 104
//     0 <= nums[i] <= 5 * 104

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
  public:
    int maxWidthRamp(const std::vector<int> &nums) {
        std::vector<int> idxs(nums.size());
        std::iota(idxs.begin(), idxs.end(), 0);
        std::sort(idxs.begin(), idxs.end(), [&](int a, int b) {
            return nums[a] != nums[b] ? nums[a] < nums[b] : a < b;
        });

        int max = 0, min = idxs.size();
        for (int i = 0; i < idxs.size(); i++) {
            max = std::max(max, idxs[i] - min);
            min = std::min(min, idxs[i]);
        }

        return max;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{6, 0, 8, 2, 1, 5}, 4},
        {{9, 8, 1, 0, 1, 9, 4, 0, 4, 1}, 7},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxWidthRamp(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
