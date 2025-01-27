// 1462. Course Schedule IV
// Difficulty: Medium

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course ai first if you want to take
// course bi.

//     For example, the pair [0, 1] indicates that you have to take course 0
//     before you can take course 1.

// Prerequisites can also be indirect. If course a is a prerequisite of course
// b, and course b is a prerequisite of course c, then course a is a
// prerequisite of course c.

// You are also given an array queries where queries[j] = [uj, vj]. For the jth
// query, you should answer whether course uj is a prerequisite of course vj or
// not.

// Return a boolean array answer, where answer[j] is the answer to the jth
// query.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
// Output: [false,true]
// Explanation: The pair [1, 0] indicates that you have to take course 1 before
// you can take course 0. Course 0 is not a prerequisite of course 1, but the
// opposite is true.

// Example 2:

// Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
// Output: [false,false]
// Explanation: There are no prerequisites, and each course is independent.

// Example 3:

// Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries =
// [[1,0],[1,2]] Output: [true,true]

// Constraints:

//     2 <= numCourses <= 100
//     0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
//     prerequisites[i].length == 2
//     0 <= ai, bi <= numCourses - 1
//     ai != bi
//     All the pairs [ai, bi] are unique.
//     The prerequisites graph has no cycles.
//     1 <= queries.length <= 104
//     0 <= ui, vi <= numCourses - 1
//     ui != vi

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<bool>
    checkIfPrerequisite(int n, std::vector<std::vector<int>> &prerequisites,
                        std::vector<std::vector<int>> &queries) {
        std::vector<std::vector<int>>  adj(n);
        std::vector<std::vector<bool>> isPre(n, std::vector(n, false));
        for (auto &e : prerequisites) {
            adj[e[0]].push_back(e[1]);
        }
        traverse(n, adj, isPre);

        std::vector<bool> result;
        result.reserve(n);
        for (auto &q : queries) {
            result.push_back(isPre[q[0]][q[1]]);
        }
        return result;
    }

  private:
    void traverse(int n, std::vector<std::vector<int>> &adj,
                  std::vector<std::vector<bool>> &isPre) {
        for (int i = 0; i < n; i++) {
            std::queue<int> q{{i}};
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto &e : adj[node]) {
                    if (!isPre[i][e]) {
                        isPre[i][e] = true;
                        q.push(e);
                    }
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<int, std::vector<std::vector<int>>,
                                     std::vector<std::vector<int>>>,
                          std::vector<bool>>>
        tests = {
            {{2, {{1, 0}}, {{0, 1}, {1, 0}}}, {false, true}},
            {{2, {}, {{1, 0}, {0, 1}}}, {false, false}},
            {{3, {{1, 2}, {1, 0}, {2, 0}}, {{1, 0}, {1, 2}}}, {true, true}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.checkIfPrerequisite(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
