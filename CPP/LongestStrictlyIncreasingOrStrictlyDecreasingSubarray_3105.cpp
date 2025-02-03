// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// Difficulty: Easy

// You are given an array of integers nums. Return the length of the longest
// subarray
// of nums which is either
// strictly increasing
// or
// strictly decreasing
// .

// Example 1:

// Input: nums = [1,4,3,3,2]

// Output: 2

// Explanation:

// The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and
// [1,4].

// The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2],
// and [4,3].

// Hence, we return 2.

// Example 2:

// Input: nums = [3,3,3,3]

// Output: 1

// Explanation:

// The strictly increasing subarrays of nums are [3], [3], [3], and [3].

// The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

// Hence, we return 1.

// Example 3:

// Input: nums = [3,2,1]

// Output: 3

// Explanation:

// The strictly increasing subarrays of nums are [3], [2], and [1].

// The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1],
// and [3,2,1].

// Hence, we return 3.

// Constraints:

//     1 <= nums.length <= 50
//     1 <= nums[i] <= 50

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int longestMonotonicSubarray(std::vector<int> &nums) {
        int max = 1;
        for (int i = 0; i < nums.size(); i++) {
            int j;
            for (j = i + 1; j < nums.size() && nums[j] > nums[j - 1]; j++) {}
            max = std::max(max, j - i);
            for (j = i + 1; j < nums.size() && nums[j] < nums[j - 1]; j++) {}
            max = std::max(max, j - i);
        }
        return max;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 4, 3, 3, 2}, 2},
        {{3, 3, 3, 3}, 1},
        {{3, 2, 1}, 3},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.longestMonotonicSubarray(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
