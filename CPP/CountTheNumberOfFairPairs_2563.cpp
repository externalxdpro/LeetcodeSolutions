// 2563. Count the Number of Fair Pairs
// Difficulty: Medium

// Given a 0-indexed integer array nums of size n and two integers lower and
// upper, return the number of fair pairs.

// A pair (i, j) is fair if:

//     0 <= i < j < n, and
//     lower <= nums[i] + nums[j] <= upper

// Example 1:

// Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
// Output: 6
// Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and
// (1,5).

// Example 2:

// Input: nums = [1,7,9,2,5], lower = 11, upper = 11
// Output: 1
// Explanation: There is a single fair pair: (2,3).

// Constraints:

//     1 <= nums.length <= 105
//     nums.length == n
//     -109 <= nums[i] <= 109
//     -109 <= lower <= upper <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    long long countFairPairs(std::vector<int> &nums, int lower, int upper) {
        std::ranges::sort(nums);
        return lowerBound(nums, upper + 1) - lowerBound(nums, lower);
    }

  private:
    long long lowerBound(std::vector<int> &nums, int val) {
        int       l = 0, r = nums.size() - 1;
        long long result = 0;
        while (l < r) {
            if (nums[l] + nums[r] < val) {
                result += r - l++;
            } else {
                r--;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int>, long long>>
        tests = {
            {{{0, 1, 7, 4, 4, 5}, 3, 6}, 6},
            {{{1, 7, 9, 2, 5}, 11, 11}, 1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countFairPairs(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
