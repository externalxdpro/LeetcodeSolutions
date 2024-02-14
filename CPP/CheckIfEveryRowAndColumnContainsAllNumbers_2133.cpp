// Difficulty: Easy

// An n x n matrix is valid if every row and every column contains all the
// integers from 1 to n (inclusive). Given an n x n integer matrix matrix,
// return true if the matrix is valid. Otherwise, return false.

// Example 1:
// Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
// Output: true
// Explanation: In this case, n = 3, and every row and column contains the
// numbers 1, 2, and 3. Hence, we return true.

// Example 2:
// Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
// Output: false
// Explanation: In this case, n = 3, but the first row and the first column do
// not contain the numbers 2 or 3. Hence, we return false.

// Constraints:
//     n == matrix.length == matrix[i].length
//     1 <= n <= 100
//     1 <= matrix[i][j] <= n

#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

bool checkValid(std::vector<std::vector<int>> &matrix) {
    // rows
    for (auto i : matrix) {
        std::unordered_set<int> set(i.begin(), i.end());
        if (i.size() != set.size())
            return false;
    }

    // columns
    for (int j = 0; j < matrix[0].size(); j++) {
        std::unordered_set<int> set;
        for (int i = 0; i < matrix.size(); i++) {
            set.insert(matrix[i][j]);
        }
        if (matrix[0].size() != set.size())
            return false;
    }

    return true;
}

int main() {
    std::vector<std::vector<std::vector<int>>> tests = {
        {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}},
        {{1, 1, 1}, {1, 2, 3}, {1, 2, 3}},
    };

    for (auto test : tests) {
        std::cout << checkValid(test) << std::endl;
    }

    return 0;
}
