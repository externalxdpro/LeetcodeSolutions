// 2406. Divide Intervals Into Minimum Number of Groups
// Difficulty: Medium

// You are given a 2D integer array intervals where intervals[i] = [lefti,
// righti] represents the inclusive interval [lefti, righti].

// You have to divide the intervals into one or more groups such that each
// interval is in exactly one group, and no two intervals that are in the same
// group intersect each other.

// Return the minimum number of groups you need to make.

// Two intervals intersect if there is at least one common number between them.
// For example, the intervals [1, 5] and [5, 8] intersect.

// Example 1:

// Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
// Output: 3
// Explanation: We can divide the intervals into the following groups:
// - Group 1: [1, 5], [6, 8].
// - Group 2: [2, 3], [5, 10].
// - Group 3: [1, 10].
// It can be proven that it is not possible to divide the intervals into fewer
// than 3 groups.

// Example 2:

// Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
// Output: 1
// Explanation: None of the intervals overlap, so we can put all of them in one
// group.

// Constraints:

//     1 <= intervals.length <= 105
//     intervals[i].length == 2
//     1 <= lefti <= righti <= 106

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minGroups(std::vector<std::vector<int>> &intervals) {
        std::vector<std::pair<int, int>> events;
        events.reserve(intervals.size() * 2);
        for (const auto &interval : intervals) {
            events.emplace_back(interval[0], 1);
            events.emplace_back(interval[1] + 1, -1);
        }
        std::sort(events.begin(), events.end());

        int curr = 0, max = 0;
        for (const auto &e : events) {
            curr += e.second;
            max = std::max(max, curr);
        }

        return max;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}}, 3},
        {{{1, 3}, {5, 6}, {8, 10}, {11, 13}}, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minGroups(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
