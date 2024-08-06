// 40. Combination Sum II
// Difficulty: Medium

// Given a collection of candidate numbers (candidates) and a target number
// (target), find all unique combinations in candidates where the candidate
// numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output:
// [
// [1,2,2],
// [5]
// ]

// Constraints:
//     1 <= candidates.length <= 100
//     1 <= candidates[i] <= 50
//     1 <= target <= 30

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                  int               target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> result;
        std::vector<int>              curr;
        recurse(candidates, target, 0, curr, result);
        return result;
    }

  private:
    void recurse(std::vector<int> &candidates, int target, int i,
                 std::vector<int>              &curr,
                 std::vector<std::vector<int>> &result) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            if (candidates[j] > target) {
                break;
            }
            curr.push_back(candidates[j]);
            recurse(candidates, target - candidates[j], j + 1, curr, result);
            curr.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>,
                          std::vector<std::vector<int>>>>
        tests = {
            {{{10, 1, 2, 7, 6, 1, 5}, 8},
             {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}}},
            {{{2, 5, 2, 1, 2}, 5}, {{1, 2, 2}, {5}}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.combinationSum2(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
