// 149. Max Points on a Line
// Difficulty: Hard

// Given an array of points where points[i] = [xi, yi] represents a point on the
// X-Y plane, return the maximum number of points that lie on the same straight
// line.

// Example 1:

// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3
// Example 2:

// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4

// Constraints:

// 1 <= points.length <= 300
// points[i].length == 2
// -104 <= xi, yi <= 104
// All the points are unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int maxPoints(std::vector<std::vector<int>> &points) {
        int result = 1;

        for (size_t i = 0; i < points.size(); i++) {
            std::unordered_map<double, int> slopes;
            for (size_t j = i + 1; j < points.size(); j++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                double slope = (dx != 0) ? (double)dy / dx
                                         : std::numeric_limits<int>::max();
                slopes[slope]++;
                result = std::max(result, slopes[slope] + 1);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 1}, {2, 2}, {3, 3}}, 3},
        {{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}, 4},
        {{{0, 0}}, 1},
        {{{0, 0}, {4, 5}, {7, 8}, {8, 9}, {5, 6}, {3, 4}, {1, 1}}, 5},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.maxPoints(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
