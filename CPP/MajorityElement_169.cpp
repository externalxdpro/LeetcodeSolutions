// Difficulty: Easy
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You
// may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Constraints:
//     n == nums.length
//     1 <= n <= 5 * 10^4
//     -109 <= nums[i] <= 10^9

// Follow-up: Could you solve the problem in linear time and in O(1) space?

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

// O(n) time, O(n) space
// class Solution {
//   public:
//     int majorityElement(std::vector<int> &nums) {
//         std::unordered_map<int, int> occurences;
//         for (int i : nums) {
//             occurences[i]++;
//             if (occurences[i] > nums.size() / 2) {
//                 return i;
//             }
//         }

//         return 0;
//     }
// };

// O(n) time, O(1) space
class Solution {
  public:
    int majorityElement(std::vector<int> &nums) {
        int count = 1;
        int curr  = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (curr == nums[i]) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                curr  = nums[i];
                count = 1;
            }
        }

        return curr;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{3, 2, 3}, 3},
        {{2, 2, 1, 1, 1, 2, 2}, 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.majorityElement(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
