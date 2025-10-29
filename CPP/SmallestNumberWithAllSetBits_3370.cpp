// 3370. Smallest Number With All Set Bits
// Difficulty: Easy

// You are given a positive number n.

// Return the smallest number x greater than or equal to n, such that the binary
// representation of x contains only

// Example 1:

// Input: n = 5

// Output: 7

// Explanation:

// The binary representation of 7 is "111".

// Example 2:

// Input: n = 10

// Output: 15

// Explanation:

// The binary representation of 15 is "1111".

// Example 3:

// Input: n = 3

// Output: 3

// Explanation:

// The binary representation of 3 is "11".

// Constraints:

//     1 <= n <= 1000

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int smallestNumber(int n) {
        int result = 0;
        while (result < n) {
            result = result * 2 + 1;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {5, 7},
        {10, 15},
        {3, 3},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.smallestNumber(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
