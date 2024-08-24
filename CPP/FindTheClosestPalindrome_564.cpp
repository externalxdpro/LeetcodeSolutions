// 564. Find the Closest Palindrome
// Difficulty: Hard

// Given a string n representing an integer, return the closest integer (not
// including itself), which is a palindrome. If there is a tie, return the
// smaller one.

// The closest is defined as the absolute difference minimized between two
// integers.

// Example 1:

// Input: n = "123"
// Output: "121"

// Example 2:

// Input: n = "1"
// Output: "0"
// Explanation: 0 and 2 are the closest palindromes but we return the smallest
// which is 0.

// Constraints:

//     1 <= n.length <= 18
//     n consists of only digits.
//     n does not have leading zeros.
//     n is representing an integer in the range [1, 10^18 - 1].

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string nearestPalindromic(std::string n) {
        long num = std::stol(n), temp = num;
        long large = createPalindrome(temp), small = large;
        long unit = std::pow(10, (n.size() == 1) ? 0 : n.size() / 2 - 1);

        while (large <= num) {
            large = createPalindrome(temp += unit);
        }
        temp = num;
        while (small >= num) {
            small = createPalindrome(temp -= unit);
        }
        return (large - num < num - small) ? std::to_string(large)
                                           : std::to_string(small);
    }

  private:
    long createPalindrome(long n) {
        std::string str = std::to_string(n);
        int         l = 0, r = str.size() - 1;
        while (l < r) {
            str[r--] = str[l++];
        }
        return std::stol(str);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"123", "121"},     {"1", "0"},       {"10", "9"},
        {"11911", "11811"}, {"9009", "8998"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.nearestPalindromic(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
