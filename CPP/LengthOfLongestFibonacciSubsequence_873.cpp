// 873. Length of Longest Fibonacci Subsequence
// Difficulty: Medium

// A sequence x1, x2, ..., xn is Fibonacci-like if:

//     n >= 3
//     xi + xi+1 == xi+2 for all i + 2 <= n

// Given a strictly increasing array arr of positive integers forming a
// sequence, return the length of the longest Fibonacci-like subsequence of arr.
// If one does not exist, return 0.

// A subsequence is derived from another sequence arr by deleting any number of
// elements (including none) from arr, without changing the order of the
// remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6,
// 7, 8].

// Example 1:

// Input: arr = [1,2,3,4,5,6,7,8]
// Output: 5
// Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].

// Example 2:

// Input: arr = [1,3,7,11,12,14,18]
// Output: 3
// Explanation: The longest subsequence that is fibonacci-like: [1,11,12],
// [3,11,14] or [7,11,18].

// Constraints:

//     3 <= arr.length <= 1000
//     1 <= arr[i] < arr[i + 1] <= 109

#include <algorithm>
#include <array>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int lenLongestFibSubseq(std::vector<int> &arr) {
        std::array<std::array<int, 1000>, 1000> dp;
        std::unordered_map<int, int>            indexes;
        int                                     result = 0;

        for (int j = 0; j < arr.size(); j++) {
            indexes[arr[j]] = j;
            for (int i = 0; i < j; i++) {
                int diff = arr[j] - arr[i];
                int h    = indexes.contains(diff) ? indexes[diff] : -1;
                if (diff < arr[i] && h >= 0) {
                    dp[i][j] = dp[h][i] + 1;
                } else {
                    dp[i][j] = 2;
                }
                result = std::max(result, dp[i][j]);
            }
        }
        return result > 2 ? result : 0;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 3, 4, 5, 6, 7, 8}, 5},
        {{1, 3, 7, 11, 12, 14, 18}, 3},
        {{1, 3, 5}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.lenLongestFibSubseq(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
