// 2616. Minimize the Maximum Difference of Pairs
// Difficulty: Medium

// You are given a 0-indexed integer array nums and an integer p. Find p pairs
// of indices of nums such that the maximum difference amongst all the pairs is
// minimized. Also, ensure no index appears more than once amongst the p pairs.

// Note that for a pair of elements at the index i and j, the difference of this
// pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

// Return the minimum maximum difference among all p pairs. We define the
// maximum of an empty set to be zero.

// Example 1:

// Input: nums = [10,1,2,7,1,3], p = 2
// Output: 1
// Explanation: The first pair is formed from the indices 1 and 4, and the
// second pair is formed from the indices 2 and 5. The maximum difference is
// max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we
// return 1.

// Example 2:

// Input: nums = [4,2,1,2], p = 1
// Output: 0
// Explanation: Let the indices 1 and 3 form a pair. The difference of that pair
// is |2 - 2| = 0, which is the minimum we can attain.

// Constraints:

//     1 <= nums.length <= 105
//     0 <= nums[i] <= 109
//     0 <= p <= (nums.length)/2

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minimizeMax(std::vector<int> &nums, int p) {
        if (p == 0) {
            return 0;
        }
        std::ranges::sort(nums);

        int l = 0, r = nums.back() - nums[0];
        int result = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (hasPairs(nums, p, m)) {
                result = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return result;
    }

  private:
    bool hasPairs(std::vector<int> &nums, int p, int diff) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] <= diff) {
                count++;
                if (count == p) {
                    return true;
                }
                i++;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{10, 1, 2, 7, 1, 3}, 2}, 1},
        {{{4, 2, 1, 2}, 1}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimizeMax(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
