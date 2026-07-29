// 218. The Skyline Problem
// Difficulty: Hard

// A city's skyline is the outer contour of the silhouette formed by all the
// buildings in that city when viewed from a distance. Given the locations and
// heights of all the buildings, return the skyline formed by these buildings
// collectively.

// The geometric information of each building is given in the array buildings
// where buildings[i] = [lefti, righti, heighti]:

// lefti is the x coordinate of the left edge of the ith building.
// righti is the x coordinate of the right edge of the ith building.
// heighti is the height of the ith building.
// You may assume all buildings are perfect rectangles grounded on an absolutely
// flat surface at height 0.

// The skyline should be represented as a list of "key points" sorted by their
// x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left
// endpoint of some horizontal segment in the skyline except the last point in
// the list, which always has a y-coordinate 0 and is used to mark the skyline's
// termination where the rightmost building ends. Any ground between the
// leftmost and rightmost buildings should be part of the skyline's contour.

// Note: There must be no consecutive horizontal lines of equal height in the
// output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is
// not acceptable; the three lines of height 5 should be merged into one in the
// final output as such: [...,[2 3],[4 5],[12 7],...]

// Example 1:

// Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
// Explanation:
// Figure A shows the buildings of the input.
// Figure B shows the skyline formed by those buildings. The red points in
// figure B represent the key points in the output list. Example 2:

// Input: buildings = [[0,2,3],[2,5,3]]
// Output: [[0,3],[5,0]]

// Constraints:

// 1 <= buildings.length <= 104
// 0 <= lefti < righti <= 231 - 1
// 1 <= heighti <= 231 - 1
// buildings is sorted by lefti in non-decreasing order.

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <set>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    getSkyline(std::vector<std::vector<int>> &buildings) {
        std::vector<std::vector<int>> result;
        std::priority_queue<std::tuple<int, bool, int>,
                            std::vector<std::tuple<int, bool, int>>,
                            std::greater<>>
            pq;
        std::multiset<int, std::greater<>> heights;

        for (std::vector<int> &b : buildings) {
            pq.emplace(b[0], false, b[2]);
            pq.emplace(b[1], true, b[2]);
        }

        while (!pq.empty()) {
            int prev = heights.empty() ? 0 : *heights.begin();

            int x;
            do {
                x = std::get<0>(pq.top());
                bool end = std::get<1>(pq.top());
                int height = std::get<2>(pq.top());
                pq.pop();
                if (end) {
                    heights.extract(height);
                } else {
                    heights.insert(height);
                }
            } while (!pq.empty() && std::get<0>(pq.top()) == x);

            int next = heights.empty() ? 0 : *heights.begin();

            if (prev != next) {
                result.push_back({x, next});
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>>
        tests = {
            {{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}},
             {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}}},
            {{{0, 2, 3}, {2, 5, 3}}, {{0, 3}, {5, 0}}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.getSkyline(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
