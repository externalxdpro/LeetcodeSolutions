// 2127. Maximum Employees to Be Invited to a Meeting
// Difficulty: Hard

// A company is organizing a meeting and has a list of n employees, waiting to
// be invited. They have arranged for a large circular table, capable of seating
// any number of employees.

// The employees are numbered from 0 to n - 1. Each employee has a favorite
// person and they will attend the meeting only if they can sit next to their
// favorite person at the table. The favorite person of an employee is not
// themself.

// Given a 0-indexed integer array favorite, where favorite[i] denotes the
// favorite person of the ith employee, return the maximum number of employees
// that can be invited to the meeting.

// Example 1:

// Input: favorite = [2,2,1,2]
// Output: 3
// Explanation:
// The above figure shows how the company can invite employees 0, 1, and 2, and
// seat them at the round table. All employees cannot be invited because
// employee 2 cannot sit beside employees 0, 1, and 3, simultaneously. Note that
// the company can also invite employees 1, 2, and 3, and give them their
// desired seats. The maximum number of employees that can be invited to the
// meeting is 3.

// Example 2:

// Input: favorite = [1,2,0]
// Output: 3
// Explanation:
// Each employee is the favorite person of at least one other employee, and the
// only way the company can invite them is if they invite every employee. The
// seating arrangement will be the same as that in the figure given in example
// 1:
// - Employee 0 will sit between employees 2 and 1.
// - Employee 1 will sit between employees 0 and 2.
// - Employee 2 will sit between employees 1 and 0.
// The maximum number of employees that can be invited to the meeting is 3.

// Example 3:

// Input: favorite = [3,0,1,4,1]
// Output: 4
// Explanation:
// The above figure shows how the company will invite employees 0, 1, 3, and 4,
// and seat them at the round table. Employee 2 cannot be invited because the
// two spots next to their favorite employee 1 are taken. So the company leaves
// them out of the meeting. The maximum number of employees that can be invited
// to the meeting is 4.

// Constraints:

//     n == favorite.length
//     2 <= n <= 105
//     0 <= favorite[i] <= n - 1
//     favorite[i] != i

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int maximumInvitations(std::vector<int> &favorite) {
        std::vector<std::vector<int>> revGraph(favorite.size());
        for (int i = 0; i < favorite.size(); i++) {
            revGraph[favorite[i]].push_back(i);
        }

        int               longest = 0, pairs = 0;
        std::vector<bool> visited(favorite.size(), false);

        for (int i = 0; i < favorite.size(); i++) {
            if (visited[i]) {
                continue;
            }
            std::unordered_map<int, int> visitedMap;
            int                          curr = i;
            int                          dist = 0;
            while (true) {
                if (visited[curr]) {
                    break;
                }
                visited[curr]    = true;
                visitedMap[curr] = dist++;
                int next         = favorite[curr];
                if (visitedMap.contains(next)) {
                    int length = dist - visitedMap[next];
                    longest    = std::max(longest, length);
                    if (length == 2) {
                        std::unordered_set visitedSet = {curr, next};
                        pairs += 2 + bfs(revGraph, curr, visitedSet) +
                                 bfs(revGraph, next, visitedSet);
                    }
                    break;
                }
                curr = next;
            }
        }
        return std::max(longest, pairs);
    }

  private:
    int bfs(std::vector<std::vector<int>> &revGraph, int start,
            std::unordered_set<int> &visited) {
        std::queue<std::pair<int, int>> q{{{start, 0}}};
        int                             max = 0;
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            for (int n : revGraph[node]) {
                if (visited.contains(n)) {
                    continue;
                }
                visited.insert(n);
                q.emplace(n, dist + 1);
                max = std::max(max, dist + 1);
            }
        }
        return max;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 2, 1, 2}, 3},
        {{1, 2, 0}, 3},
        {{3, 0, 1, 4, 1}, 4},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumInvitations(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
