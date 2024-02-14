// Difficulty: Medium
// Given a set of distinct positive integers nums, return the largest subset
// answer such that every pair (answer[i], answer[j]) of elements in this subset
// satisfies:
//     answer[i] % answer[j] == 0, or
//     answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

// Example 1:
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.

// Example 2:
// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]

// Constraints:
//     1 <= nums.length <= 1000
//     1 <= nums[i] <= 2 * 10^9
//     All the integers in nums are unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <vector>

// Recursive w/ memo, too slow
// class Solution {
//   public:
//     std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
//         std::ranges::sort(nums);

//         std::map<std::pair<int, int>, std::vector<int>> memo;
//         std::vector<int> result = dp(nums, 0, -1, memo);

//         fmt::print("{}\n", memo);
//         return result;
//     }

//   private:
//     std::vector<int> dp(std::vector<int> &nums, int i, int prev,
//                         std::map<std::pair<int, int>, std::vector<int>>
//                         &memo) {
//         if (i >= nums.size()) {
//             return {};
//         }

//         if (memo.contains({i, prev})) {
//             return memo[{i, prev}];
//         }

//         std::vector<int> skip = dp(nums, i + 1, prev, memo);
//         // skip.insert(skip.begin(), nums[i]);
//         // skip.push_back(nums[i]);

//         std::vector<int> take;
//         if (prev == -1 || nums[i] % nums[prev] == 0) {
//             take = dp(nums, i + 1, i, memo);
//             // take.insert(take.begin(), nums[i]);
//             take.push_back(nums[i]);
//         }

//         // if (skip.size() > take.size()) {
//         //     memo[{i, prev}] = skip;
//         // } else {
//         //     memo[{i, prev}] = take;
//         // }
//         memo[{i, prev}] = std::max(skip, take);
//         return memo[{i, prev}];
//     }
// };

// Bottom up
class Solution {
  public:
    std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
        if (nums.size() == 1) {
            return nums;
        }

        std::ranges::sort(nums);
        std::vector<std::vector<int>> memo(nums.size());
        memo.back() = {nums.back()};

        int size  = 0;
        int index = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int tempSize  = 0;
            int tempIndex = -1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] % nums[i] == 0 && memo[j].size() > tempSize) {
                    tempSize  = memo[j].size();
                    tempIndex = j;
                }
            }

            memo[i] = {nums[i]};

            if (tempIndex != -1) {
                memo[i].insert(memo[i].end(), memo[tempIndex].begin(),
                               memo[tempIndex].end());
            }

            if (size < memo[i].size()) {
                size  = memo[i].size();
                index = i;
            }
        }

        return memo[index];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1, 2, 3}, {1, 2}},
        {{1, 2, 4, 8}, {1, 2, 4, 8}},
        {{1}, {1}},
        {{3, 17}, {3}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        fmt::print("{}: ", test);
        auto result = solution.largestDivisibleSubset(test);
        fmt::print("{} {}\n", result, result == ans ? "✅" : "❌");
    }

    return 0;
}
