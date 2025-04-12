// 3272. Find the Count of Good Integers
// Difficulty: Hard

// You are given two positive integers n and k.

// An integer x is called k-palindromic if:

//     x is a

//     .
//     x is divisible by k.

// An integer is called good if its digits can be rearranged to form a
// k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form
// the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a
// k-palindromic integer.

// Return the count of good integers containing n digits.

// Note that any integer must not have leading zeros, neither before nor after
// rearrangement. For example, 1010 cannot be rearranged to form 101.

// Example 1:

// Input: n = 3, k = 5

// Output: 27

// Explanation:

// Some of the good integers are:

//     551 because it can be rearranged to form 515.
//     525 because it is already k-palindromic.

// Example 2:

// Input: n = 1, k = 4

// Output: 2

// Explanation:

// The two good integers are 4 and 8.

// Example 3:

// Input: n = 5, k = 6

// Output: 2468

// Constraints:

//     1 <= n <= 10
//     1 <= k <= 9

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    long long countGoodIntegers(int n, int k) {
        std::unordered_set<std::string> strs;
        int base = std::pow(10, (n - 1) / 2), skip = n & 1;
        for (int i = base; i < base * 10; i++) {
            std::string s = std::to_string(i);
            s += std::string(s.rbegin() + skip, s.rend());
            long long num = std::stoll(s);
            if (num % k == 0) {
                std::ranges::sort(s);
                strs.insert(s);
            }
        }

        std::vector<long long> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        long long result = 0;
        for (auto &s : strs) {
            std::vector<int> counts(10);
            for (char c : s) {
                counts[c - '0']++;
            }
            long long curr = (n - counts[0]) * factorial[n - 1];
            for (int i : counts) {
                curr /= factorial[i];
            }
            result += curr;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, long long>> tests = {
        {{3, 5}, 27},
        {{1, 4}, 2},
        {{5, 6}, 2468},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countGoodIntegers(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
