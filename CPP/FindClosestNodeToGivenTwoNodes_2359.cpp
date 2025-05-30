// 2359. Find Closest Node to Given Two Nodes
// Difficulty: Medium

// You are given a directed graph of n nodes numbered from 0 to n - 1, where
// each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n,
// indicating that there is a directed edge from node i to node edges[i]. If
// there is no outgoing edge from i, then edges[i] == -1.

// You are also given two integers node1 and node2.

// Return the index of the node that can be reached from both node1 and node2,
// such that the maximum between the distance from node1 to that node, and from
// node2 to that node is minimized. If there are multiple answers, return the
// node with the smallest index, and if no possible answer exists, return -1.

// Note that edges may contain cycles.

// Example 1:

// Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
// Output: 2
// Explanation: The distance from node 0 to node 2 is 1, and the distance from
// node 1 to node 2 is 1. The maximum of those two distances is 1. It can be
// proven that we cannot get a node with a smaller maximum distance than 1, so
// we return node 2.

// Example 2:

// Input: edges = [1,2,-1], node1 = 0, node2 = 2
// Output: 2
// Explanation: The distance from node 0 to node 2 is 2, and the distance from
// node 2 to itself is 0. The maximum of those two distances is 2. It can be
// proven that we cannot get a node with a smaller maximum distance than 2, so
// we return node 2.

// Constraints:

//     n == edges.length
//     2 <= n <= 105
//     -1 <= edges[i] < n
//     edges[i] != i
//     0 <= node1, node2 < n

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int closestMeetingNode(std::vector<int> &edges, int node1, int node2) {
        auto dists1 = dists(edges, node1);
        auto dists2 = dists(edges, node2);
        int min = -1, result = -1;
        for (int i = 0; i < edges.size(); i++) {
            if (dists1[i] != -1 && dists2[i] != -1 &&
                (min == -1 || std::max(dists1[i], dists2[i]) < min)) {
                min = std::max(dists1[i], dists2[i]);
                result = i;
            }
        }
        return result;
    }

  private:
    std::vector<int> dists(std::vector<int> &edges, int start) {
        std::vector<int> result(edges.size(), -1);
        int curr = start;
        int dist = 0;
        while (curr != -1 && result[curr] == -1) {
            result[curr] = dist;
            curr = edges[curr];
            dist++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int>, int>> tests =
        {
            {{{2, 2, 3, -1}, 0, 1}, 2},
            {{{1, 2, -1}, 0, 2}, 2},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.closestMeetingNode(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
