// Difficulty: Medium
// You are given a 0-indexed integer array nums. You can rearrange the elements
// of nums to any order (including the given order). Let prefix be the array
// containing the prefix sums of nums after rearranging it. In other words,
// prefix[i] is the sum of the elements from 0 to i in nums after rearranging
// it. The score of nums is the number of positive integers in the array prefix.

// Return the maximum score you can achieve.

// Example 1:
// Input: nums = [2,-1,0,1,-3,3,-3]
// Output: 6
// Explanation: We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
// prefix = [2,5,6,5,2,2,-1], so the score is 6.
// It can be shown that 6 is the maximum score we can obtain.

// Example 2:
// Input: nums = [-2,-3,0]
// Output: 0
// Explanation: Any rearrangement of the array will result in a score of 0.

// Constraints:
//     1 <= nums.length <= 10^5
//     -10^6 <= nums[i] <= 10^6

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

namespace rv = std::views;

// faster??
// int maxScore(std::vector<int> &nums) {
//     std::vector<long> copy(nums.begin(), nums.end());
//     std::ranges::sort(copy, std::ranges::greater());
//     std::inclusive_scan(copy.begin(), copy.end(), copy.begin());
//     copy.erase(
//         std::remove_if(copy.begin(), copy.end(), [](auto i) { return i <= 0;
//         }), copy.end());

//     return copy.size();
// }

int maxScore(std::vector<int> &nums) {
    std::vector<long> newNums;
    std::ranges::sort(nums, std::ranges::greater());

    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
            if (nums[0] <= 0) {
                return 0;
            }
            newNums.push_back(nums[0]);
            continue;
        }

        long sum = (long)nums[i] + (long)newNums[i - 1];
        if (sum <= 0) {
            break;
        }

        newNums.push_back(sum);
    }

    return newNums.size();
}

int main() {
    std::vector<std::vector<int>> tests = {
        {2, -1, 0, 1, -3, 3, -3},
        {-2, -3, 0},
    };

    for (auto test : tests) {
        std::cout << maxScore(test) << std::endl;
    }

    return 0;
}
