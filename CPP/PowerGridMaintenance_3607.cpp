// 3607. Power Grid Maintenance
// Difficulty: Medium

// You are given an integer c representing c power stations, each with a unique
// identifier id from 1 to c (1‑based indexing).

// These stations are interconnected via n bidirectional cables, represented by
// a 2D array connections, where each element connections[i] = [ui, vi]
// indicates a connection between station ui and station vi. Stations that are
// directly or indirectly connected form a power grid.

// Initially, all stations are online (operational).

// You are also given a 2D array queries, where each query is one of the
// following two types:

//     [1, x]: A maintenance check is requested for station x. If station x is
//     online, it resolves the check by itself. If station x is offline, the
//     check is resolved by the operational station with the smallest id in the
//     same power grid as x. If no operational station exists in that grid,
//     return -1.

//     [2, x]: Station x goes offline (i.e., it becomes non-operational).

// Return an array of integers representing the results of each query of type
// [1, x] in the order they appear.

// Note: The power grid preserves its structure; an offline (non‑operational)
// node remains part of its grid and taking it offline does not alter
// connectivity.

// Example 1:

// Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries =
// [[1,3],[2,1],[1,1],[2,2],[1,2]]

// Output: [3,2,3]

// Explanation:

//     Initially, all stations {1, 2, 3, 4, 5} are online and form a single
//     power grid. Query [1,3]: Station 3 is online, so the maintenance check is
//     resolved by station 3. Query [2,1]: Station 1 goes offline. The remaining
//     online stations are {2, 3, 4, 5}. Query [1,1]: Station 1 is offline, so
//     the check is resolved by the operational station with the smallest id
//     among {2, 3, 4, 5}, which is station 2. Query [2,2]: Station 2 goes
//     offline. The remaining online stations are {3, 4, 5}. Query [1,2]:
//     Station 2 is offline, so the check is resolved by the operational station
//     with the smallest id among {3, 4, 5}, which is station 3.

// Example 2:

// Input: c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]

// Output: [1,-1]

// Explanation:

//     There are no connections, so each station is its own isolated grid.
//     Query [1,1]: Station 1 is online in its isolated grid, so the maintenance
//     check is resolved by station 1. Query [2,1]: Station 1 goes offline.
//     Query [1,1]: Station 1 is offline and there are no other stations in its
//     grid, so the result is -1.

// Constraints:

//     1 <= c <= 105
//     0 <= n == connections.length <= min(105, c * (c - 1) / 2)
//     connections[i].length == 2
//     1 <= ui, vi <= c
//     ui != vi
//     1 <= queries.length <= 2 * 105
//     queries[i].length == 2
//     queries[i][0] is either 1 or 2.
//     1 <= queries[i][1] <= c

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
    using Grid = std::priority_queue<int, std::vector<int>, std::greater<>>;
    using Graph = std::vector<std::vector<int>>;

    struct Node {
        int id;
        bool online = true;
        int gridId = -1;
    };

    std::vector<Node> nodes;

  public:
    std::vector<int> processQueries(int c,
                                    std::vector<std::vector<int>> &connections,
                                    std::vector<std::vector<int>> &queries) {
        std::vector<std::vector<int>> graph(c + 1);
        nodes.resize(c + 1);

        for (int i = 1; i <= c; i++) {
            nodes[i].id = i;
        }
        for (auto &c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        std::vector<Grid> grids;
        for (int i = 1, gridId = 0; i <= c; i++) {
            Node &n = nodes[i];
            if (n.gridId == -1) {
                Grid grid;
                setGridId(n, gridId, grid, graph);
                grids.push_back(grid);
                gridId++;
            }
        }

        std::vector<int> result;
        for (auto &q : queries) {
            int op = q[0], x = q[1];
            if (op == 1) {
                if (nodes[x].online) {
                    result.push_back(x);
                } else {
                    Grid &grid = grids[nodes[x].gridId];
                    while (!grid.empty() && !nodes[grid.top()].online) {
                        grid.pop();
                    }
                    result.push_back(!grid.empty() ? grid.top() : -1);
                }
            } else {
                nodes[x].online = false;
            }
        }
        return result;
    }

  private:
    void setGridId(Node &n, int gridId, Grid &grid, Graph &graph) {
        n.gridId = gridId;
        grid.push(n.id);
        for (int id : graph[n.id]) {
            Node &m = nodes[id];
            if (m.gridId == -1) {
                setGridId(m, gridId, grid, graph);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<int, std::vector<std::vector<int>>,
                                     std::vector<std::vector<int>>>,
                          std::vector<int>>>
        tests = {
            {{5,
              {{1, 2}, {2, 3}, {3, 4}, {4, 5}},
              {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}}},
             {3, 2, 3}},
            {{3, {}, {{1, 1}, {2, 1}, {1, 1}}}, {1, -1}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.processQueries(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
