// Difficulty: Medium
// An integer has sequential digits if and only if each digit in the number is
// one more than the previous digit.
// Return a sorted list of all the integers in the range [low, high] inclusive
// that have sequential digits.

// Example 1:
// Input: low = 100, high = 300
// Output: [123,234]

// Example 2:
// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

// Constraints:
//     10 <= low <= high <= 10^9

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        for (int len = 2; len <= 9; len++) {
            for (int firstDigit = 1; firstDigit <= 10 - len; firstDigit++) {
                std::string temp;
                for (int i = firstDigit; i < len + firstDigit; i++) {
                    temp += i + 48;
                }

                int num = std::stoi(temp);
                if (num < low) {
                    continue;
                }
                if (num > high) {
                    break;
                }

                result.push_back(num);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, std::vector<int>>> tests = {
        {{100, 300}, {123, 234}},
        {{1000, 13000}, {1234, 2345, 3456, 4567, 5678, 6789, 12345}},
        {{10, 1000000000},
         {12,      23,      34,      45,       56,       67,
          78,      89,      123,     234,      345,      456,
          567,     678,     789,     1234,     2345,     3456,
          4567,    5678,    6789,    12345,    23456,    34567,
          45678,   56789,   123456,  234567,   345678,   456789,
          1234567, 2345678, 3456789, 12345678, 23456789, 123456789}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.sequentialDigits(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
