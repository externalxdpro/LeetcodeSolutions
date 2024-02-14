// Difficulty: Hard
// For an integer array nums, an inverse pair is a pair of integers [i, j] where
// 0 <= i < j < nums.length and nums[i] > nums[j].
// Given two integers n and k, return the number of different arrays consist of
// numbers from 1 to n such that there are exactly k inverse pairs. Since the
// answer can be huge, return it modulo 109 + 7.

// Example 1:
// Input: n = 3, k = 0
// Output: 1
// Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has
// exactly 0 inverse pairs.

// Example 2:
// Input: n = 3, k = 1
// Output: 2
// Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

// Constraints:
//     1 <= n <= 1000
//     0 <= k <= 1000

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

// Recursion w/ memo
// class Solution {
//   public:
//     int kInversePairs(int n, int k) {
//         std::vector<std::vector<int>> memo(n + 1, std::vector(k + 1, -1));
//         return recurse(n, k, memo);
//     }

//   private:
//     int recurse(int n, int k, std::vector<std::vector<int>> &memo) {

//         if (k == 0) {
//             return 1;
//         }
//         if (k < 0) {
//             return 0;
//         }

//         if (memo[n][k] != -1) {
//             return memo[n][k];
//         }

//         const int MOD    = 1'000'000'007;
//         int       result = 0;
//         for (int i = 0; i < n; i++) {
//             result += recurse(n - 1, k - i, memo);
//             result %= MOD;
//         }

//         memo[n][k] = result;
//         return memo[n][k];
//     }
// };

// Bottom up
class Solution {
  public:
    int kInversePairs(int n, int k) {
        const int                     MOD = 1'000'000'007;
        std::vector<std::vector<int>> memo(n + 1, std::vector(k + 1, 0));
        for (int i = 0; i <= n; i++) {
            memo[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int result = 0;
                for (int l = 0; l < std::min(i, j + 1); l++) {
                    result += memo[i - 1][j - l];
                    result %= MOD;
                }
                memo[i][j] = result;
            }
        }
        return memo[n][k];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {3, 0},
        {3, 1},
        {1000, 1000},
    };

    Solution solution;
    for (auto &test : tests) {
        auto result = solution.kInversePairs(test.first, test.second);
        fmt::print("{}: {}\n", test, result);
    }

    return 0;
}
