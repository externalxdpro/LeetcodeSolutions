// 2493. Divide Nodes Into the Maximum Number of Groups
// Difficulty: Hard

// You are given a positive integer n representing the number of nodes in an
// undirected graph. The nodes are labeled from 1 to n.

// You are also given a 2D integer array edges, where edges[i] = [ai, bi]
// indicates that there is a bidirectional edge between nodes ai and bi. Notice
// that the given graph may be disconnected.

// Divide the nodes of the graph into m groups (1-indexed) such that:

//     Each node in the graph belongs to exactly one group.
//     For every pair of nodes in the graph that are connected by an edge [ai,
//     bi], if ai belongs to the group with index x, and bi belongs to the group
//     with index y, then |y - x| = 1.

// Return the maximum number of groups (i.e., maximum m) into which you can
// divide the nodes. Return -1 if it is impossible to group the nodes with the
// given conditions.

// Example 1:

// Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
// Output: 4
// Explanation: As shown in the image we:
// - Add node 5 to the first group.
// - Add node 1 to the second group.
// - Add nodes 2 and 4 to the third group.
// - Add nodes 3 and 6 to the fourth group.
// We can see that every edge is satisfied.
// It can be shown that that if we create a fifth group and move any node from
// the third or fourth group to it, at least on of the edges will not be
// satisfied.

// Example 2:

// Input: n = 3, edges = [[1,2],[2,3],[3,1]]
// Output: -1
// Explanation: If we add node 1 to the first group, node 2 to the second group,
// and node 3 to the third group to satisfy the first two edges, we can see that
// the third edge will not be satisfied. It can be shown that no grouping is
// possible.

// Constraints:

//     1 <= n <= 500
//     1 <= edges.length <= 104
//     edges[i].length == 2
//     1 <= ai, bi <= n
//     ai != bi
//     There is at most one edge between any pair of vertices.

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int magnificentSets(int n, std::vector<std::vector<int>> &edges) {
        std::vector<std::vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }

        std::vector<int> colours(n, -1);
        for (int i = 0; i < n; i++) {
            if (colours[i] != -1) {
                continue;
            }
            colours[i] = 0;
            if (!isBipartite(adj, i, colours)) {
                return -1;
            }
        }

        std::vector<int> dists(n);
        for (int i = 0; i < n; i++) {
            dists[i] = getLongestShortestPath(adj, i, n);
        }

        int               result = 0;
        std::vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            result += getNumberOfGroups(adj, i, dists, visited);
        }
        return result;
    }

  private:
    bool isBipartite(std::vector<std::vector<int>> &adj, int curr,
                     std::vector<int> &colours) {
        for (int n : adj[curr]) {
            if (colours[n] == colours[curr]) {
                return false;
            }
            if (colours[n] != -1) {
                continue;
            }
            colours[n] = !colours[curr];
            if (!isBipartite(adj, n, colours)) {
                return false;
            }
        }
        return true;
    }

    int getLongestShortestPath(std::vector<std::vector<int>> &adj, int src,
                               int n) {
        std::queue<int>   q{{src}};
        std::vector<bool> visited(n);
        visited[src] = true;
        int dist     = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int front = q.front();
                q.pop();

                for (int n : adj[front]) {
                    if (visited[n]) {
                        continue;
                    }
                    visited[n] = true;
                    q.push(n);
                }
            }
            dist++;
        }
        return dist;
    }

    int getNumberOfGroups(std::vector<std::vector<int>> &adj, int curr,
                          std::vector<int> &dists, std::vector<bool> &visited) {
        int result    = dists[curr];
        visited[curr] = true;
        for (int n : adj[curr]) {
            if (visited[n]) {
                continue;
            }
            result =
                std::max(result, getNumberOfGroups(adj, n, dists, visited));
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>, int>>
        tests = {
            {{6, {{1, 2}, {1, 4}, {1, 5}, {2, 6}, {2, 3}, {4, 6}}}, 4},
            {{3, {{1, 2}, {2, 3}, {3, 1}}}, -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.magnificentSets(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
