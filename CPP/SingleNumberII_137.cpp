// 137. Single Number II
// Difficulty: Medium

// Given an integer array nums where every element appears three times except
// for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only
// constant extra space.

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

// Constraints:

// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each element in nums appears exactly three times except for one element which
// appears once.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int singleNumber(std::vector<int> &nums) {
        int result = 0;

        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int num : nums) {
                count += (num >> i) & 1;
            }

            result |= (count % 3) << i;
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 2, 3, 2}, 3},
        {{0, 1, 0, 1, 0, 1, 99}, 99},
        {{-2, -2, 1, 1, 4, 1, 4, 4, -4, -2}, -4},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.singleNumber(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
