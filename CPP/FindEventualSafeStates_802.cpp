// 802. Find Eventual Safe States
// Difficulty: Medium

// There is a directed graph of n nodes with each node labeled from 0 to n - 1.
// The graph is represented by a 0-indexed 2D integer array graph where graph[i]
// is an integer array of nodes adjacent to node i, meaning there is an edge
// from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe
// node if every possible path starting from that node leads to a terminal node
// (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should
// be sorted in ascending order.

// Example 1:
// Illustration of graph

// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either
// of them. Every path starting at nodes 2, 4, 5, and 6 all lead to either node
// 5 or 6.

// Example 2:

// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
// Explanation:
// Only node 4 is a terminal node, and every path starting at node 4 leads to
// node 4.

// Constraints:

//     n == graph.length
//     1 <= n <= 104
//     0 <= graph[i].length <= n
//     0 <= graph[i][j] <= n - 1
//     graph[i] is sorted in a strictly increasing order.
//     The graph may contain self-loops.
//     The number of edges in the graph will be in the range [1, 4 * 104].

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>> &graph) {
        std::vector<bool> visited(graph.size()), stack(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            dfs(graph, i, visited, stack);
        }

        std::vector<int> result;
        for (int i = 0; i < graph.size(); i++) {
            if (!stack[i]) {
                result.push_back(i);
            }
        }
        return result;
    }

  private:
    bool dfs(std::vector<std::vector<int>> &graph, int curr,
             std::vector<bool> &visited, std::vector<bool> &stack) {
        if (stack[curr]) {
            return true;
        }
        if (visited[curr]) {
            return false;
        }

        visited[curr] = true;
        stack[curr]   = true;
        for (int n : graph[curr]) {
            if (dfs(graph, n, visited, stack)) {
                return true;
            }
        }
        stack[curr] = false;
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<int>>>
        tests = {
            {{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}}, {2, 4, 5, 6}},
            {{{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}}, {4}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.eventualSafeNodes(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
