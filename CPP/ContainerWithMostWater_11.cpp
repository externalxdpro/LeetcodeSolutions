// 11. Container With Most Water
// Difficulty: Medium

// You are given an integer array height of length n. There are n vertical lines
// drawn such that the two endpoints of the ith line are (i, 0) and (i,
// height[i]).

// Find two lines that together with the x-axis form a container, such that the
// container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Example 1:

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array
// [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
// container can contain is 49.

// Example 2:

// Input: height = [1,1]
// Output: 1

// Constraints:

//     n == height.length
//     2 <= n <= 105
//     0 <= height[i] <= 104

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maxArea(std::vector<int> &height) {
        int result = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            int h = (j - i) * std::min(height[i], height[j]);
            result = std::max(result, h);

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
        {{1, 1}, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxArea(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
