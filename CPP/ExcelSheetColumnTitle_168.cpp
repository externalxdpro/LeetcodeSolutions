// 168. Excel Sheet Column Title
// Difficulty: Easy

// Given an integer columnNumber, return its corresponding column title as it
// appears in an Excel sheet.

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

// Input: columnNumber = 1
// Output: "A"
// Example 2:

// Input: columnNumber = 28
// Output: "AB"
// Example 3:

// Input: columnNumber = 701
// Output: "ZY"

// Constraints:

// 1 <= columnNumber <= 231 - 1

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string convertToTitle(int columnNumber) {
        std::string result;
        while (columnNumber) {
            columnNumber--;
            result += 'A' + columnNumber % 26;
            columnNumber /= 26;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::string>> tests = {
        {1, "A"},
        {28, "AB"},
        {701, "ZY"},
        {52, "AZ"},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.convertToTitle(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
