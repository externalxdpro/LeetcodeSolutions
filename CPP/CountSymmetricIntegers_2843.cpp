// 2843. Count Symmetric Integers
// Difficulty: Easy

// You are given two positive integers low and high.

// An integer x consisting of 2 * n digits is symmetric if the sum of the first
// n digits of x is equal to the sum of the last n digits of x. Numbers with an
// odd number of digits are never symmetric.

// Return the number of symmetric integers in the range [low, high].

// Example 1:

// Input: low = 1, high = 100
// Output: 9
// Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33,
// 44, 55, 66, 77, 88, and 99.

// Example 2:

// Input: low = 1200, high = 1230
// Output: 4
// Explanation: There are 4 symmetric integers between 1200 and 1230: 1203,
// 1212, 1221, and 1230.

// Constraints:

//     1 <= low <= high <= 104

#include <algorithm>
#include <fmt/ranges.h>
#include <string_view>
#include <vector>

class Solution {
  public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        for (int i = low; i <= high; i++) {
            result += isSymmetric(i);
        }
        return result;
    }

  private:
    bool isSymmetric(int num) {
        std::string str = std::to_string(num);
        int         n   = str.size();
        if (n % 2 == 1) {
            return false;
        }
        int l = 0, r = 0;
        for (int i = 0; i < n / 2; i++) {
            l += str[i] - '0';
            r += str[i + n / 2] - '0';
        }
        return l == r;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, int>> tests = {
        {{1, 100}, 9},
        {{1200, 1230}, 4},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countSymmetricIntegers(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
