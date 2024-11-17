// 862. Shortest Subarray with Sum at Least K
// Difficulty: Hard

// Given an integer array nums and an integer k, return the length of the
// shortest non-empty subarray of nums with a sum of at least k. If there is no
// such subarray, return -1.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [1], k = 1
// Output: 1

// Example 2:

// Input: nums = [1,2], k = 4
// Output: -1

// Example 3:

// Input: nums = [2,-1,2], k = 3
// Output: 3

// Constraints:

//     1 <= nums.length <= 105
//     -105 <= nums[i] <= 105
//     1 <= k <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <queue>
#include <vector>

class Solution {
  public:
    int shortestSubarray(std::vector<int> &nums, int k) {
        int min = std::numeric_limits<int>::max();
        std::priority_queue<std::pair<long long, int>,
                            std::vector<std::pair<long long, int>>,
                            std::greater<>>
                  pq;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum >= k) {
                min = std::min(min, i + 1);
            }
            while (!pq.empty() && sum - pq.top().first >= k) {
                min = std::min(min, i - pq.top().second);
                pq.pop();
            }
            pq.emplace(sum, i);
        }
        return min == std::numeric_limits<int>::max() ? -1 : min;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{1}, 1}, 1},
        {{{1, 2}, 4}, -1},
        {{{2, -1, 2}, 3}, 3},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.shortestSubarray(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
