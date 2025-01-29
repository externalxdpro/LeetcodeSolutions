// 684. Redundant Connection
// Difficulty: Medium

// In this problem, a tree is an undirected graph that is connected and has no
// cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to
// n, with one additional edge added. The added edge has two different vertices
// chosen from 1 to n, and was not an edge that already existed. The graph is
// represented as an array edges of length n where edges[i] = [ai, bi] indicates
// that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n
// nodes. If there are multiple answers, return the answer that occurs last in
// the input.

// Example 1:

// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

// Example 2:

// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]

// Constraints:

//     n == edges.length
//     3 <= n <= 1000
//     edges[i].length == 2
//     1 <= ai < bi <= edges.length
//     ai != bi
//     There are no repeated edges.
//     The given graph is connected.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int>
    findRedundantConnection(std::vector<std::vector<int>> &edges) {
        std::vector<std::vector<int>> adj(edges.size() + 1);

        for (auto &e : edges) {
            std::vector<bool> visited(edges.size() + 1);
            if (isConnected(adj, e[0], e[1], visited)) {
                return e;
            }
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return {};
    }

  private:
    bool isConnected(std::vector<std::vector<int>> &adj, int src, int target,
                     std::vector<bool> &visited) {
        visited[src] = true;
        if (src == target) {
            return true;
        }

        bool found = false;
        for (int a : adj[src]) {
            if (!visited[a]) {
                found = found || isConnected(adj, a, target, visited);
            }
        }
        return found;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<int>>>
        tests = {
            {{{1, 2}, {1, 3}, {2, 3}}, {2, 3}},
            {{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}}, {1, 4}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findRedundantConnection(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
