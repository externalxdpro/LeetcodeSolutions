// 3152. Special Array II
// Difficulty: Medium

// An array is considered special if every pair of its adjacent elements
// contains two numbers with different parity.

// You are given an array of integer nums and a 2D integer matrix queries, where
// for queries[i] = [fromi, toi] your task is to check that subarray
// nums[fromi..toi] is special or not.

// Return an array of booleans answer such that answer[i] is true if
// nums[fromi..toi] is special.

// Example 1:

// Input: nums = [3,4,1,2,6], queries = [[0,4]]

// Output: [false]

// Explanation:

// The subarray is [3,4,1,2,6]. 2 and 6 are both even.

// Example 2:

// Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

// Output: [false,true]

// Explanation:

//     The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this
//     query is false. The subarray is [1,6]. There is only one pair: (1,6) and
//     it contains numbers with different parity. So the answer to this query is
//     true.

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 105
//     1 <= queries.length <= 105
//     queries[i].length == 2
//     0 <= queries[i][0] <= queries[i][1] <= nums.length - 1

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<bool>
    isArraySpecial(const std::vector<int>              &nums,
                   const std::vector<std::vector<int>> &queries) {
        std::vector<bool> result(queries.size());
        std::vector<int>  bad;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                bad.push_back(i);
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            const std::vector<int> &q = queries[i];
            int                     l = q[0], r = q[1];
            bool                    found = search(bad, l + 1, r);
            result[i]                     = !found;
        }

        return result;
    }

  private:
    bool search(const std::vector<int> &bad, int start, int end) {
        int l = 0, r = bad.size() - 1;
        while (l <= r) {
            int m    = l + (r - l) / 2;
            int curr = bad[m];
            if (curr < start) {
                l = m + 1;
            } else if (curr > end) {
                r = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::vector<int>, std::vector<std::vector<int>>>,
                  std::vector<bool>>>
        tests = {
            {{{3, 4, 1, 2, 6}, {{0, 4}}}, {false}},
            {{{4, 3, 1, 6}, {{0, 2}, {2, 3}}}, {false, true}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.isArraySpecial(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
