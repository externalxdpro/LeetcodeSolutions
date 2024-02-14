// Difficulty: Medium
// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
// You must decrease the overall operation steps as much as possible.

// Example 1:
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Example 2:
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

// Constraints:
//     1 <= nums.length <= 5000
//     -104 <= nums[i] <= 104
//     nums is guaranteed to be rotated at some pivot.
//     -104 <= target <= 104

// Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

bool search(std::vector<int>& nums, int target) {
    std::vector<int>::iterator it = nums.begin();
    for (auto i = nums.begin() + 1; i != nums.end(); ++i) {
        if (*(i - 1) > *i) {
            it = i;
            break;
        }
    }

    std::vector<int>::iterator left, right;
    if (it == nums.begin()) {
        left = nums.begin();
        right = nums.end() - 1;
    }
    else {
        if (target <= *(nums.end() - 1)) {
            left = it;
            right = nums.end() - 1;
        }
        else {
            left = nums.begin();
            right = it - 1;
        }
    }

    while (left < right) {
        auto middle = left + ((right - left) / 2);

        if (*middle == target) return true;
        else if (*middle < target) left = middle + 1;
        else right = middle - 1;
    }

    if ((left < nums.end() && *left == target) ||
        (right >= nums.begin() && *right == target))
        return true;

    return false;
}

int main() {
    std::vector<std::pair<std::vector<int>, int>> tests{{{2,5,6,0,0,1,2}, 0},
                                                        {{2,5,6,0,0,1,2}, 3},
                                                        {{1}, 1},
                                                        {{1, 1}, 0},
                                                        {{1, 3}, 3},
                                                        {{1, 3}, 1},
                                                        {{3, 1}, 1}};

    for (auto [nums, target] : tests) {
        std::cout << (search(nums, target) ? "true" : "false") << std::endl;
    }

    return 0;
}
