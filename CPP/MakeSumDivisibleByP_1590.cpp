// 1590. Make Sum Divisible by P
// Difficulty: Medium

// Given an array of positive integers nums, remove the smallest subarray
// (possibly empty) such that the sum of the remaining elements is divisible by
// p. It is not allowed to remove the whole array.

// Return the length of the smallest subarray that you need to remove, or -1 if
// it's impossible.

// A subarray is defined as a contiguous block of elements in the array.

// Example 1:

// Input: nums = [3,1,4,2], p = 6
// Output: 1
// Explanation: The sum of the elements in nums is 10, which is not divisible
// by 6. We can remove the subarray [4], and the sum of the remaining elements
// is 6, which is divisible by 6.

// Example 2:

// Input: nums = [6,3,5,2], p = 9
// Output: 2
// Explanation: We cannot remove a single element to get a sum divisible by 9.
// The best way is to remove the subarray [5,2], leaving us with [6,3] with
// sum 9.

// Example 3:

// Input: nums = [1,2,3], p = 3
// Output: 0
// Explanation: Here the sum is 6. which is already divisible by 3. Thus we do
// not need to remove anything.

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 109
//     1 <= p <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int minSubarray(std::vector<int> &nums, int p) {
        int target = std::accumulate(nums.begin(), nums.end(), 0ll) % p;
        if (target == 0) {
            return 0;
        }

        std::unordered_map<int, int> map{{0, -1}};
        int                          curr = 0, minLen = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            curr       = (curr + nums[i]) % p;
            int needed = (curr - target + p) % p;

            if (map.contains(needed)) {
                minLen = std::min(minLen, i - map[needed]);
            }

            map[curr] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{3, 1, 4, 2}, 6}, 1},
        {{{6, 3, 5, 2}, 9}, 2},
        {{{1, 2, 3}, 3}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minSubarray(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
