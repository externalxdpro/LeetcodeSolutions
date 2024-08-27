// 1514. Path with Maximum Probability
// Difficulty: Medium

// You are given an undirected weighted graph of n nodes (0-indexed),
// represented by an edge list where edges[i] = [a, b] is an undirected edge
// connecting the nodes a and b with a probability of success of traversing that
// edge succProb[i].
// Given two nodes start and end, find the path with the maximum probability of
// success to go from start to end and return its success probability.
// If there is no path from start to end, return 0. Your answer will be accepted
// if it differs from the correct answer by at most 1e-5.

// Example 1:
// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start =
// 0, end = 2 Output: 0.25000 Explanation: There are two paths from start to
// end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 =
// 0.25.

// Example 2:
// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start =
// 0, end = 2 Output: 0.30000

// Example 3:
// Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
// Output: 0.00000
// Explanation: There is no path between 0 and 2.

// Constraints:
//     2 <= n <= 10^4
//     0 <= start, end < n
//     start != end
//     0 <= a, b < n
//     a != b
//     0 <= succProb.length == edges.length <= 2*10^4
//     0 <= succProb[i] <= 1
//     There is at most one edge between every two nodes.

#include <fmt/ranges.h>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    double maxProbability(int n, std::vector<std::vector<int>> &edges,
                          std::vector<double> &succProb, int start_node,
                          int end_node) {
        std::unordered_map<int, std::vector<std::pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            graph[u].emplace_back(v, succProb[i]);
            graph[v].emplace_back(u, succProb[i]);
        }

        std::vector<double> maxProb(n);
        maxProb[start_node] = 1;

        std::priority_queue<std::pair<double, int>> pq;
        pq.emplace(1, start_node);
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            if (node == end_node) {
                return prob;
            }
            for (auto &[nxtNode, pathProb] : graph[node]) {
                if (prob * pathProb > maxProb[nxtNode]) {
                    maxProb[nxtNode] = prob * pathProb;
                    pq.emplace(maxProb[nxtNode], nxtNode);
                }
            }
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<int, std::vector<std::vector<int>>,
                                     std::vector<double>, int, int>,
                          double>>
        tests = {
            {{3, {{0, 1}, {1, 2}, {0, 2}}, {0.5, 0.5, 0.2}, 0, 2}, 0.25},
            {{3, {{0, 1}, {1, 2}, {0, 2}}, {0.5, 0.5, 0.3}, 0, 2}, 0.3},
            {{3, {{0, 1}}, {0.5}, 0, 2}, 0},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxProbability(
            std::get<0>(test), std::get<1>(test), std::get<2>(test),
            std::get<3>(test), std::get<4>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
