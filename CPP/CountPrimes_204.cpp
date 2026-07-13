// 204. Count Primes
// Difficulty: Medium

// Given an integer n, return the number of prime numbers that are strictly less
// than n.

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0

// Constraints:

// 0 <= n <= 5 * 106

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int countPrimes(int n) {
        std::vector<bool> sieve(n, true);
        for (int i = 2; i < std::sqrt(n); i++) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j += i) {
                    sieve[j] = false;
                }
            }
        }

        int result = 0;
        for (size_t i = 2; i < sieve.size(); i++) {
            result += sieve[i];
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {10, 4},
        {0, 0},
        {1, 0},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.countPrimes(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
