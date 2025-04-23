// 1399. Count Largest Group
// Difficulty: Easy

// You are given an integer n.

// Each number from 1 to n is grouped according to the sum of its digits.

// Return the number of groups that have the largest size.

// Example 1:

// Input: n = 13
// Output: 4
// Explanation: There are 9 groups in total, they are grouped according sum of
// its digits of numbers from 1 to 13: [1,10], [2,11], [3,12], [4,13], [5], [6],
// [7], [8], [9]. There are 4 groups with largest size.

// Example 2:

// Input: n = 2
// Output: 2
// Explanation: There are 2 groups [1], [2] of size 1.

// Constraints:

//     1 <= n <= 104

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int countLargestGroup(int n) {
        std::unordered_map<int, int> sums;
        for (int i = 1; i <= n; i++) {
            int k = 0, curr = i;
            while (curr) {
                k += curr % 10;
                curr /= 10;
            }
            sums[k]++;
        }
        int max = std::ranges::max_element(sums, [](auto a, auto b) {
                      return a.second < b.second;
                  })->second;
        return std::accumulate(
            sums.begin(), sums.end(), 0,
            [&](auto a, auto b) { return a + (b.second == max); });
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {13, 4},
        {2, 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countLargestGroup(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
