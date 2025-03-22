// 2685. Count the Number of Complete Components
// Difficulty: Medium

// You are given an integer n. There is an undirected graph with n vertices,
// numbered from 0 to n - 1. You are given a 2D integer array edges where
// edges[i] = [ai, bi] denotes that there exists an undirected edge connecting
// vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path
// between any two vertices, and no vertex of the subgraph shares an edge with a
// vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between
// every pair of its vertices.

// Example 1:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components
// of this graph are complete.

// Example 2:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since
// there is an edge between every pair of two vertices. On the other hand, the
// component containing vertices 3, 4, and 5 is not complete since there is no
// edge between vertices 4 and 5. Thus, the number of complete components in
// this graph is 1.

// Constraints:

//     1 <= n <= 50
//     0 <= edges.length <= n * (n - 1) / 2
//     edges[i].length == 2
//     0 <= ai, bi <= n - 1
//     ai != bi
//     There are no repeated edges.

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int countCompleteComponents(int n, std::vector<std::vector<int>> &edges) {
        std::vector<std::vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        std::vector<bool> visited(n);
        int               result = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            std::vector<int> nodes;
            std::queue<int>  q{{i}};
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                nodes.push_back(curr);
                for (int next : adj[curr]) {
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }

            bool isComplete = true;
            for (int node : nodes) {
                if (adj[node].size() != nodes.size() - 1) {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete) {
                result++;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>, int>>
        tests = {
            {{6, {{0, 1}, {0, 2}, {1, 2}, {3, 4}}}, 3},
            {{6, {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}}}, 1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countCompleteComponents(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
