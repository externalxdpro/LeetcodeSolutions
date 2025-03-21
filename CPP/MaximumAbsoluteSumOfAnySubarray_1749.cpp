// 1749. Maximum Absolute Sum of Any Subarray
// Difficulty: Medium

// You are given an integer array nums. The absolute sum of a subarray [numsl,
// numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 +
// numsr).

// Return the maximum absolute sum of any (possibly empty) subarray of nums.

// Note that abs(x) is defined as follows:

//     If x is a negative integer, then abs(x) = -x.
//     If x is a non-negative integer, then abs(x) = x.

// Example 1:

// Input: nums = [1,-3,2,3,-4]
// Output: 5
// Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

// Example 2:

// Input: nums = [2,-5,1,-4,3,-2]
// Output: 8
// Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8)
// = 8.

// Constraints:

//     1 <= nums.length <= 105
//     -104 <= nums[i] <= 104

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <vector>

class Solution {
  public:
    int maxAbsoluteSum(std::vector<int> &nums) {
        int result = 0, prefix = 0;
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            min = std::min(prefix, min);
            max = std::max(prefix, max);

            if (prefix > 0) {
                result = std::max({prefix, result, prefix - min});
            } else {
                result = std::max(
                    {std::abs(prefix), result, std::abs(prefix - max)});
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, -3, 2, 3, -4}, 5},
        {{2, -5, 1, -4, 3, -2}, 8},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxAbsoluteSum(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
