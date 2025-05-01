// 2071. Maximum Number of Tasks You Can Assign
// Difficulty: Hard

// You have n tasks and m workers. Each task has a strength requirement stored
// in a 0-indexed integer array tasks, with the ith task requiring tasks[i]
// strength to complete. The strength of each worker is stored in a 0-indexed
// integer array workers, with the jth worker having workers[j] strength. Each
// worker can only be assigned to a single task and must have a strength greater
// than or equal to the task's strength requirement (i.e., workers[j] >=
// tasks[i]).

// Additionally, you have pills magical pills that will increase a worker's
// strength by strength. You can decide which workers receive the magical pills,
// however, you may only give each worker at most one magical pill.

// Given the 0-indexed integer arrays tasks and workers and the integers pills
// and strength, return the maximum number of tasks that can be completed.

// Example 1:

// Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
// Output: 3
// Explanation:
// We can assign the magical pill and tasks as follows:
// - Give the magical pill to worker 0.
// - Assign worker 0 to task 2 (0 + 1 >= 1)
// - Assign worker 1 to task 1 (3 >= 2)
// - Assign worker 2 to task 0 (3 >= 3)

// Example 2:

// Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
// Output: 1
// Explanation:
// We can assign the magical pill and tasks as follows:
// - Give the magical pill to worker 0.
// - Assign worker 0 to task 0 (0 + 5 >= 5)

// Example 3:

// Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength =
// 10 Output: 2 Explanation: We can assign the magical pills and tasks as
// follows:
// - Give the magical pill to worker 0 and worker 1.
// - Assign worker 0 to task 0 (0 + 10 >= 10)
// - Assign worker 1 to task 1 (10 + 10 >= 15)
// The last pill is not given because it will not make any worker strong enough
// for the last task.

// Constraints:

//     n == tasks.length
//     m == workers.length
//     1 <= n, m <= 5 * 104
//     0 <= pills <= m
//     0 <= tasks[i], workers[j], strength <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <vector>

class Solution {
  public:
    int maxTaskAssign(std::vector<int> &tasks, std::vector<int> &workers,
                      int pills, int strength) {
        std::ranges::sort(tasks);
        std::ranges::sort(workers);

        int l = 1, r = std::min(tasks.size(), workers.size());
        int result = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(tasks, workers, pills, strength, m)) {
                result = m;
                l      = m + 1;
            } else {
                r = m - 1;
            }
        }

        return result;
    }

  private:
    bool check(std::vector<int> &tasks, std::vector<int> &workers, int pills,
               int str, int m) {
        std::map<int, int> ws;
        for (int i = workers.size() - m; i < workers.size(); i++) {
            ws[workers[i]]++;
        }
        for (int i = m - 1; i >= 0; i--) {
            auto worker = ws.rbegin()->first;
            if (worker >= tasks[i]) {
                ws[worker]--;
                if (ws[worker] == 0) {
                    ws.erase(worker);
                }
            } else {
                if (pills == 0) {
                    return false;
                }
                auto it = std::find_if(ws.begin(), ws.end(), [&](auto w) {
                    return w.first >= tasks[i] - str;
                });
                if (it == ws.end()) {
                    return false;
                }
                pills--;
                ws[it->first]--;
                if (ws[it->first] == 0) {
                    ws.erase(it->first);
                }
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::tuple<std::vector<int>, std::vector<int>, int, int>, int>>
        tests = {
            {{{3, 2, 1}, {0, 3, 3}, 1, 1}, 3},
            {{{5, 4}, {0, 0, 0}, 1, 5}, 1},
            {{{10, 15, 30}, {0, 10, 10, 10, 10}, 3, 10}, 2},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.maxTaskAssign(std::get<0>(test), std::get<1>(test),
                                   std::get<2>(test), std::get<3>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
