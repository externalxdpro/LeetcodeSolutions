// [310] Minimum Height Trees
// Medium

// A tree is an undirected graph in which any two vertices are connected by
// exactly one path. In other words, any connected graph without simple cycles
// is a tree.
// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges
// where edges[i] = [ai, bi] indicates that there is an undirected edge between
// the two nodes ai and bi in the tree, you can choose any node of the tree as
// the root. When you select a node x as the root, the result tree has height h.
// Among all possible rooted trees, those with minimum height (i.e. min(h))  are
// called minimum height trees (MHTs).
// Return a list of all MHTs' root labels. You can return the answer in any
// order.
// The height of a rooted tree is the number of edges on the longest downward
// path between the root and a leaf.

// Example 1:
// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]
// Explanation: As shown, the height of the tree is 1 when the root is the node
// with label 1 which is the only MHT.

// Example 2:
// Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// Output: [3,4]

// Constraints:
//     1 <= n <= 2 * 10^4
//     edges.length == n - 1
//     0 <= a_i, b_i < n
//     a_i != b_i
//     All the pairs (a_i, b_i) are distinct.
//     The given input is guaranteed to be a tree and there will be no repeated
//     edges.

#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> findMinHeightTrees(int                            n,
                                        std::vector<std::vector<int>> &edges) {
        if (n == 1) {
            return {0};
        }
        std::vector<std::vector<int>> e(n);
        std::vector<int>              degree(n);
        for (std::vector<int> &edge : edges) {
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        std::queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        while (n > 2) {
            int size = leaves.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (int edge : e[leaf]) {
                    if (--degree[edge] == 1) {
                        leaves.push(edge);
                    }
                }
            }
        }

        std::vector<int> result;
        result.reserve(leaves.size());
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<int, std::vector<std::vector<int>>>,
                          std::vector<int>>>
        tests = {
            {{4, {{1, 0}, {1, 2}, {1, 3}}}, {1}},
            {{6, {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}}, {3, 4}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.findMinHeightTrees(std::get<0>(test), std::get<1>(test));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
