// Difficulty: Medium
// Given an array of intervals where intervals[i] = [starti, endi], merge all
// overlapping intervals, and return an array of the non-overlapping intervals
// that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// Constraints:
//     1 <= intervals.length <= 10^4
//     intervals[i].length == 2
//     0 <= starti <= endi <= 10^4

#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <vector>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
    std::ranges::sort(intervals, [](auto i, auto j) { return i[0] < j[0]; });

    std::vector<std::vector<int>> result = {intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
        auto &curr = intervals[i];
        auto &back = result.back();
        bool found = false;
        if (back[0] >= curr[0] && back[0] <= curr[1]) {
            back[0] = curr[0];
            found = true;
        }
        if (back[1] <= curr[1] && back[1] >= curr[0]) {
            back[1] = curr[1];
            found = true;
        }

        if (curr[0] > back[0] && curr[0] < back[1]) {
            continue;
        }

        if (!found) {
            result.push_back(curr);
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<std::vector<int>>> tests = {
        {{1, 3}, {2, 6}, {8, 10}, {15, 18}},
        {{1, 4}, {4, 5}},
        {{1, 4}, {2, 3}},
    };

    for (auto test : tests) {
        for (auto i : merge(test)) {
            std::cout << std::format("[{},{}] ", i[0], i[1]);
        }
        std::cout << std::endl;
    }

    return 0;
}
