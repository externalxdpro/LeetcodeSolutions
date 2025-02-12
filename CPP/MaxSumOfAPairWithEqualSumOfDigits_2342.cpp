// 2342. Max Sum of a Pair With Equal Sum of Digits
// Difficulty: Medium

// You are given a 0-indexed array nums consisting of positive integers. You can
// choose two indices i and j, such that i != j, and the sum of digits of the
// number nums[i] is equal to that of nums[j].

// Return the maximum value of nums[i] + nums[j] that you can obtain over all
// possible indices i and j that satisfy the conditions.

// Example 1:

// Input: nums = [18,43,36,13,7]
// Output: 54
// Explanation: The pairs (i, j) that satisfy the conditions are:
// - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 +
// 36 = 54.
// - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 +
// 7 = 50. So the maximum sum that we can obtain is 54.

// Example 2:

// Input: nums = [10,12,19,14]
// Output: -1
// Explanation: There are no two numbers that satisfy the conditions, so we
// return -1.

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int maximumSum(std::vector<int> &nums) {
        std::unordered_map<int, std::priority_queue<int>> sums;
        for (int i : nums) {
            sums[sumDigits(i)].push(i);
        }
        int result = -1;
        for (auto &[_, pq] : sums) {
            if (pq.size() < 2) {
                continue;
            }
            int curr = pq.top();
            pq.pop();
            curr += pq.top();
            result = std::max(result, curr);
        }
        return result;
    }

  private:
    int sumDigits(int num) {
        int result = 0;
        while (num) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{18, 43, 36, 13, 7}, 54},
        {{10, 12, 19, 14}, -1},
        {{368, 369, 307, 304, 384, 138, 90, 279, 35, 396, 114, 328, 251, 364,
          300, 191, 438, 467, 183},
         835},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumSum(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
