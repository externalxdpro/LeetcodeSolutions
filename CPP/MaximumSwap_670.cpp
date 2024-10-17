// 670. Maximum Swap
// Difficulty: Medium

// You are given an integer num. You can swap two digits at most once to get the
// maximum valued number.

// Return the maximum valued number you can get.

// Example 1:

// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.

// Example 2:

// Input: num = 9973
// Output: 9973
// Explanation: No swap.

// Constraints:

//     0 <= num <= 108

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maximumSwap(int num) {
        std::string      numStr = std::to_string(num);
        std::vector<int> max(numStr.size());
        max.back() = numStr.size() - 1;
        for (int i = numStr.size() - 2; i >= 0; i--) {
            max[i] = std::max(i, max[i + 1], [&](int a, int b) {
                return numStr[a] <= numStr[b];
            });
        }
        for (int i = 0; i < numStr.size(); i++) {
            if (numStr[i] < numStr[max[i]]) {
                std::swap(numStr[i], numStr[max[i]]);
                return std::stoi(numStr);
            }
        }
        return num;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {2736, 7236},
        {9973, 9973},
        {98368, 98863},
        {1993, 9913},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumSwap(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
