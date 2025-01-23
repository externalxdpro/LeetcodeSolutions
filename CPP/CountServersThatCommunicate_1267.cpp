// 1267. Count Servers that Communicate
// Difficulty: Medium

// You are given a map of a server center, represented as a m * n integer matrix
// grid, where 1 means that on that cell there is a server and 0 means that it
// is no server. Two servers are said to communicate if they are on the same row
// or on the same column.

// Return the number of servers that communicate with any other server.

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 0
// Explanation: No servers can communicate with others.

// Example 2:

// Input: grid = [[1,0],[1,1]]
// Output: 3
// Explanation: All three servers can communicate with at least one other
// server.

// Example 3:

// Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
// Output: 4
// Explanation: The two servers in the first row can communicate with each
// other. The two servers in the third column can communicate with each other.
// The server at right bottom corner can't communicate with any other server.

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m <= 250
//     1 <= n <= 250
//     grid[i][j] == 0 or 1

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int countServers(std::vector<std::vector<int>> &grid) {
        std::vector<int> rowCounts(grid.size());
        std::vector<int> colCounts(grid[0].size());
        int              result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    rowCounts[i]++;
                    colCounts[j]++;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (rowCounts[i] > 1 || colCounts[j] > 1) {
                    result++;
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 0}, {0, 1}}, 0},
        {{{1, 0}, {1, 1}}, 3},
        {{{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}, 4},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countServers(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
