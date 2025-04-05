// 1863. Sum of All Subset XOR Totals
// Difficulty: Easy

// The XOR total of an array is defined as the bitwise XOR of all its elements,
// or 0 if the array is empty.

//     For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.

// Given an array nums, return the sum of all XOR totals for every subset of
// nums.

// Note: Subsets with the same elements should be counted multiple times.

// An array a is a subset of an array b if a can be obtained from b by deleting
// some (possibly zero) elements of b.

// Example 1:

// Input: nums = [1,3]
// Output: 6
// Explanation: The 4 subsets of [1,3] are:
// - The empty subset has an XOR total of 0.
// - [1] has an XOR total of 1.
// - [3] has an XOR total of 3.
// - [1,3] has an XOR total of 1 XOR 3 = 2.
// 0 + 1 + 3 + 2 = 6

// Example 2:

// Input: nums = [5,1,6]
// Output: 28
// Explanation: The 8 subsets of [5,1,6] are:
// - The empty subset has an XOR total of 0.
// - [5] has an XOR total of 5.
// - [1] has an XOR total of 1.
// - [6] has an XOR total of 6.
// - [5,1] has an XOR total of 5 XOR 1 = 4.
// - [5,6] has an XOR total of 5 XOR 6 = 3.
// - [1,6] has an XOR total of 1 XOR 6 = 7.
// - [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
// 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28

// Example 3:

// Input: nums = [3,4,5,6,7,8]
// Output: 480
// Explanation: The sum of all XOR totals for every subset is 480.

// Constraints:

//     1 <= nums.length <= 12
//     1 <= nums[i] <= 20

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int subsetXORSum(std::vector<int> &nums) { return recurse(nums, 0, 0); }

  private:
    int recurse(std::vector<int> &nums, int i, int sum) {
        if (i == nums.size()) {
            return sum;
        }
        int take = recurse(nums, i + 1, sum ^ nums[i]);
        int skip = recurse(nums, i + 1, sum);
        return take + skip;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 3}, 6},
        {{5, 1, 6}, 28},
        {{3, 4, 5, 6, 7, 8}, 480},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.subsetXORSum(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
