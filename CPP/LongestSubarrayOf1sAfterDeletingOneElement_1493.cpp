// 1493. Longest Subarray of 1's After Deleting One Element
// Difficulty: Medium

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the
// resulting array. Return 0 if there is no such subarray.

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3
// numbers with value of 1's.

// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
// longest subarray with value of 1's is [1,1,1,1,1].

// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int longestSubarray(std::vector<int> &nums) {
        int l = 0;
        int zeroes = 0, result = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                zeroes++;
            }
            while (zeroes > 1) {
                if (nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }
            result = std::max(result, r - l);
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 1, 0, 1}, 3},
        {{0, 1, 1, 1, 0, 1, 1, 0, 1}, 5},
        {{1, 1, 1}, 2},
        {{1, 0, 0, 0, 0}, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.longestSubarray(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
