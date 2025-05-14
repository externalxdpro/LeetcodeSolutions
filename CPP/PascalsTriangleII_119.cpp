// 119. Pascal's Triangle II
// Difficulty: Easy

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the
// Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:

// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]

// Example 2:

// Input: rowIndex = 0
// Output: [1]

// Example 3:

// Input: rowIndex = 1
// Output: [1,1]

// Constraints:

//     0 <= rowIndex <= 33

// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
// space?

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> result(rowIndex + 1);
        result[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            result[i] = (long long)result[i - 1] * (rowIndex - i + 1) / i;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::vector<int>>> tests = {
        {3, {1, 3, 3, 1}},
        {0, {1}},
        {1, {1, 1}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.getRow(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
