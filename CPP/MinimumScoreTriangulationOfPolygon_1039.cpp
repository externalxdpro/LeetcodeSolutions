// 1039. Minimum Score Triangulation of Polygon
// Difficulty: Medium

// You have a convex n-sided polygon where each vertex has an integer value. You
// are given an integer array values where values[i] is the value of the ith
// vertex in clockwise order.

// Polygon triangulation is a process where you divide a polygon into a set of
// triangles and the vertices of each triangle must also be vertices of the
// original polygon. Note that no other shapes other than triangles are allowed
// in the division. This process will result in n - 2 triangles.

// You will triangulate the polygon. For each triangle, the weight of that
// triangle is the product of the values at its vertices. The total score of the
// triangulation is the sum of these weights over all n - 2 triangles.

// Return the minimum possible score that you can achieve with some
// triangulation of the polygon.

// Example 1:

// Input: values = [1,2,3]

// Output: 6

// Explanation: The polygon is already triangulated, and the score of the only
// triangle is 6.

// Example 2:

// Input: values = [3,7,4,5]

// Output: 144

// Explanation: There are two triangulations, with possible scores: 3*7*5 +
// 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144. The minimum score is 144.

// Example 3:

// Input: values = [1,3,1,4,1,5]

// Output: 13

// Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1
// = 13.

// Constraints:

//     n == values.length
//     3 <= n <= 50
//     1 <= values[i] <= 100

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int minScoreTriangulation(std::vector<int> &values) {
        std::unordered_map<int, int> memo;
        return recurse(values, 0, values.size() - 1, memo);
    }

  private:
    int recurse(std::vector<int> &values, int i, int j,
                std::unordered_map<int, int> &memo) {
        if (i + 2 > j) {
            return 0;
        }
        if (i + 2 == j) {
            return values[i] * values[i + 1] * values[j];
        }

        int key = i * values.size() + j;
        if (memo.contains(key)) {
            return memo[key];
        }
        int min = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            min = std::min(min, values[i] * values[k] * values[j] +
                                    recurse(values, i, k, memo) +
                                    recurse(values, k, j, memo));
        }
        return memo[key] = min;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 3}, 6},
        {{3, 7, 4, 5}, 144},
        {{1, 3, 1, 4, 1, 5}, 13},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minScoreTriangulation(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
