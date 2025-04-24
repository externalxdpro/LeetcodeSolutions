// 2799. Count Complete Subarrays in an Array
// Difficulty: Medium

// You are given an array nums consisting of positive integers.

// We call a subarray of an array complete if the following condition is
// satisfied:

//     The number of distinct elements in the subarray is equal to the number of
//     distinct elements in the whole array.

// Return the number of complete subarrays.

// A subarray is a contiguous non-empty part of an array.

// Example 1:

// Input: nums = [1,3,1,2,2]
// Output: 4
// Explanation: The complete subarrays are the following: [1,3,1,2],
// [1,3,1,2,2], [3,1,2] and [3,1,2,2].

// Example 2:

// Input: nums = [5,5,5,5]
// Output: 10
// Explanation: The array consists only of the integer 5, so any subarray is
// complete. The number of subarrays that we can choose is 10.

// Constraints:

//     1 <= nums.length <= 1000
//     1 <= nums[i] <= 2000

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int countCompleteSubarrays(std::vector<int> &nums) {
        std::unordered_set<int>      distinct(nums.begin(), nums.end());
        std::unordered_map<int, int> counts;
        int                          r      = 0;
        int                          result = 0;
        for (int l = 0; l < nums.size(); l++) {
            if (l > 0) {
                int rm = nums[l - 1];
                counts[rm]--;
                if (counts[rm] == 0) {
                    counts.erase(rm);
                }
            }
            while (r < nums.size() && counts.size() < distinct.size()) {
                int add = nums[r];
                counts[add]++;
                r++;
            }
            if (counts.size() == distinct.size()) {
                result += nums.size() - r + 1;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 3, 1, 2, 2}, 4},
        {{5, 5, 5, 5}, 10},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countCompleteSubarrays(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
