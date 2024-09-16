// 539. Minimum Time Difference
// Difficulty: Medium

// Given a list of 24-hour clock time points in "HH:MM" format, return the
// minimum minutes difference between any two time-points in the list.

// Example 1:
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

// Constraints:
//     2 <= timePoints.length <= 2 * 10^4
//     timePoints[i] is in the format "HH:MM".

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <vector>

class Solution {
  public:
    int findMinDifference(std::vector<std::string> &timePoints) {
        std::vector<int> mins;
        mins.reserve(timePoints.size() * 2);
        for (std::string &time : timePoints) {
            int h = (time[0] - '0') * 10 + (time[1] - '0');
            int m = (time[3] - '0') * 10 + (time[4] - '0');
            mins.push_back(h * 60 + m);
            mins.push_back((h + 24) * 60 + m);
        }
        std::ranges::sort(mins);
        int result = std::numeric_limits<int>::max();
        for (int i = 1; i < mins.size(); i++) {
            result = std::min(result, mins[i] - mins[i - 1]);
            if (result == 0) {
                return result;
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, int>> tests = {
        {{"23:59", "00:00"}, 1},
        {{"00:00", "23:59", "00:00"}, 0},
        {{"05:31", "22:08", "00:35"}, 147},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findMinDifference(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
