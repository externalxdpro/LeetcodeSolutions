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
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
        std::ranges::sort(nums);
        std::vector<int>              deg(nums.size());
        std::vector<int>              prev(nums.size(), -1);
        std::vector<std::vector<int>> adj(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] % nums[i] == 0) {
                    adj[i].push_back(j);
                    deg[j]++;
                }
            }
        }

        std::queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }

        int last = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                if (--deg[next] == 0) {
                    q.push(next);
                    prev[next] = curr;
                }
            }
            last = curr;
        }

        std::vector<int> result;
        for (int i = last; i != -1; i = prev[i]) {
            result.push_back(nums[i]);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1, 2, 3}, {3, 1}},
        {{1, 2, 4, 8}, {8, 4, 2, 1}},
        {{1}, {1}},
        {{3, 17}, {17}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        fmt::print("{}: ", test);
        auto result = solution.largestDivisibleSubset(test);
        fmt::print("{} {}\n", result, result == ans ? "✅" : "❌");
    }

    return 0;
}
