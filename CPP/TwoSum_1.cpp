// Difficulty: Easy
// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:
//     2 <= nums.length <= 10^4
//     -10^9 <= nums[i] <= 10^9
//     -10^9 <= target <= 10^9
//     Only one valid answer exists.

// Follow-up: Can you come up with an algorithm that is less than O(n2) time
// complexity?

#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

// std::vector<int> twoSum(std::vector<int> &nums, int target) {
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = 0; j < nums.size(); j++) {
//             if (i == j) {
//                 continue;
//             }

//             if (nums[i] + nums[j] == target) {
//                 return {i, j};
//             }
//         }
//     }
//     return {};
// }

// follow up
std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        if (seen.contains(target - nums[i])) {
            return {seen[target - nums[i]], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6},
    };

    for (auto test : tests) {
        fmt::print("{}: {}\n", test, twoSum(test.first, test.second));
    }

    return 0;
}
