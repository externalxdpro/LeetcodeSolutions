// 166. Fraction to Recurring Decimal
// Difficulty: Medium

// Given two integers representing the numerator and denominator of a fraction,
// return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in
// parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for
// all the given inputs.

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"

// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"

// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"

// Constraints:

//     -231 <= numerator, denominator <= 231 - 1
//     denominator != 0

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        std::string result;
        if ((numerator < 0 && denominator >= 0) ||
            (numerator >= 0 && denominator < 0)) {
            result += '-';
        }

        long long n = std::abs((long long)numerator);
        long long d = std::abs((long long)denominator);
        long long q = n / d;
        long long r = n % d;
        result += std::to_string(q);

        if (r == 0) {
            return result;
        }
        result += '.';

        std::unordered_map<int, int> freq;
        std::string fractional;

        int i = 0;
        while (r != 0) {
            auto it = freq.find(r);
            if (it != freq.end()) {
                fractional.insert(it->second, "(");
                fractional += ')';
                break;
            }
            freq[r] = i;
            r *= 10;
            fractional += r / d + '0';
            r %= d;
            i++;
        }

        return result + fractional;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, std::string>> tests = {
        {{1, 2}, "0.5"},
        {{2, 1}, "2"},
        {{4, 333}, "0.(012)"},
        {{-1, -2147483648}, "0.0000000004656612873077392578125"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.fractionToDecimal(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
