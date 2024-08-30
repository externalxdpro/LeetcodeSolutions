// 2699. Modify Graph Edge Weights
// Difficulty: Hard

// You are given an undirected weighted connected graph containing n nodes
// labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi,
// wi] indicates that there is an edge between nodes ai and bi with weight wi.
// Some edges have a weight of -1 (wi = -1), while others have a positive weight
// (wi > 0).
// Your task is to modify all edges with a weight of -1 by assigning them
// positive integer values in the range [1, 2 * 109] so that the shortest
// distance between the nodes source and destination becomes equal to an integer
// target. If there are multiple modifications that make the shortest distance
// between source and destination equal to target, any of them will be
// considered correct.
// Return an array containing all edges (even unmodified ones) in any order if
// it is possible to make the shortest distance from source to destination equal
// to target, or an empty array if it's impossible.
// Note: You are not allowed to modify the weights of edges with initial
// positive weights.

// Example 1:
// Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0,
// destination = 1, target = 5 Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
// Explanation: The graph above shows a possible modification to the edges,
// making the distance from 0 to 1 equal to 5.

// Example 2:
// Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target
// = 6 Output: [] Explanation: The graph above contains the initial edges. It is
// not possible to make the distance from 0 to 2 equal to 6 by modifying the
// edge with weight -1. So, an empty array is returned.

// Example 3:
// Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0,
// destination = 2, target = 6 Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
// Explanation: The graph above shows a modified graph having the shortest
// distance from 0 to 2 as 6.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    const int INF = 2e9;

  public:
    std::vector<std::vector<int>>
    modifiedGraphEdges(int n, std::vector<std::vector<int>> &edges, int source,
                       int destination, int target) {
        long long curr = djikstra(edges, n, source, destination);
        if (curr < target) {
            return {};
        }

        bool matches = curr == target;
        for (std::vector<int> &edge : edges) {
            if (edge[2] > 0) {
                continue;
            }
            edge[2] = matches ? INF : 1;

            if (!matches) {
                long long dist = djikstra(edges, n, source, destination);
                if (dist <= target) {
                    matches = true;
                    edge[2] += target - dist;
                }
            }
        }
        return matches ? edges : std::vector<std::vector<int>>{};
    }

  private:
    long long djikstra(const std::vector<std::vector<int>> &edges, int n,
                       int src, int dst) {
        std::vector<std::vector<long long>> adjMatrix(
            n, std::vector<long long>(n, INF));
        std::vector<long long> minDist(n, INF);
        std::vector<bool>      visited(n, false);

        minDist[src] = 0;

        for (const std::vector<int> &edge : edges) {
            if (edge[2] != -1) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        for (int i = 0; i < n; i++) {
            int nearest = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] &&
                    (nearest == -1 || minDist[j] < minDist[nearest])) {
                    nearest = j;
                }
            }

            visited[nearest] = true;

            for (int v = 0; v < n; v++) {
                minDist[v] = std::min(minDist[v],
                                      minDist[nearest] + adjMatrix[nearest][v]);
            }
        }

        return minDist[dst];
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::tuple<int, std::vector<std::vector<int>>, int, int, int>,
                  std::vector<std::vector<int>>>>
        tests = {
            {{5, {{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}}, 0, 1, 5},
             {{4, 1, 1}, {2, 0, 1}, {0, 3, 1}, {4, 3, 3}}},
            {{3, {{0, 1, -1}, {0, 2, 5}}, 0, 2, 6}, {}},
            {{4, {{1, 0, 4}, {1, 2, 3}, {2, 3, 5}, {0, 3, -1}}, 0, 2, 6},
             {{1, 0, 4}, {1, 2, 3}, {2, 3, 5}, {0, 3, 1}}},
            {{5,
              {{1, 4, 1},
               {2, 4, -1},
               {3, 0, 2},
               {0, 4, -1},
               {1, 3, 10},
               {1, 0, 10}},
              0,
              2,
              15},
             {{1, 4, 1},
              {2, 4, 4},
              {3, 0, 2},
              {0, 4, 10000000},
              {1, 3, 10},
              {1, 0, 10}}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.modifiedGraphEdges(
            std::get<0>(test), std::get<1>(test), std::get<2>(test),
            std::get<3>(test), std::get<4>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
