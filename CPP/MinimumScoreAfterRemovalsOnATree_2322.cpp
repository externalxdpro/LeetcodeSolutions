// 2322. Minimum Score After Removals on a Tree
// Difficulty: Hard

// There is an undirected connected tree with n nodes labeled from 0 to n - 1
// and n - 1 edges.

// You are given a 0-indexed integer array nums of length n where nums[i]
// represents the value of the ith node. You are also given a 2D integer array
// edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an
// edge between nodes ai and bi in the tree.

// Remove two distinct edges of the tree to form three connected components. For
// a pair of removed edges, the following steps are defined:

// Get the XOR of all the values of the nodes for each of the three components
// respectively. The difference between the largest XOR value and the smallest
// XOR value is the score of the pair. For example, say the three components
// have the node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4
// ^ 5 ^ 7 = 6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the
// smallest XOR value is 3. The score is then 8 - 3 = 5. Return the minimum
// score of any possible pair of edge removals on the given tree.

// Example 1:

// Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
// Output: 9
// Explanation: The diagram above shows a way to make a pair of removals.
// - The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is
// 5 ^ 4 ^ 11 = 10.
// - The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
// - The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
// The score is the difference between the largest and smallest XOR value which
// is 10 - 1 = 9. It can be shown that no other pair of removals will obtain a
// smaller score than 9. Example 2:

// Input: nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
// Output: 0
// Explanation: The diagram above shows a way to make a pair of removals.
// - The 1st component has nodes [3,4] with values [4,4]. Its XOR value is 4 ^ 4
// = 0.
// - The 2nd component has nodes [1,0] with values [5,5]. Its XOR value is 5 ^ 5
// = 0.
// - The 3rd component has nodes [2,5] with values [2,2]. Its XOR value is 2 ^ 2
// = 0. The score is the difference between the largest and smallest XOR value
// which is 0 - 0 = 0. We cannot obtain a smaller score than 0.

// Constraints:

// n == nums.length
// 3 <= n <= 1000
// 1 <= nums[i] <= 108
// edges.length == n - 1
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// edges represents a valid tree.

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int minimumScore(std::vector<int> &nums,
                     std::vector<std::vector<int>> &edges) {
        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, std::unordered_set<int>> children;
        std::vector<int> xors = nums;
        std::vector<int> degrees(nums.size());

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degrees[e[0]]++;
            degrees[e[1]]++;
        }

        int currXor = 0;

        std::unordered_set<int> seen;
        std::queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            currXor ^= nums[i];
            if (degrees[i] == 1) {
                q.push(i);
                seen.insert(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : graph[curr]) {
                if (!seen.contains(next)) {
                    children[next].insert(curr);
                    children[next].insert(children[curr].begin(),
                                          children[curr].end());
                    xors[next] ^= xors[curr];
                }
                degrees[next]--;
                if (degrees[next] == 1) {
                    seen.insert(next);
                    q.push(next);
                }
            }
        }

        int result = std::numeric_limits<int>::max();
        for (int i = 0; i < edges.size() - 1; i++) {
            for (int j = i + 1; j < edges.size(); j++) {
                int a = edges[i][0], b = edges[i][1];
                if (children[a].contains(b)) {
                    std::swap(a, b);
                }
                int c = edges[j][0], d = edges[j][1];
                if (children[c].contains(d)) {
                    std::swap(c, d);
                }

                std::vector<int> curr(3);
                if (children[a].contains(c)) {
                    curr = {xors[c], xors[a] ^ xors[c], currXor ^ xors[a]};
                } else if (children[c].contains(a)) {
                    curr = {xors[a], xors[c] ^ xors[a], currXor ^ xors[c]};
                } else {
                    curr = {xors[a], xors[c], currXor ^ xors[a] ^ xors[c]};
                }

                auto [min, max] = std::ranges::minmax_element(curr);
                result = std::min(result, *max - *min);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::pair<std::vector<int>, std::vector<std::vector<int>>>, int>>
        tests = {
            {{{1, 5, 5, 4, 11}, {{0, 1}, {1, 2}, {1, 3}, {3, 4}}}, 9},
            {{{5, 5, 2, 4, 4, 2}, {{0, 1}, {1, 2}, {5, 2}, {4, 3}, {1, 3}}}, 0},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimumScore(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
