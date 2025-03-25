// 3394. Check if Grid can be Cut into Sections
// Difficulty: Medium

// You are given an integer n representing the dimensions of an n x n grid, with
// the origin at the bottom-left corner of the grid. You are also given a 2D
// array of coordinates rectangles, where rectangles[i] is in the form [startx,
// starty, endx, endy], representing a rectangle on the grid. Each rectangle is
// defined as follows:

//     (startx, starty): The bottom-left corner of the rectangle.
//     (endx, endy): The top-right corner of the rectangle.

// Note that the rectangles do not overlap. Your task is to determine if it is
// possible to make either two horizontal or two vertical cuts on the grid such
// that:

//     Each of the three resulting sections formed by the cuts contains at least
//     one rectangle. Every rectangle belongs to exactly one section.

// Return true if such cuts can be made; otherwise, return false.

// Example 1:

// Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]

// Output: true

// Explanation:

// The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y
// = 4. Hence, output is true.

// Example 2:

// Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]

// Output: true

// Explanation:

// We can make vertical cuts at x = 2 and x = 3. Hence, output is true.

// Example 3:

// Input: n = 4, rectangles =
// [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]

// Output: false

// Explanation:

// We cannot make two horizontal or two vertical cuts that satisfy the
// conditions. Hence, output is false.

// Constraints:

//     3 <= n <= 109
//     3 <= rectangles.length <= 105
//     0 <= rectangles[i][0] < rectangles[i][2] <= n
//     0 <= rectangles[i][1] < rectangles[i][3] <= n
//     No two rectangles overlap.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool checkValidCuts(int n, std::vector<std::vector<int>> &rectangles) {
        std::ranges::sort(rectangles,
                          [](auto &a, auto &b) { return a[0] < b[0]; });
        int gaps = 0, last = rectangles[0][2];
        for (int i = 1; i < rectangles.size(); i++) {
            if (last <= rectangles[i][0]) {
                gaps++;
            }
            last = std::max(last, rectangles[i][2]);
        }
        if (gaps >= 2) {
            return true;
        }

        std::ranges::sort(rectangles,
                          [](auto &a, auto &b) { return a[1] < b[1]; });
        gaps = 0, last = rectangles[0][3];
        for (int i = 1; i < rectangles.size(); i++) {
            if (last <= rectangles[i][1]) {
                gaps++;
            }
            last = std::max(last, rectangles[i][3]);
        }
        return gaps >= 2;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>, bool>>
        tests = {
            {{5, {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}}},
             true},
            {{4, {{0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}}},
             true},
            {{4,
              {{0, 2, 2, 4},
               {1, 0, 3, 2},
               {2, 2, 3, 4},
               {3, 0, 4, 2},
               {3, 2, 4, 4}}},
             false},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.checkValidCuts(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
