// 1931. Painting a Grid With Three Different Colors
// Difficulty: Hard

// You are given two integers m and n. Consider an m x n grid where each cell is
// initially white. You can paint each cell red, green, or blue. All cells must
// be painted.

// Return the number of ways to color the grid with no two adjacent cells having
// the same color. Since the answer can be very large, return it modulo 109 + 7.

// Example 1:

// Input: m = 1, n = 1
// Output: 3
// Explanation: The three possible colorings are shown in the image above.

// Example 2:

// Input: m = 1, n = 2
// Output: 6
// Explanation: The six possible colorings are shown in the image above.

// Example 3:

// Input: m = 5, n = 5
// Output: 580986

// Constraints:

//     1 <= m <= 5
//     1 <= n <= 1000

#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
    const int MOD = 1e9 + 7;

  public:
    int colorTheGrid(int m, int n) {
        std::unordered_map<int, std::vector<int>> valid;

        int end = std::pow(3, m);
        for (int i = 0; i < end; i++) {
            std::vector<int> col(m);
            int              temp = i;
            for (int i = 0; i < m; i++) {
                col[i] = temp % 3;
                temp /= 3;
            }
            bool check = true;
            for (int i = 0; i < m - 1; i++) {
                if (col[i] == col[i + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                valid[i] = col;
            }
        }

        std::unordered_map<int, std::vector<int>> adj;
        for (auto &[i, col1] : valid) {
            for (auto &[j, col2] : valid) {
                bool check = true;
                for (int k = 0; k < m; k++) {
                    if (col1[k] == col2[k]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    adj[i].push_back(j);
                }
            }
        }

        std::vector<int> f(end);
        for (auto &[i, _] : valid) {
            f[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            std::vector<int> g(end);
            for (auto &[j, _] : valid) {
                for (int k : adj[j]) {
                    g[j] += f[k];
                    if (g[j] >= MOD) {
                        g[j] -= MOD;
                    }
                }
            }
            f = g;
        }

        int result = 0;
        for (int i : f) {
            result += i;
            if (result >= MOD) {
                result -= MOD;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, int>> tests = {
        {{1, 1}, 3},
        {{1, 2}, 6},
        {{5, 5}, 580986},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.colorTheGrid(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
