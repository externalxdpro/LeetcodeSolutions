// 2048. Next Greater Numerically Balanced Number
// Difficulty: Medium

// An integer x is numerically balanced if for every digit d in the number x,
// there are exactly d occurrences of that digit in x.

// Given an integer n, return the smallest numerically balanced number strictly
// greater than n.

// Example 1:

// Input: n = 1
// Output: 22
// Explanation:
// 22 is numerically balanced since:
// - The digit 2 occurs 2 times.
// It is also the smallest numerically balanced number strictly greater than 1.

// Example 2:

// Input: n = 1000
// Output: 1333
// Explanation:
// 1333 is numerically balanced since:
// - The digit 1 occurs 1 time.
// - The digit 3 occurs 3 times.
// It is also the smallest numerically balanced number strictly greater than
// 1000. Note that 1022 cannot be the answer because 0 appeared more than 0
// times.

// Example 3:

// Input: n = 3000
// Output: 3133
// Explanation:
// 3133 is numerically balanced since:
// - The digit 1 occurs 1 time.
// - The digit 3 occurs 3 times.
// It is also the smallest numerically balanced number strictly greater than
// 3000.

// Constraints:

//     0 <= n <= 106

#include <climits>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i < INT_MAX; i++) {
            if (isBalanced(i)) {
                return i;
            }
        }
        return -1;
    }

  private:
    bool isBalanced(int x) {
        std::vector<int> count(10);
        while (x) {
            count[x % 10]++;
            x /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (count[i] > 0 && count[i] != i) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {1, 22},
        {1000, 1333},
        {3000, 3133},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.nextBeautifulNumber(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
