// Difficulty: Hard
// We have n jobs, where every job is scheduled to be done from startTime[i] to
// endTime[i], obtaining a profit of profit[i].

// You're given the startTime, endTime and profit arrays, return the maximum
// profit you can take such that there are no two jobs in the subset with
// overlapping time range.

// If you choose a job that ends at time X you will be able to start another job
// that starts at time X.

// Example 1:
// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job.
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

// Example 2:
// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
// [20,20,100,70,60] Output: 150 Explanation: The subset chosen is the first,
// fourth and fifth job. Profit obtained 150 = 20 + 70 + 60.

// Example 3:
// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
// Output: 6

// Constraints:
//     1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
//     1 <= startTime[i] < endTime[i] <= 10^9
//     1 <= profit[i] <= 10^4

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

int dfs(int currIndex, std::vector<std::vector<int>> &schedules,
        std::vector<int> &map) {
    if (currIndex == schedules.size()) {
        return 0;
    }
    if (map[currIndex] != -1) {
        return map[currIndex];
    }
    int nextIndex = std::distance(
        schedules.begin(),
        std::upper_bound(schedules.begin(), schedules.end(),
                         schedules[currIndex][1],
                         [](int i, std::vector<int> j) { return i <= j[0]; }));
    map[currIndex] =
        std::max(dfs(currIndex + 1, schedules, map),
                 dfs(nextIndex, schedules, map) + schedules[currIndex][2]);

    return map[currIndex];
}

int jobScheduling(std::vector<int> &startTime, std::vector<int> &endTime,
                  std::vector<int> &profit) {
    std::vector<std::vector<int>> schedules(startTime.size());
    for (int i = 0; i < startTime.size(); i++) {
        schedules[i] = {startTime[i], endTime[i], profit[i]};
    }
    std::ranges::sort(schedules);

    std::vector<int> map(startTime.size(), -1);
    return dfs(0, schedules, map);

    return 0;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<std::vector<int>>> tests = {
        {{1, 2, 3, 3}, {3, 4, 5, 6}, {50, 10, 40, 70}},
        {{1, 2, 3, 4, 6}, {3, 5, 10, 6, 9}, {20, 20, 100, 70, 60}},
    };

    for (auto test : tests) {
        fmt::print("{}: {}\n", test, jobScheduling(test[0], test[1], test[2]));
    }

    return 0;
}
