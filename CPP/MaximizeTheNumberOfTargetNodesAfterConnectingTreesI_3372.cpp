// 3372. Maximize the Number of Target Nodes After Connecting Trees I
// Difficulty: Medium

// There exist two undirected trees with n and m nodes, with distinct labels in
// ranges [0, n - 1] and [0, m - 1], respectively.

// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m
// - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge
// between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates
// that there is an edge between nodes ui and vi in the second tree. You are
// also given an integer k.

// Node u is target to node v if the number of edges on the path from u to v is
// less than or equal to k. Note that a node is always target to itself.

// Return an array of n integers answer, where answer[i] is the maximum possible
// number of nodes target to node i of the first tree if you have to connect one
// node from the first tree to another node in the second tree.

// Note that queries are independent from each other. That is, for every query
// you will remove the added edge before proceeding to the next query.

// Example 1:

// Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 =
// [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2

// Output: [9,7,9,8,8]

// Explanation:

//     For i = 0, connect node 0 from the first tree to node 0 from the second
//     tree. For i = 1, connect node 1 from the first tree to node 0 from the
//     second tree. For i = 2, connect node 2 from the first tree to node 4 from
//     the second tree. For i = 3, connect node 3 from the first tree to node 4
//     from the second tree. For i = 4, connect node 4 from the first tree to
//     node 4 from the second tree.

// Example 2:

// Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k =
// 1

// Output: [6,3,3,3,3]

// Explanation:

// For every i, connect node i of the first tree with any node of the second
// tree.

// Constraints:

//     2 <= n, m <= 1000
//     edges1.length == n - 1
//     edges2.length == m - 1
//     edges1[i].length == edges2[i].length == 2
//     edges1[i] = [ai, bi]
//     0 <= ai, bi < n
//     edges2[i] = [ui, vi]
//     0 <= ui, vi < m
//     The input is generated such that edges1 and edges2 represent valid trees.
//     0 <= k <= 1000

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>> &edges1,
                                    std::vector<std::vector<int>> &edges2,
                                    int                            k) {
        std::vector<std::vector<int>> adj1(edges1.size() + 1);
        std::vector<std::vector<int>> adj2(edges2.size() + 1);
        for (auto &e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        std::vector<int> count1(edges1.size() + 1);
        std::vector<int> count2(edges2.size() + 1);
        for (int i = 0; i <= edges1.size(); i++) {
            count1[i] = recurse(adj1, k, i, -1);
        }
        for (int i = 0; i <= edges2.size(); i++) {
            count2[i] = recurse(adj2, k - 1, i, -1);
        }

        int              max = *std::ranges::max_element(count2);
        std::vector<int> result(edges1.size() + 1);
        for (int i = 0; i <= edges1.size(); i++) {
            result[i] = count1[i] + max;
        }
        return result;
    }

  private:
    int recurse(std::vector<std::vector<int>> &nodes, int k, int curr,
                int parent) {
        if (k < 0) {
            return 0;
        }
        int result = 1;
        for (int next : nodes[curr]) {
            if (next == parent) {
                continue;
            }
            result += recurse(nodes, k - 1, next, curr);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<std::vector<int>>,
                                     std::vector<std::vector<int>>, int>,
                          std::vector<int>>>
        tests = {
            {{{{0, 1}, {0, 2}, {2, 3}, {2, 4}},
              {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}},
              2},
             {9, 7, 9, 8, 8}},
            {{{{0, 1}, {0, 2}, {0, 3}, {0, 4}}, {{0, 1}, {1, 2}, {2, 3}}, 1},
             {6, 3, 3, 3, 3}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxTargetNodes(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
