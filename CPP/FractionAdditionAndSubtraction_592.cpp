// 592. Fraction Addition and Subtraction
// Difficulty: Medium

// Given a string expression representing an expression of fraction addition and
// subtraction, return the calculation result in string format.
// The final result should be an irreducible fraction. If your final result is
// an integer, change it to the format of a fraction that has a denominator 1.
// So in this case, 2 should be converted to 2/1.

// Example 1:
// Input: expression = "-1/2+1/2"
// Output: "0/1"

// Example 2:
// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"

// Example 3:
// Input: expression = "1/3-1/2"
// Output: "-1/6"

// Constraints:
//     The input string only contains '0' to '9', '/', '+' and '-'. So does the
//     output. Each fraction (input and output) has the format
//     ±numerator/denominator. If the first input fraction or the output is
//     positive, then '+' will be omitted. The input only contains valid
//     irreducible fractions, where the numerator and denominator of each
//     fraction will always be in the range [1, 10]. If the denominator is 1, it
//     means this fraction is actually an integer in a fraction format defined
//     above. The number of given fractions will be in the range [1, 10]. The
//     numerator and denominator of the final result are guaranteed to be valid
//     and in the range of 32-bit int.

#include <algorithm>
#include <fmt/ranges.h>
#include <format>
#include <numeric>
#include <vector>

class Fraction {
  public:
    int num, den;

    Fraction() : num(0), den(1) {}
    Fraction(int num, int den) : num(num), den(den) {}
    Fraction(std::string &str) {
        int slash = (int)str.find('/');
        this->num = std::stoi(str.substr(0, slash));
        this->den = std::stoi(str.substr(slash + 1));
    }

    Fraction operator+(Fraction &other) {
        int lcm = (this->den * other.den) / std::gcd(this->den, other.den);
        int sum = (this->num * lcm / this->den) + (other.num * lcm / other.den);
        int num = sum / std::gcd(sum, lcm);
        lcm /= std::gcd(sum, lcm);
        return {num, lcm};
    }

    std::string to_string() { return std::format("{}/{}", num, den); }
};

class Solution {
  public:
    std::string fractionAddition(std::string expression) {
        std::vector<Fraction> fracs;
        int                   i = 0;
        while (i < (int)expression.size()) {
            int j =
                (int)std::min(expression.find('-', i), expression.find('+', i));
            if (j == i) {
                j = (int)std::min(expression.find('-', i + 1),
                                  expression.find('+', i + 1));
            }

            std::string substr;
            if (j == std::string::npos) {
                substr = expression.substr(i);
            } else {
                substr = expression.substr(i, j - i);
            }
            fracs.emplace_back(substr);

            i = (j == std::string::npos) ? INT_MAX : j;
        }

        return std::accumulate(fracs.begin(), fracs.end(), Fraction())
            .to_string();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"-1/2+1/2", "0/1"},
        {"-1/2+1/2+1/3", "1/3"},
        {"1/3-1/2", "-1/6"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.fractionAddition(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
