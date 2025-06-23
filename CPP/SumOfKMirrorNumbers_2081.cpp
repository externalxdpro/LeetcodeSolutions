// 2081. Sum of k-Mirror Numbers
// Difficulty: Hard

// A k-mirror number is a positive integer without leading zeros that reads the
// same both forward and backward in base-10 as well as in base-k.

//     For example, 9 is a 2-mirror number. The representation of 9 in base-10
//     and base-2 are 9 and 1001 respectively, which read the same both forward
//     and backward. On the contrary, 4 is not a 2-mirror number. The
//     representation of 4 in base-2 is 100, which does not read the same both
//     forward and backward.

// Given the base k and the number n, return the sum of the n smallest k-mirror
// numbers.

// Example 1:

// Input: k = 2, n = 5
// Output: 25
// Explanation:
// The 5 smallest 2-mirror numbers and their representations in base-2 are
// listed as follows:
//   base-10    base-2
//     1          1
//     3          11
//     5          101
//     7          111
//     9          1001
// Their sum = 1 + 3 + 5 + 7 + 9 = 25.

// Example 2:

// Input: k = 3, n = 7
// Output: 499
// Explanation:
// The 7 smallest 3-mirror numbers are and their representations in base-3 are
// listed as follows:
//   base-10    base-3
//     1          1
//     2          2
//     4          11
//     8          22
//     121        11111
//     151        12121
//     212        21212
// Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.

// Example 3:

// Input: k = 7, n = 17
// Output: 20379000
// Explanation: The 17 smallest 7-mirror numbers are:
// 1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064,
// 6597956, 6958596

// Constraints:

//     2 <= k <= 9
//     1 <= n <= 30

#include <array>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    std::array<int, 100> digit;

  public:
    long long kMirror(int k, int n) {
        int l = 1, count = 0;
        long long result = 0;
        while (count < n) {
            int r = l * 10;
            for (int even = 0; even <= 1; even++) {
                for (int i = l; i < r && count < n; i++) {
                    long long curr = i;
                    int x = !even ? i / 10 : i;
                    while (x) {
                        curr = curr * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(k, curr)) {
                        count++;
                        result += curr;
                    }
                }
            }

            l = r;
        }
        return result;
    }

  private:
    bool isPalindrome(int k, long long x) {
        int len = -1;
        while (x) {
            len++;
            digit[len] = x % k;
            x /= k;
        }
        for (int i = 0; i <= len / 2; i++) {
            if (digit[i] != digit[len - i]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, long long>> tests = {
        {{2, 5}, 25},
        {{3, 7}, 499},
        {{7, 17}, 20379000},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.kMirror(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
