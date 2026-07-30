// 219. Contains Duplicate II
// Difficulty: Easy

// Given an integer array nums and an integer k, return true if there are two
// distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
// - j) <= k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 0 <= k <= 105

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool containsNearbyDuplicate(std::vector<int> &nums, size_t k) {
        std::unordered_set<int> seen(nums.begin(),
                                     nums.begin() + std::min(k, nums.size()));
        if (seen.size() < std::min(k, nums.size())) {
            return true;
        }

        size_t l = 0;
        for (size_t r = k; r < nums.size(); r++) {
            if (seen.contains(nums[r])) {
                return true;
            }
            seen.insert(nums[r]);
            seen.erase(nums[l++]);
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, bool>> tests = {
        {{{1, 2, 3, 1}, 3}, true},
        {{{1, 0, 1, 1}, 1}, true},
        {{{1, 2, 3, 1, 2, 3}, 2}, false},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.containsNearbyDuplicate(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
