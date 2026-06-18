// 136. Single Number
// Difficulty: Easy

// Given a non-empty array of integers nums, every element appears twice except
// for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only
// constant extra space.

// Example 1:

// Input: nums = [2,2,1]

// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]

// Output: 4

// Example 3:

// Input: nums = [1]

// Output: 1

// Constraints:

// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears
// only once.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int singleNumber(std::vector<int> &nums) {
        int curr = 0;
        for (int i : nums) {
            curr ^= i;
        }
        return curr;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 2, 1}, 1},
        {{4, 1, 2, 1, 2}, 4},
        {{1}, 1},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.singleNumber(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
