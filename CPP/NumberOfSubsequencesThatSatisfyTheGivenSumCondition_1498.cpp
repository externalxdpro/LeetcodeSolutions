// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// Difficulty: Medium

// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the
// minimum and maximum element on it is less or equal to target. Since the
// answer may be too large, return it modulo 109 + 7.

// Example 1:

// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)

// Example 2:

// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can
// have repeated numbers). [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

// Example 3:

// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two of them do not satisfy
// the condition ([6,7], [7]). Number of valid subsequences (63 - 2 = 61).

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 106
//     1 <= target <= 106

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int numSubseq(std::vector<int> &nums, int target) {
        const int MOD = 1e9 + 7;
        std::ranges::sort(nums);
        std::vector<int> pow(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            pow[i] = pow[i - 1] * 2 % MOD;
        }

        int result = 0;
        for (int l = 0; l < nums.size(); l++) {
            int r = std::ranges::upper_bound(nums, target - nums[l]) -
                    nums.begin() - 1;
            if (l <= r) {
                result = (result + pow[r - l]) % MOD;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{3, 5, 6, 7}, 9}, 4},
        {{{3, 3, 6, 8}, 10}, 6},
        {{{2, 3, 3, 4, 6, 7}, 12}, 61},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numSubseq(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
