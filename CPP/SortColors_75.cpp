// 75. Sort Colors
// Difficulty: Medium

// Given an array nums with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors in
// the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and
// blue, respectively.

// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Constraints:

//     n == nums.length
//     1 <= n <= 300
//     nums[i] is either 0, 1, or 2.

// Follow up: Could you come up with a one-pass algorithm using only constant
// extra space?

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    void sortColors(std::vector<int> &nums) {
        int l = 0, r = nums.size() - 1, i = 0;
        while (i <= r && r > 0) {
            if (nums[i] == 0) {
                std::swap(nums[i++], nums[l++]);
            } else if (nums[i] == 1) {
                i++;
            } else {
                std::swap(nums[i], nums[r--]);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> tests = {
        {2, 0, 2, 1, 1, 0},
        {2, 0, 1},
    };

    Solution solution;
    for (auto test : tests) {
        fmt::print("{}", test);
        solution.sortColors(test);
        fmt::println(": {}", test);
    }

    return 0;
}
