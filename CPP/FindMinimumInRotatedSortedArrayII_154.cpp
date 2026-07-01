// 154. Find Minimum in Rotated Sorted Array II
// Difficulty: Hard

// Suppose an array of length n sorted in ascending order is rotated between 1
// and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

// [4,5,6,7,0,1,4] if it was rotated 4 times.
// [0,1,4,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
// in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums that may contain duplicates, return the
// minimum element of this array.

// You must decrease the overall operation steps as much as possible.

// Example 1:

// Input: nums = [1,3,5]
// Output: 1
// Example 2:

// Input: nums = [2,2,2,0,1]
// Output: 0

// Constraints:

// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// nums is sorted and rotated between 1 and n times.

// Follow up: This problem is similar to Find Minimum in Rotated Sorted Array,
// but nums may contain duplicates. Would this affect the runtime complexity?
// How and why?

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int findMin(std::vector<int> &nums) {
        size_t left = 0, right = nums.size() - 1;

        while (right > 0 && nums[right] == nums[0]) {
            right--;
        }

        while (left <= right) {
            size_t mid = left + (right - left) / 2;

            if (nums[0] > nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (left > nums.size() - 1)
            return nums[0];
        return nums[left];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 3, 5}, 1},
        {{2, 2, 2, 0, 1}, 0},
        {{3, 1, 3, 3}, 1},
        {{1}, 1},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.findMin(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
