// 3169. Count Days Without Meetings
// Difficulty: Medium

// You are given a positive integer days representing the total number of days
// an employee is available for work (starting from day 1). You are also given a
// 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents
// the starting and ending days of meeting i (inclusive).

// Return the count of days when the employee is available for work but no
// meetings are scheduled.

// Note: The meetings may overlap.

// Example 1:

// Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

// Output: 2

// Explanation:

// There is no meeting scheduled on the 4th and 8th days.

// Example 2:

// Input: days = 5, meetings = [[2,4],[1,3]]

// Output: 1

// Explanation:

// There is no meeting scheduled on the 5th day.

// Example 3:

// Input: days = 6, meetings = [[1,6]]

// Output: 0

// Explanation:

// Meetings are scheduled for all working days.

// Constraints:

//     1 <= days <= 109
//     1 <= meetings.length <= 105
//     meetings[i].length == 2
//     1 <= meetings[i][0] <= meetings[i][1] <= days

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int countDays(int days, std::vector<std::vector<int>> &meetings) {
        std::ranges::sort(meetings);
        int result = 0, last = 0;
        for (auto &m : meetings) {
            if (m[0] > last + 1) {
                result += m[0] - last - 1;
            }
            last = std::max(last, m[1]);
        }
        return result + days - last;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>, int>>
        tests = {
            {{10, {{5, 7}, {1, 3}, {9, 10}}}, 2},
            {{5, {{2, 4}, {1, 3}}}, 1},
            {{6, {{1, 6}}}, 0},
            {{14,
              {{6, 11},
               {7, 13},
               {8, 9},
               {5, 8},
               {3, 13},
               {11, 13},
               {1, 3},
               {5, 10},
               {8, 13},
               {3, 9}}},
             1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countDays(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
