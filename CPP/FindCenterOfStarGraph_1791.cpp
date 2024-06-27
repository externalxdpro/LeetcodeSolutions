// 1791. Find Center of Star Graph
// Difficulty: Easy

// There is an undirected star graph consisting of n nodes labeled from 1 to n.
// A star graph is a graph where there is one center node and exactly n - 1
// edges that connect the center node with every other node.
// You are given a 2D integer array edges where each edges[i] = [ui, vi]
// indicates that there is an edge between the nodes ui and vi. Return the
// center of the given star graph.

// Example 1:
// Input: edges = [[1,2],[2,3],[4,2]]
// Output: 2
// Explanation: As shown in the figure above, node 2 is connected to every other
// node, so 2 is the center.

// Example 2:
// Input: edges = [[1,2],[5,1],[1,3],[1,4]]
// Output: 1

// Constraints:
//     3 <= n <= 10^5
//     edges.length == n - 1
//     edges[i].length == 2
//     1 <= u_i, v_i <= n
//     u_i != v_i
//     The given edges represent a valid star graph.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int findCenter(std::vector<std::vector<int>> &edges) {
        int e[100000] = {0};

        for (std::vector<int> edge : edges) {
            if (e[edge[0]] != 0) {
                return edge[0];
            }
            e[edge[0]] = edge[1];

            if (e[edge[1]] != 0) {
                return edge[1];
            }
            e[edge[1]] = edge[0];
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 2}, {2, 3}, {4, 2}}, 2},
        {{{1, 2}, {5, 1}, {1, 3}, {1, 4}}, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findCenter(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
