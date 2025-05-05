// 790. Domino and Tromino Tiling
// Difficulty: Medium

// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You
// may rotate these shapes.

// Given an integer n, return the number of ways to tile an 2 x n board. Since
// the answer may be very large, return it modulo 109 + 7.

// In a tiling, every square must be covered by a tile. Two tilings are
// different if and only if there are two 4-directionally adjacent cells on the
// board such that exactly one of the tilings has both squares occupied by a
// tile.

// Example 1:

// Input: n = 3
// Output: 5
// Explanation: The five different ways are show above.

// Example 2:

// Input: n = 1
// Output: 1

// Constraints:

//     1 <= n <= 1000

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    const int MOD = 1e9 + 7;

  public:
    int numTilings(int n) {
        int memo[1001][2] = {0};
        return recurse(n, 0, false, memo);
    }

  private:
    int recurse(int n, int i, bool prev, int memo[1001][2]) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return !prev;
        }
        if (memo[i][prev]) {
            return memo[i][prev];
        }
        if (prev) {
            return memo[i][prev] = ((long)recurse(n, i + 1, false, memo) +
                                    recurse(n, i + 1, true, memo)) %
                                   MOD;
        }
        return memo[i][prev] = (recurse(n, i + 1, false, memo) +
                                recurse(n, i + 2, false, memo) +
                                2L * recurse(n, i + 2, true, memo)) %
                               MOD;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {3, 5},
        {1, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numTilings(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
