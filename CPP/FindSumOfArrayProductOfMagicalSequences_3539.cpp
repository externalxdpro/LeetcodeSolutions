// 3539. Find Sum of Array Product of Magical Sequences
// Difficulty: Hard

// You are given two integers, m and k, and an integer array nums.
// A sequence of integers seq is called magical if:

//     seq has a size of m.
//     0 <= seq[i] < nums.length
//     The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k
//     set bits.

// The array product of this sequence is defined as prod(seq) = (nums[seq[0]] *
// nums[seq[1]] * ... * nums[seq[m - 1]]).

// Return the sum of the array products for all valid magical sequences.

// Since the answer may be large, return it modulo 109 + 7.

// A set bit refers to a bit in the binary representation of a number that has a
// value of 1.

// Example 1:

// Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]

// Output: 991600007

// Explanation:

// All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array
// product of 1013.

// Example 2:

// Input: m = 2, k = 2, nums = [5,4,3,2,1]

// Output: 170

// Explanation:

// The magical sequences are [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 2], [1,
// 3], [1, 4], [2, 0], [2, 1], [2, 3], [2, 4], [3, 0], [3, 1], [3, 2], [3, 4],
// [4, 0], [4, 1], [4, 2], and [4, 3].

// Example 3:

// Input: m = 1, k = 1, nums = [28]

// Output: 28

// Explanation:

// The only magical sequence is [0].

// Constraints:

//     1 <= k <= m <= 30
//     1 <= nums.length <= 50
//     1 <= nums[i] <= 108

#include <algorithm>
#include <bitset>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    const int MOD = 1e9 + 7;

  public:
    int magicalSum(int m, int k, std::vector<int> &nums) {
        std::vector<std::vector<std::vector<std::vector<int>>>> memo(
            m + 1, std::vector(k + 1, std::vector(nums.size(),
                                                  std::vector(m + 1, -1))));
        return dp(m, k, nums, 0, 0, memo);
    }

  private:
    long long
    dp(int m, int k, std::vector<int> &nums, int i, int flag,
       std::vector<std::vector<std::vector<std::vector<int>>>> &memo) {
        if (m < 0 || k < 0 || m + __builtin_popcount(flag) < k) {
            return 0;
        }
        if (m == 0) {
            if (k == __builtin_popcount(flag)) {
                return 1;
            } else {
                return 0;
            }
        }
        if (i >= nums.size()) {
            return 0;
        }
        if (memo[m][k][i][flag] != -1) {
            return memo[m][k][i][flag];
        }
        long long result = 0;
        for (int c = 0; c <= m; c++) {
            long long mul = comb(m, c) * modPow(nums[i], c, MOD) % MOD;
            int f2 = flag + c;
            result += mul * dp(m - c, k - (f2 % 2), nums, i + 1, f2 / 2, memo);
        }

        return memo[m][k][i][flag] = result % MOD;
    }

    long long comb(int n, int r) {
        if (r == 0)
            return 1;
        if (r > n / 2)
            return comb(n, n - r);

        long long result = 1;

        for (int k = 1; k <= r; ++k) {
            result *= n - k + 1;
            result /= k;
        }

        return result;
    }

    long long modPow(long long x, unsigned exp, int mod) {
        if (exp == 0)
            return 1;
        const int bM = 31 - std::countl_zero(exp);
        std::bitset<32> B(exp);
        long long y = x;
        for (int b = bM - 1; b >= 0; b--)
            y = (y * y % mod) * (B[b] ? x : 1) % mod;
        return y;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<int, int, std::vector<int>>, int>> tests =
        {
            {{5, 5, {1, 10, 100, 10000, 1000000}}, 991600007},
            {{2, 2, {5, 4, 3, 2, 1}}, 170},
            {{1, 1, {28}}, 28},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.magicalSum(std::get<0>(test), std::get<1>(test),
                                          std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
