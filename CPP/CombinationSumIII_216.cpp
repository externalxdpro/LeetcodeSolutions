// 216. Combination Sum III
// Difficulty: Medium

// Find all valid combinations of k numbers that sum up to n such that the
// following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain
// the same combination twice, and the combinations may be returned in any
// order.

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is
// 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

// Constraints:

// 2 <= k <= 9
// 1 <= n <= 60

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        recurse(k, n, 1, 0, temp, result);
        return result;
    }

  private:
    void recurse(int k, int n, int i, int sum, std::vector<int> &curr,
                 std::vector<std::vector<int>> &result) {
        if (curr.size() > k) {
            return;
        }
        if (curr.size() == k && sum == n) {
            result.push_back(curr);
            return;
        }
        if (i > 9) {
            return;
        }

        curr.push_back(i);
        recurse(k, n, i + 1, sum + i, curr, result);
        curr.pop_back();

        recurse(k, n, i + 1, sum, curr, result);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, std::vector<std::vector<int>>>>
        tests = {
            {{3, 7}, {{1, 2, 4}}},
            {{3, 9}, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}}},
            {{4, 1}, {}},
            {{9, 45}, {{1, 2, 3, 4, 5, 6, 7, 8, 9}}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.combinationSum3(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
