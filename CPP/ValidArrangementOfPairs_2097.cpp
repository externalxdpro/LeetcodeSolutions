// 2097. Valid Arrangement of Pairs
// Difficulty: Hard

// You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti,
// endi]. An arrangement of pairs is valid if for every index i where 1 <= i <
// pairs.length, we have endi-1 == starti.

// Return any valid arrangement of pairs.

// Note: The inputs will be generated such that there exists a valid arrangement
// of pairs.

// Example 1:

// Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
// Output: [[11,9],[9,4],[4,5],[5,1]]
// Explanation:
// This is a valid arrangement since endi-1 always equals starti.
// end0 = 9 == 9 = start1
// end1 = 4 == 4 = start2
// end2 = 5 == 5 = start3

// Example 2:

// Input: pairs = [[1,3],[3,2],[2,1]]
// Output: [[1,3],[3,2],[2,1]]
// Explanation:
// This is a valid arrangement since endi-1 always equals starti.
// end0 = 3 == 3 = start1
// end1 = 2 == 2 = start2
// The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.

// Example 3:

// Input: pairs = [[1,2],[1,3],[2,1]]
// Output: [[1,2],[2,1],[1,3]]
// Explanation:
// This is a valid arrangement since endi-1 always equals starti.
// end0 = 2 == 2 = start1
// end1 = 1 == 1 = start2

// Constraints:

//     1 <= pairs.length <= 105
//     pairs[i].length == 2
//     0 <= starti, endi <= 109
//     starti != endi
//     No two pairs are exactly the same.
//     There exists a valid arrangement of pairs.

#include <algorithm>
#include <deque>
#include <fmt/ranges.h>
#include <functional>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    validArrangement(const std::vector<std::vector<int>> &pairs) {
        std::unordered_map<int, std::deque<int>> adj;
        std::unordered_map<int, int>             in, out;

        for (auto &p : pairs) {
            adj[p[0]].push_back(p[1]);
            out[p[0]]++;
            in[p[1]]++;
        }

        std::vector<int> path;

        std::function<void(int)> recurse = [&](int node) {
            while (!adj[node].empty()) {
                int next = adj[node].front();
                adj[node].pop_front();
                recurse(next);
            }
            path.push_back(node);
        };

        int start = -1;
        for (auto &[node, count] : out) {
            if (out[node] == in[node] + 1) {
                start = node;
                break;
            }
        }
        if (start == -1) {
            start = pairs[0][0];
        }

        recurse(start);
        std::ranges::reverse(path);

        std::vector<std::vector<int>> result;
        for (size_t i = 1; i < path.size(); i++) {
            result.push_back({path[i - 1], path[i]});
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>>
        tests = {
            {{{5, 1}, {4, 5}, {11, 9}, {9, 4}},
             {{11, 9}, {9, 4}, {4, 5}, {5, 1}}},
            {{{1, 3}, {3, 2}, {2, 1}}, {{1, 3}, {3, 2}, {2, 1}}},
            {{{1, 2}, {1, 3}, {2, 1}}, {{1, 2}, {2, 1}, {1, 3}}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.validArrangement(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
