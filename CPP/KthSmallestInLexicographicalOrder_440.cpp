// 440. K-th Smallest in Lexicographical Order
// Difficulty: Hard

// Given two integers n and k, return the kth lexicographically smallest integer
// in the range [1, n].

// Example 1:
// Input: n = 13, k = 2
// Output: 10
// Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6,
// 7, 8, 9], so the second smallest number is 10.

// Example 2:
// Input: n = 1, k = 1
// Output: 1

// Constraints:
//     1 <= k <= n <= 10^9

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int findKthNumber(int n, int k) {
        int res = 1;
        k--;
        while (k) {
            int step = count(n, res, res + 1);
            if (step <= k) {
                res++;
                k -= step;
            } else {
                res *= 10;
                k--;
            }
        }
        return res;
    }

  private:
    int count(int n, long long prefix1, long long prefix2) {
        int steps = 0;
        while (prefix1 <= n) {
            steps += std::min((long long)(n + 1), prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, int>> tests = {
        {{13, 2}, 10},
        {{1, 1}, 1},
        {{2, 2}, 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findKthNumber(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
