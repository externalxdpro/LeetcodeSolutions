#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int furthestBuilding(std::vector<int> &heights, int bricks, int ladders) {
        std::priority_queue<int> pastHeights;
        for (int i = 0; i < heights.size() - 1; i++) {
            if (heights[i + 1] <= heights[i]) {
                continue;
            }
            if (bricks < heights[i + 1] - heights[i]) {
                if (ladders == 0) {
                    return i;
                }
                if (!pastHeights.empty() &&
                    heights[i + 1] - heights[i] < pastHeights.top()) {
                    bricks += pastHeights.top();
                    pastHeights.pop();
                    i--;
                }
                ladders--;
                continue;
            }

            bricks -= heights[i + 1] - heights[i];
            pastHeights.push(heights[i + 1] - heights[i]);
        }

        return heights.size() - 1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int>, int>> tests =
        {
            {{{4, 2, 7, 6, 9, 14, 12}, 5, 1}, 4},
            {{{4, 12, 2, 7, 3, 18, 20, 3, 19}, 10, 2}, 7},
            {{{14, 3, 19, 3}, 17, 0}, 3},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.furthestBuilding(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
