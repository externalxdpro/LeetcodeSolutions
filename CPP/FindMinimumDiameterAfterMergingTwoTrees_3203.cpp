// 3203. Find Minimum Diameter After Merging Two Trees
// Difficulty: Hard

// There exist two undirected trees with n and m nodes, numbered from 0 to n - 1
// and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1
// and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai,
// bi] indicates that there is an edge between nodes ai and bi in the first tree
// and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and
// vi in the second tree.

// You must connect one node from the first tree with another node from the
// second tree with an edge.

// Return the minimum possible diameter of the resulting tree.

// The diameter of a tree is the length of the longest path between any two
// nodes in the tree.

// Example 1:

// Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]

// Output: 3

// Explanation:

// We can obtain a tree of diameter 3 by connecting node 0 from the first tree
// with any node from the second tree.

// Example 2:

// Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 =
// [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]

// Output: 5

// Explanation:

// We can obtain a tree of diameter 5 by connecting node 0 from the first tree
// with node 0 from the second tree.

// Constraints:

//     1 <= n, m <= 105
//     edges1.length == n - 1
//     edges2.length == m - 1
//     edges1[i].length == edges2[i].length == 2
//     edges1[i] = [ai, bi]
//     0 <= ai, bi < n
//     edges2[i] = [ui, vi]
//     0 <= ui, vi < m
//     The input is generated such that edges1 and edges2 represent valid trees.

#include <algorithm>
#include <cmath>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minimumDiameterAfterMerge(std::vector<std::vector<int>> &edges1,
                                  std::vector<std::vector<int>> &edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        std::vector<std::vector<int>> adj1(n);
        std::vector<std::vector<int>> adj2(m);
        for (auto &e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        int d1   = getDiameter(adj1, 0, -1).first;
        int d2   = getDiameter(adj2, 0, -1).first;
        int both = std::ceil(d1 / 2.0) + std::ceil(d2 / 2.0) + 1;

        return std::max({d1, d2, both});
    }

  private:
    std::pair<int, int> getDiameter(std::vector<std::vector<int>> &adj,
                                    int curr, int prev) {
        int max1 = 0, max2 = 0;
        int diameter = 0;
        for (int n : adj[curr]) {
            if (n == prev) {
                continue;
            }
            auto [newD, depth] = getDiameter(adj, n, curr);
            diameter           = std::max(diameter, newD);
            depth++;
            if (depth > max1) {
                max2 = max1;
                max1 = depth;
            } else if (depth > max2) {
                max2 = depth;
            }
        }
        diameter = std::max(diameter, max1 + max2);
        return {diameter, max1};
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>,
        int>>
        tests = {
            {{{{0, 1}, {0, 2}, {0, 3}}, {{0, 1}}}, 3},
            {{{{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}},
              {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}}},
             5},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.minimumDiameterAfterMerge(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
