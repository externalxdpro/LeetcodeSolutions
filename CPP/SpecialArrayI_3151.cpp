// 3151. Special Array I
// Difficulty: Easy

// An array is considered special if every pair of its adjacent elements
// contains two numbers with different parity.

// You are given an array of integers nums. Return true if nums is a special
// array, otherwise, return false.

// Example 1:

// Input: nums = [1]

// Output: true

// Explanation:

// There is only one element. So the answer is true.

// Example 2:

// Input: nums = [2,1,4]

// Output: true

// Explanation:

// There is only two pairs: (2,1) and (1,4), and both of them contain numbers
// with different parity. So the answer is true.

// Example 3:

// Input: nums = [4,3,1,6]

// Output: false

// Explanation:

// nums[1] and nums[2] are both odd. So the answer is false.

// Constraints:

//     1 <= nums.length <= 100
//     1 <= nums[i] <= 100

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool isArraySpecial(std::vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, bool>> tests = {
        {{1}, true},
        {{2, 1, 4}, true},
        {{4, 3, 1, 6}, false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.isArraySpecial(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
