// 171. Excel Sheet Column Number
// Difficulty: Easy

// Given a string columnTitle that represents the column title as appears in an
// Excel sheet, return its corresponding column number.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28
// ...

// Example 1:

// Input: columnTitle = "A"
// Output: 1
// Example 2:

// Input: columnTitle = "AB"
// Output: 28
// Example 3:

// Input: columnTitle = "ZY"
// Output: 701

// Constraints:

// 1 <= columnTitle.length <= 7
// columnTitle consists only of uppercase English letters.
// columnTitle is in the range ["A", "FXSHRXW"].

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int titleToNumber(std::string &columnTitle) {
        int result = 0;
        long long factor = 1;
        for (auto c = columnTitle.rbegin(); c != columnTitle.rend(); c++) {
            result += factor * (*c - 'A' + 1);
            factor *= 26;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"A", 1}, {"AB", 28}, {"ZY", 701}, {"AZ", 52}, {"FXSHRXW", 2147483647},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.titleToNumber(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
