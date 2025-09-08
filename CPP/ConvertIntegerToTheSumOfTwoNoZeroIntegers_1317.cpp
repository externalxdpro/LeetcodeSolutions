// 1317. Convert Integer to the Sum of Two No-Zero Integers
// Difficulty: Easy

// No-Zero integer is a positive integer that does not contain any 0 in its
// decimal representation.

// Given an integer n, return a list of two integers [a, b] where:

// a and b are No-Zero integers.
// a + b = n
// The test cases are generated so that there is at least one valid solution. If
// there are many valid solutions, you can return any of them.

// Example 1:

// Input: n = 2
// Output: [1,1]
// Explanation: Let a = 1 and b = 1.
// Both a and b are no-zero integers, and a + b = 2 = n.
// Example 2:

// Input: n = 11
// Output: [2,9]
// Explanation: Let a = 2 and b = 9.
// Both a and b are no-zero integers, and a + b = 11 = n.
// Note that there are other valid answers as [8, 3] that can be accepted.

// Constraints:

// 2 <= n <= 104

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> getNoZeroIntegers(int n) {
        for (int i = 0; i < n; i++) {
            if (hasZero(i) || hasZero(n - i)) {
                continue;
            }
            return {i, n - i};
        }
        return {};
    }

  private:
    bool hasZero(int n) {
        do {
            if (n % 10 == 0) {
                return true;
            }
            n /= 10;
        } while (n);
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::vector<int>>> tests = {
        {2, {1, 1}},
        {11, {2, 9}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.getNoZeroIntegers(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
