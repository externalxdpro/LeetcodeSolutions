// 118. Pascal's Triangle
// Difficulty: Easy

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:

// Input: numRows = 1
// Output: [[1]]

// Constraints:

//     1 <= numRows <= 30

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle(numRows, std::vector(1, 1));
        for (int row = 1; row < numRows; row++) {
            for (int i = 0; i < triangle[row - 1].size() - 1; i++) {
                triangle[row].push_back(triangle[row - 1][i] +
                                        triangle[row - 1][i + 1]);
            }
            triangle[row].push_back(1);
        }
        return triangle;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::vector<std::vector<int>>>> tests = {
        {5, {{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}}},
        {1, {{1}}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.generate(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
