// 191. Number of 1 Bits
// Difficulty: Easy

// Given a positive integer n, write a function that returns the number of set
// bits in its binary representation (also known as the Hamming weight).

// Example 1:

// Input: n = 11

// Output: 3

// Explanation:

// The input binary string 1011 has a total of three set bits.

// Example 2:

// Input: n = 128

// Output: 1

// Explanation:

// The input binary string 10000000 has a total of one set bit.

// Example 3:

// Input: n = 2147483645

// Output: 30

// Explanation:

// The input binary string 1111111111111111111111111111101 has a total of thirty
// set bits.

// Constraints:

// 1 <= n <= 231 - 1

// Follow up: If this function is called many times, how would you optimize it?

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int hammingWeight(int n) {
        int result = 0;
        while (n) {
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {11, 3},
        {128, 1},
        {2147483645, 30},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.hammingWeight(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
