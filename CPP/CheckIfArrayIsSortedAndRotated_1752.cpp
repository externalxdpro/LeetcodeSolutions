// 1752. Check if Array Is Sorted and Rotated
// Difficulty: Easy

// Given an array nums, return true if the array was originally sorted in
// non-decreasing order, then rotated some number of positions (including zero).
// Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same
// length such that A[i] == B[(i+x) % A.length], where % is the modulo
// operation.

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of
// value 3: [3,4,5,1,2].

// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.

// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

// Constraints:

//     1 <= nums.length <= 100
//     1 <= nums[i] <= 100

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool check(std::vector<int> &nums) {
        int greater = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                greater++;
            }
            if (greater > 1) {
                return false;
            }
        }
        return greater == 0 || nums.back() <= nums.front();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, bool>> tests = {
        {{3, 4, 5, 1, 2}, true},
        {{2, 1, 3, 4}, false},
        {{1, 2, 3}, true},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.check(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
