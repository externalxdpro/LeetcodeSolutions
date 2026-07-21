// 210. Course Schedule II
// Difficulty: Medium

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to
// first take course 1. Return the ordering of courses you should take to finish
// all courses. If there are many valid answers, return any of them. If it is
// impossible to finish all courses, return an empty array.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you
// should have finished course 0. So the correct course order is [0,1]. Example
// 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you
// should have finished both courses 1 and 2. Both courses 1 and 2 should be
// taken after you finished course 0. So one correct course order is [0,1,2,3].
// Another correct ordering is [0,2,1,3]. Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> findOrder(int numCourses,
                               std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for (auto &req : prerequisites) {
            adj[req[0]].push_back(req[1]);
        }

        std::vector<int> result;
        std::vector<bool> seen(numCourses);
        std::vector<bool> path(numCourses);

        for (int i = 0; i < numCourses; i++) {
            if (!seen[i] && !dfs(adj, i, seen, path, result)) {
                return {};
            }
        }

        return result;
    }

  private:
    bool dfs(const std::vector<std::vector<int>> &adj, int node,
             std::vector<bool> &seen, std::vector<bool> &path,
             std::vector<int> &result) {
        if (path[node]) {
            return false;
        }
        if (seen[node]) {
            return true;
        }
        seen[node] = true;
        path[node] = true;

        for (int next : adj[node]) {
            if (!dfs(adj, next, seen, path, result)) {
                return false;
            }
        }

        path[node] = false;
        result.push_back(node);
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>,
                          std::vector<int>>>
        tests = {
            {{2, {{1, 0}}}, {0, 1}},
            {{4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}}, {0, 1, 2, 3}},
            {{1, {}}, {0}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.findOrder(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
