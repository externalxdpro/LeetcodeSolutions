// Difficulty: Medium
// Given the coordinates of four points in 2D space p1, p2, p3 and p4, return
// true if the four points construct a square. The coordinate of a point pi is
// represented as [xi, yi]. The input is not given in any order. A valid square
// has four equal sides with positive length and four equal angles (90-degree
// angles).

// Example 1:
// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: true

// Example 2:
// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
// Output: false

// Example 3:
// Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
// Output: true

// Constraints:
//     p1.length == p2.length == p3.length == p4.length == 2
//     -10^4 <= xi, yi <= 10^4

#include <algorithm>
#include <cmath>
#include <format>
#include <iostream>
#include <vector>

bool validSquare(std::vector<int> &p1, std::vector<int> &p2,
                 std::vector<int> &p3, std::vector<int> &p4) {
    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
        return false;
    }

    std::vector<std::vector<int>> points = {p1, p2, p3, p4};
    std::ranges::sort(points);

    if (points[0][0] == points[1][0] || points[2][0] == points[3][0] ||
        points[0][1] == points[2][1] || points[1][1] == points[3][1]) {
        if (points[0][0] != points[1][0] || points[2][0] != points[3][0] ||
            points[0][1] != points[2][1] || points[1][1] != points[3][1]) {
            return false;
        }
        if (abs(points[0][1] - points[1][1]) !=
            abs(points[0][0] - points[2][0])) {
            return false;
        }
    } else {
        double diag1, diag2;
        double l1 = abs(points[0][1] - points[3][1]);
        double w1 = abs(points[0][0] - points[3][0]);
        diag1 = sqrt(l1 * l1 + w1 * w1);

        double l2 = abs(points[1][1] - points[2][1]);
        double w2 = abs(points[1][0] - points[2][0]);
        diag2 = sqrt(l2 * l2 + w2 * w2);

        if (diag1 != diag2)
            return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, bool>> tests = {
        {{{0, 0}, {1, 1}, {1, 0}, {0, 1}}, true},
        {{{0, 0}, {1, 1}, {1, 0}, {0, 12}}, false},
        {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, true},
        {{{1134, -2539}, {492, -1255}, {-792, -1897}, {-150, -3181}}, true},
        {{{0, 0}, {5, 0}, {5, 4}, {0, 4}}, false},
        {{{0, 0}, {0, 0}, {0, 0}, {0, 0}}, false},
        {{{2, 1}, {1, 2}, {0, 0}, {2, 0}}, false},
        {{{0, 0}, {-1, 1}, {0, 1}, {1, 0}}, false},
    };

    for (auto [test, ans] : tests) {
        int result = validSquare(test[0], test[1], test[2], test[3]);
        for (auto i : test) {
            for (auto j : i) {
                std::cout << j << ',';
            }
            std::cout << ' ';
        }
        std::cout << std::format(": {} {}", result, result == ans ? "✅" : "❌")
                  << std::endl;
    }

    return 0;
}
