// 3405. Count the Number of Arrays with K Matching Adjacent Elements
// Difficulty: Hard

// You are given three integers n, m, k. A good array arr of size n is defined
// as follows:

//     Each element in arr is in the inclusive range [1, m].
//     Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1]
//     == arr[i].

// Return the number of good arrays that can be formed.

// Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: n = 3, m = 2, k = 1

// Output: 4

// Explanation:

//     There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2,
//     2, 1]. Hence, the answer is 4.

// Example 2:

// Input: n = 4, m = 2, k = 2

// Output: 6

// Explanation:

//     The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1,
//     1], [2, 2, 1, 1] and [2, 2, 2, 1]. Hence, the answer is 6.

// Example 3:

// Input: n = 5, m = 2, k = 0

// Output: 2

// Explanation:

//     The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the
//     answer is 2.

// Constraints:

//     1 <= n <= 105
//     1 <= m <= 105
//     0 <= k <= n - 1

#include <array>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    const int MOD = 1e9 + 7;

  public:
    int countGoodArrays(int n, int m, int k) {
        std::vector<long long> fac(n), inv(n);

        fac[0] = 1;
        for (int i = 1; i < n; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }

        inv[n - 1] = modPow(fac[n - 1], MOD - 2);
        for (int i = n - 2; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }

        long long combs = fac[n - 1] * inv[k] % MOD * inv[n - k - 1] % MOD;
        long long pow = modPow(m - 1, n - k - 1);
        return combs * m % MOD * pow % MOD;
    }

  private:
    long long modPow(long long x, long long exp) {
        long long result = 1;
        x %= MOD;

        while (exp) {
            if (exp % 2 != 0) {
                result = (result * x) % MOD;
            }
            x = x * x % MOD;
            exp /= 2;
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::array<int, 3>, int>> tests = {
        {{3, 2, 1}, 4},
        {{4, 2, 2}, 6},
        {{5, 2, 0}, 2},
        {{6, 1, 2}, 0},
        {{5581, 58624, 4766}, 846088010},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countGoodArrays(test[0], test[1], test[2]);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
