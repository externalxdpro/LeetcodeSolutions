// 2338. Count the Number of Ideal Arrays
// Difficulty: Hard

// You are given two integers n and maxValue, which are used to describe an
// ideal array.

// A 0-indexed integer array arr of length n is considered ideal if the
// following conditions hold:

//     Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
//     Every arr[i] is divisible by arr[i - 1], for 0 < i < n.

// Return the number of distinct ideal arrays of length n. Since the answer may
// be very large, return it modulo 109 + 7.

// Example 1:

// Input: n = 2, maxValue = 5
// Output: 10
// Explanation: The following are the possible ideal arrays:
// - Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4],
// [1,5]
// - Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
// - Arrays starting with the value 3 (1 array): [3,3]
// - Arrays starting with the value 4 (1 array): [4,4]
// - Arrays starting with the value 5 (1 array): [5,5]
// There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.

// Example 2:

// Input: n = 5, maxValue = 3
// Output: 11
// Explanation: The following are the possible ideal arrays:
// - Arrays starting with the value 1 (9 arrays):
//    - With no other distinct values (1 array): [1,1,1,1,1]
//    - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2],
//    [1,1,2,2,2], [1,2,2,2,2]
//    - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3],
//    [1,1,3,3,3], [1,3,3,3,3]
// - Arrays starting with the value 2 (1 array): [2,2,2,2,2]
// - Arrays starting with the value 3 (1 array): [3,3,3,3,3]
// There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.

// Constraints:

//     2 <= n <= 104
//     1 <= maxValue <= 104

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    int MOD                   = 1e9 + 7;
    int factorialMemo[100000] = {0};

  public:
    int idealArrays(int n, int maxValue) {
        int memo[100000][15] = {0};
        for (int i = 1; i <= maxValue; i++) {
            memo[i][1] = 1;
            for (int j = 2; j * i <= maxValue; j++) {
                for (int k = 0; k < std::min(n, 14); k++) {
                    memo[i * j][k + 1] += memo[i][k];
                }
            }
        }
        long long result = 0;
        for (int i = 1; i <= maxValue; i++) {
            for (int j = 0; j <= std::min(n, 14); j++) {
                result = (result + inv(n - 1, n - j) * memo[i][j]) % MOD;
            }
        }
        return result;
    }

  private:
    long long power(long long a, long long b) {
        long long result = 1;
        while (b) {
            if (b & 1) {
                result = result * a % MOD;
            }
            a = a * a % MOD;
            b = b >> 1;
        }
        return result;
    }

    long long factorial(long long n) {
        if (n == 0) {
            return 1;
        }
        if (factorialMemo[n]) {
            return factorialMemo[n];
        }
        return factorialMemo[n] = n * factorial(n - 1) % MOD;
    }

    long long inv(long long a, long long b) {
        return (((factorial(a) * power(factorial(b), MOD - 2)) % MOD) *
                power(factorial(a - b), MOD - 2) % MOD);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, int>> tests = {
        {{2, 5}, 10},
        {{5, 3}, 11},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.idealArrays(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
