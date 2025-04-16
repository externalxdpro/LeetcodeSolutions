// 2537. Count the Number of Good Subarrays
// Difficulty: Medium

// Given an integer array nums and an integer k, return the number of good
// subarrays of nums.

// A subarray arr is good if there are at least k pairs of indices (i, j) such
// that i < j and arr[i] == arr[j].

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1,1,1], k = 10
// Output: 1
// Explanation: The only good subarray is the array nums itself.

// Example 2:

// Input: nums = [3,1,4,3,2,2,4], k = 2
// Output: 4
// Explanation: There are 4 different good subarrays:
// - [3,1,4,3,2,2] that has 2 pairs.
// - [3,1,4,3,2,2,4] that has 3 pairs.
// - [1,4,3,2,2,4] that has 2 pairs.
// - [4,3,2,2,4] that has 2 pairs.

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i], k <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    long long countGood(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> counts;

        long long result = 0;
        int       same = 0, r = -1;
        for (int l = 0; l < nums.size(); l++) {
            while (same < k && r + 1 < nums.size()) {
                r++;
                same += counts[nums[r]];
                counts[nums[r]]++;
            }
            if (same >= k) {
                result += nums.size() - r;
            }
            counts[nums[l]]--;
            same -= counts[nums[l]];
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, long long>> tests =
        {
            {{{1, 1, 1, 1, 1}, 10}, 1},
            {{{3, 1, 4, 3, 2, 2, 4}, 2}, 4},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countGood(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
