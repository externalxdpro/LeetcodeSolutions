// 632. Smallest Range Covering Elements from K Lists
// Difficulty: Hard

// You have k lists of sorted integers in non-decreasing order. Find the
// smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a
// < c if b - a == d - c.

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation:
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].

// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]

// Constraints:

//     nums.length == k
//     1 <= k <= 3500
//     1 <= nums[i].length <= 50
//     -105 <= nums[i][j] <= 105
//     nums[i] is sorted in non-decreasing order.

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> smallestRange(std::vector<std::vector<int>> &nums) {
        std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,
                            std::greater<>>
            pq;

        int max = std::numeric_limits<int>::min();
        int l = 0, r = std::numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); i++) {
            pq.emplace(nums[i][0], i, 0);
            max = std::max(max, nums[i][0]);
        }

        while (pq.size() == nums.size()) {
            const auto [min, i, j] = pq.top();
            pq.pop();

            if (max - min < r - l) {
                l = min, r = max;
            }

            if (j + 1 < nums[i].size()) {
                pq.emplace(nums[i][j + 1], i, j + 1);
                max = std::max(max, nums[i][j + 1]);
            }
        }

        return {l, r};
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<int>>>
        tests = {
            {{{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}}, {20, 24}},
            {{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, {1, 1}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.smallestRange(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
