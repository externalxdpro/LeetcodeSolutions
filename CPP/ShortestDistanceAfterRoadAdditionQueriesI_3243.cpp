// 3243. Shortest Distance After Road Addition Queries I
// Difficulty: Medium

// You are given an integer n and a 2D integer array queries.

// There are n cities numbered from 0 to n - 1. Initially, there is a
// unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

// queries[i] = [ui, vi] represents the addition of a new unidirectional road
// from city ui to city vi. After each query, you need to find the length of the
// shortest path from city 0 to city n - 1.

// Return an array answer where for each i in the range [0, queries.length - 1],
// answer[i] is the length of the shortest path from city 0 to city n - 1 after
// processing the first i + 1 queries.

// Example 1:

// Input: n = 5, queries = [[2,4],[0,2],[0,4]]

// Output: [3,2,1]

// Explanation:

// After the addition of the road from 2 to 4, the length of the shortest path
// from 0 to 4 is 3.

// After the addition of the road from 0 to 2, the length of the shortest path
// from 0 to 4 is 2.

// After the addition of the road from 0 to 4, the length of the shortest path
// from 0 to 4 is 1.

// Example 2:

// Input: n = 4, queries = [[0,3],[0,2]]

// Output: [1,1]

// Explanation:

// After the addition of the road from 0 to 3, the length of the shortest path
// from 0 to 3 is 1.

// After the addition of the road from 0 to 2, the length of the shortest path
// remains 1.

// Constraints:

//     3 <= n <= 500
//     1 <= queries.length <= 500
//     queries[i].length == 2
//     0 <= queries[i][0] < queries[i][1] < n
//     1 < queries[i][1] - queries[i][0]
//     There are no repeated roads among the queries.

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int>
    shortestDistanceAfterQueries(int                                  n,
                                 const std::vector<std::vector<int>> &queries) {
        std::vector<int>              result;
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        for (const auto &q : queries) {
            adj[q[0]].push_back(q[1]);
            result.push_back(bfs(n, adj));
        }

        return result;
    }

  private:
    int bfs(int n, const std::vector<std::vector<int>> &adj) {
        std::vector<bool> visited(n);
        std::queue<int>   q{{0}};
        visited[0] = true;

        int result = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int front = q.front();
                q.pop();

                if (front == n - 1) {
                    return result;
                }
                for (const int e : adj[front]) {
                    if (visited[e]) {
                        continue;
                    }
                    q.push(e);
                    visited[e] = true;
                }
            }
            result++;
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>,
                          std::vector<int>>>
        tests = {
            {{5, {{2, 4}, {0, 2}, {0, 4}}}, {3, 2, 1}},
            {{4, {{0, 3}, {0, 2}}}, {1, 1}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.shortestDistanceAfterQueries(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
