// 2054. Two Best Non-Overlapping Events
// Difficulty: Medium

// You are given a 0-indexed 2D integer array of events where events[i] =
// [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends
// at endTimei, and if you attend this event, you will receive a value of
// valuei. You can choose at most two non-overlapping events to attend such that
// the sum of their values is maximized.

// Return this maximum sum.

// Note that the start time and end time is inclusive: that is, you cannot
// attend two events where one of them starts and the other ends at the same
// time. More specifically, if you attend an event with end time t, the next
// event must start at or after t + 1.

// Example 1:

// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

// Example 2:
// Example 1 Diagram

// Input: events = [[1,3,2],[4,5,2],[1,5,5]]
// Output: 5
// Explanation: Choose event 2 for a sum of 5.

// Example 3:

// Input: events = [[1,5,3],[1,5,1],[6,6,5]]
// Output: 8
// Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.

// Constraints:

// 2 <= events.length <= 105
// events[i].length == 3
// 1 <= startTimei <= endTimei <= 109
// 1 <= valuei <= 106

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maxTwoEvents(std::vector<std::vector<int>> &events) {
        std::vector<std::vector<int>> memo(events.size(), std::vector(3, -1));
        std::ranges::sort(events);
        return this->recurse(events, 0, 0, memo);
    }

  private:
    int recurse(const std::vector<std::vector<int>> &events, int i, int count,
                std::vector<std::vector<int>> &memo) {
        if (count == 2 || i >= events.size()) {
            return 0;
        }
        if (memo[i][count] != -1) {
            return memo[i][count];
        }
        int end = events[i][1];
        int l = i + 1, r = events.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (events[m][0] > end) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        int add  = events[i][2] + (l < events.size() && events[l][0] > end
                                       ? recurse(events, l, count + 1, memo)
                                       : 0);
        int skip = recurse(events, i + 1, count, memo);
        return memo[i][count] = std::max(add, skip);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 3, 2}, {4, 5, 2}, {2, 4, 3}}, 4},
        {{{1, 3, 2}, {4, 5, 2}, {1, 5, 5}}, 5},
        {{{1, 5, 3}, {1, 5, 1}, {6, 6, 5}}, 8},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxTwoEvents(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
