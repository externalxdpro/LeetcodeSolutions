// Difficulty: Medium
// Given an integer n, return the least number of perfect square numbers that
// sum to n.
// A perfect square is an integer that is the square of an integer; in other
// words, it is the product of some integer with itself. For example, 1, 4, 9,
// and 16 are perfect squares while 3 and 11 are not.

// Example 1:
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

// Example 2:
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

// Constraints:
//     1 <= n <= 10^4

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int numSquares(int n) {
        std::vector<int> squares;
        std::vector<int> memo(n + 1, -1);
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        return dp(n, squares, memo);
    }

  private:
    int dp(int n, std::vector<int> &squares, std::vector<int> &memo) {
        if (n <= 0) {
            return 0;
        }

        if (memo[n] != -1) {
            return memo[n];
        }

        int min = INT_MAX;
        for (int i = 0; i < squares.size() && squares[i] <= n; i++) {
            int result = dp(n - squares[i], squares, memo);
            if (result < min) {
                min = result + 1;
            }
        }

        memo[n] = min;
        return min;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {4, 1},
        {12, 3},
        {13, 2},
        {32, 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numSquares(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
