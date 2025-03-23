// 1976. Number of Ways to Arrive at Destination
// Difficulty: Medium

// You are in a city that consists of n intersections numbered from 0 to n - 1
// with bi-directional roads between some intersections. The inputs are
// generated such that you can reach any intersection from any other
// intersection and that there is at most one road between any two
// intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui,
// vi, timei] means that there is a road between intersections ui and vi that
// takes timei minutes to travel. You want to know in how many ways you can
// travel from intersection 0 to intersection n - 1 in the shortest amount of
// time.

// Return the number of ways you can arrive at your destination in the shortest
// amount of time. Since the answer may be large, return it modulo 109 + 7.

// Example 1:

// Input: n = 7, roads =
// [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
// Output: 4
// Explanation: The shortest amount of time it takes to go from intersection 0
// to intersection 6 is 7 minutes. The four ways to get there in 7 minutes are:
// - 0 ➝ 6
// - 0 ➝ 4 ➝ 6
// - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
// - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

// Example 2:

// Input: n = 2, roads = [[1,0,10]]
// Output: 1
// Explanation: There is only one way to go from intersection 0 to intersection
// 1, and it takes 10 minutes.

// Constraints:

//     1 <= n <= 200
//     n - 1 <= roads.length <= n * (n - 1) / 2
//     roads[i].length == 3
//     0 <= ui, vi <= n - 1
//     1 <= timei <= 109
//     ui != vi
//     There is at most one road connecting any two intersections.
//     You can reach any intersection from any other intersection.

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <queue>
#include <vector>

class Solution {
  public:
    int countPaths(int n, std::vector<std::vector<int>> &roads) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (auto &e : roads) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }

        std::priority_queue<std::pair<long long, int>,
                            std::vector<std::pair<long long, int>>,
                            std::greater<>>
                               pq;
        std::vector<long long> shortest(n,
                                        std::numeric_limits<long long>::max());
        std::vector<int>       paths(n);
        shortest[0] = 0;
        paths[0]    = 1;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > shortest[node]) {
                continue;
            }
            for (auto &[nextNode, nextTime] : adj[node]) {
                if (time + nextTime < shortest[nextNode]) {
                    shortest[nextNode] = time + nextTime;
                    paths[nextNode]    = paths[node];
                    pq.emplace(time + nextTime, nextNode);
                } else if (time + nextTime == shortest[nextNode]) {
                    paths[nextNode] =
                        (paths[nextNode] + paths[node]) % (int)(1e9 + 7);
                }
            }
        }
        return paths.back();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>, int>>
        tests = {
            {{7,
              {{0, 6, 7},
               {0, 1, 2},
               {1, 2, 3},
               {1, 3, 3},
               {6, 3, 3},
               {3, 5, 1},
               {6, 5, 1},
               {2, 5, 1},
               {0, 4, 5},
               {4, 6, 2}}},
             4},
            {{2, {{1, 0, 10}}}, 1},
            {{6,
              {{3, 0, 4},
               {0, 2, 3},
               {1, 2, 2},
               {4, 1, 3},
               {2, 5, 5},
               {2, 3, 1},
               {0, 4, 1},
               {2, 4, 6},
               {4, 3, 1}}},
             2},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countPaths(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
