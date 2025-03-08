// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// Difficulty: Easy

// You are given a 0-indexed string blocks of length n, where blocks[i] is
// either 'W' or 'B', representing the color of the ith block. The characters
// 'W' and 'B' denote the colors white and black, respectively.

// You are also given an integer k, which is the desired number of consecutive
// black blocks.

// In one operation, you can recolor a white block such that it becomes a black
// block.

// Return the minimum number of operations needed such that there is at least
// one occurrence of k consecutive black blocks.

// Example 1:

// Input: blocks = "WBBWWBBWBW", k = 7
// Output: 3
// Explanation:
// One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and
// 4th blocks so that blocks = "BBBBBBBWBW". It can be shown that there is no
// way to achieve 7 consecutive black blocks in less than 3 operations.
// Therefore, we return 3.

// Example 2:

// Input: blocks = "WBWBBBW", k = 2
// Output: 0
// Explanation:
// No changes need to be made, since 2 consecutive black blocks already exist.
// Therefore, we return 0.

// Constraints:

//     n == blocks.length
//     1 <= n <= 100
//     blocks[i] is either 'W' or 'B'.
//     1 <= k <= n

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int minimumRecolors(std::string blocks, int k) {
        int min = 0, curr = 0;
        int l = 0, r = 0;
        for (r = 0; r < k; r++) {
            min += blocks[r] == 'W';
        }
        curr = min;
        while (r < blocks.size()) {
            curr += blocks[r++] == 'W';
            curr -= blocks[l++] == 'W';
            min = std::min(min, curr);
        }
        return min;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, int>> tests = {
        {{"WBBWWBBWBW", 7}, 3},
        {{"WBWBBBW", 2}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimumRecolors(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
