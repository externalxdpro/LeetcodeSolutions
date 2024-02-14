// Difficulty: Medium
// You are given an integer array nums of size n and a positive integer k.
// Divide the array into one or more arrays of size 3 satisfying the following
// conditions:
//     Each element of nums should be in exactly one array.
//     The difference between any two elements in one array is less than or
//     equal to k.
// Return a 2D array containing all the arrays. If it is impossible to satisfy
// the conditions, return an empty array. And if there are multiple answers,
// return any of them.

// Example 1:
// Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
// Output: [[1,1,3],[3,4,5],[7,8,9]]
// Explanation: We can divide the array into the following arrays: [1,1,3],
// [3,4,5] and [7,8,9]. The difference between any two elements in each array is
// less than or equal to 2. Note that the order of elements is not important.

// Example 2:
// Input: nums = [1,3,3,2,7,3], k = 3
// Output: []
// Explanation: It is not possible to divide the array satisfying all the
// conditions.

// Constraints:
//     n == nums.length
//     1 <= n <= 10^5
//     n is a multiple of 3.
//     1 <= nums[i] <= 10^5
//     1 <= k <= 10^5

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> divideArray(std::vector<int> &nums, int k) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> result(nums.size() / 3,
                                             std::vector<int>(3));

        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }

            result[i / 3][0] = nums[i];
            result[i / 3][1] = nums[i + 1];
            result[i / 3][2] = nums[i + 2];
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 3, 4, 8, 7, 9, 3, 5, 1}, 2},
        {{1, 3, 3, 2, 7, 3}, 3},
        {{15, 13, 12, 13, 12, 14, 12, 2,  3, 13, 12,
          14, 14, 13, 5,  12, 12, 2,  13, 2, 2},
         2},
    };

    Solution solution;
    for (auto &test : tests) {
        fmt::print("{}: ", test);
        auto result = solution.divideArray(test.first, test.second);
        fmt::print("{}\n", result);
    }

    return 0;
}
