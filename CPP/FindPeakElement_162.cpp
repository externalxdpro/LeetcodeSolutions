// 162. Find Peak Element
// Difficulty: Medium

// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its
// index. If the array contains multiple peaks, return the index to any of the
// peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is
// always considered to be strictly greater than a neighbor that is outside the
// array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index
// number 2. Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak
// element is 2, or index number 5 where the peak element is 6.

// Constraints:

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int findPeakElement(std::vector<int> &nums) {
        size_t l = 0, r = nums.size() - 1;

        while (l < r) {
            size_t m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 3, 1}, 2},
        {{1, 2, 1, 3, 5, 6, 4}, 5},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.findPeakElement(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
