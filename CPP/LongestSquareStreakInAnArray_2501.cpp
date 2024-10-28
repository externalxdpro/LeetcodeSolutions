// 2501. Longest Square Streak in an Array
// Difficulty: Medium

// You are given an integer array nums. A subsequence of nums is called a square
// streak if:

//     The length of the subsequence is at least 2, and
//     after sorting the subsequence, each element (except the first element) is
//     the square of the previous number.

// Return the length of the longest square streak in nums, or return -1 if there
// is no square streak.

// A subsequence is an array that can be derived from another array by deleting
// some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [4,3,6,16,8,2]
// Output: 3
// Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes
// [2,4,16].
// - 4 = 2 * 2.
// - 16 = 4 * 4.
// Therefore, [4,16,2] is a square streak.
// It can be shown that every subsequence of length 4 is not a square streak.

// Example 2:

// Input: nums = [2,3,5,6,7]
// Output: -1
// Explanation: There is no square streak in nums so return -1.

// Constraints:

//     2 <= nums.length <= 105
//     2 <= nums[i] <= 105

#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int longestSquareStreak(const std::vector<int> &nums) {
        const std::unordered_set<long long> set(nums.begin(), nums.end());
        int                                 result = -1;

        for (int i = 0; i < nums.size(); i++) {
            long long curr   = nums[i];
            int       streak = 1;
            while (set.contains(curr * curr)) {
                curr *= curr;
                streak++;
            }
            if (streak != 1 && streak > result) {
                result = streak;
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{4, 3, 6, 16, 8, 2}, 3},
        {{2, 3, 5, 6, 7}, -1},
        {{4, 16, 256, 65536}, 4},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.longestSquareStreak(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
