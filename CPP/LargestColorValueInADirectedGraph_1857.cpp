// 1857. Largest Color Value in a Directed Graph
// Difficulty: Hard

// There is a directed graph of n colored nodes and m edges. The nodes are
// numbered from 0 to n - 1.

// You are given a string colors where colors[i] is a lowercase English letter
// representing the color of the ith node in this graph (0-indexed). You are
// also given a 2D array edges where edges[j] = [aj, bj] indicates that there is
// a directed edge from node aj to node bj.

// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk
// such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The
// color value of the path is the number of nodes that are colored the most
// frequently occurring color along that path.

// Return the largest color value of any valid path in the given graph, or -1 if
// the graph contains a cycle.

// Example 1:

// Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
// Output: 3
// Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a"
// (red in the above image).

// Example 2:

// Input: colors = "a", edges = [[0,0]]
// Output: -1
// Explanation: There is a cycle from 0 to 0.

// Constraints:

//     n == colors.length
//     m == edges.length
//     1 <= n <= 105
//     0 <= m <= 105
//     colors consists of lowercase English letters.
//     0 <= aj, bj < n

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int largestPathValue(std::string                    colors,
                         std::vector<std::vector<int>> &edges) {
        int                           n = colors.size();
        std::vector<std::vector<int>> adj(n);
        std::vector<int>              inDegree(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }

        std::vector<std::vector<int>> memo(n, std::vector(26, 0));
        std::queue<int>               q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        int max     = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited++;
            int col = colors[curr] - 'a';
            memo[curr][col]++;
            max = std::max(max, memo[curr][col]);

            for (int next : adj[curr]) {
                for (int i = 0; i < 26; i++) {
                    memo[next][i] = std::max(memo[next][i], memo[curr][i]);
                }
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return visited == n ? max : -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::string, std::vector<std::vector<int>>>, int>>
        tests = {
            {{"abaca", {{0, 1}, {0, 2}, {2, 3}, {3, 4}}}, 3},
            {{"a", {{0, 0}}}, -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.largestPathValue(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
