// 812. Largest Triangle Area
// Difficulty: Easy

// Given an array of points on the X-Y plane points where points[i] = [xi, yi],
// return the area of the largest triangle that can be formed by any three
// different points. Answers within 10-5 of the actual answer will be accepted.

// Example 1:

// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2.00000
// Explanation: The five points are shown in the above figure. The red triangle
// is the largest.

// Example 2:

// Input: points = [[1,0],[0,0],[0,1]]
// Output: 0.50000

// Constraints:

//     3 <= points.length <= 50
//     -50 <= xi, yi <= 50
//     All the given points are unique.

#include <algorithm>
#include <cmath>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    double largestTriangleArea(std::vector<std::vector<int>> &points) {
        double result = 0;
        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                for (size_t k = j + 1; k < points.size(); k++) {
                    result =
                        std::max(result, area(points[i], points[j], points[k]));
                }
            }
        }
        return result;
    }

  private:
    double area(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c) {
        return 0.5 * std::abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] -
                              a[1] * b[0] - b[1] * c[0] - c[1] * a[0]);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, double>> tests = {
        {{{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}}, 2.0},
        {{{1, 0}, {0, 0}, {0, 1}}, 0.5},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.largestTriangleArea(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
