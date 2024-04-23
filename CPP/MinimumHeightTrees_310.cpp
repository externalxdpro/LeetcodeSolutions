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

// [#] Name
// Difficulty:

// Description

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Recursive
class Solution {
  public:
    std::vector<int> findMinHeightTrees(int                            n,
                                        std::vector<std::vector<int>> &edges) {
        std::vector<std::vector<int>> map(n);
        for (std::vector<int> &edge : edges) {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }

        std::unordered_set<int> found;
        std::vector<int>        heights;
        heights.reserve(n);
        for (int i = 0; i < map.size(); i++) {
            found.clear();
            heights.push_back(height(map, i, found) - 1);
        }

        int min = *std::min_element(heights.begin(), heights.end());
        std::vector<int> result;
        result.reserve(n);
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] == min) {
                result.push_back(i);
            }
        }
        return result;
    }

  private:
    int height(std::vector<std::vector<int>> &edges, int curr,
               std::unordered_set<int> &found) {
        if (found.contains(curr) || edges[curr].empty()) {
            return 0;
        }
        found.insert(curr);
        std::vector<int> heights;
        heights.reserve(edges.size());
        for (int edge : edges[curr]) {
            heights.push_back(height(edges, edge, found));
        }

        return 1 + *std::max_element(heights.begin(), heights.end());
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
