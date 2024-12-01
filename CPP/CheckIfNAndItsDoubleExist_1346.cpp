// 1346. Check If N and Its Double Exist
// Difficulty: Easy

// Given an array arr of integers, check if there exist two indices i and j such
// that :

//     i != j
//     0 <= i, j < arr.length
//     arr[i] == 2 * arr[j]

// Example 1:

// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

// Example 2:

// Input: arr = [3,1,7,11]
// Output: false
// Explanation: There is no i and j that satisfy the conditions.

// Constraints:

//     2 <= arr.length <= 500
//     -103 <= arr[i] <= 103

#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool checkIfExist(const std::vector<int> &arr) {
        std::unordered_set<int> seen;
        for (const int i : arr) {
            if ((i % 2 == 0 && seen.contains(i / 2)) || seen.contains(2 * i)) {
                return true;
            }
            seen.insert(i);
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, bool>> tests = {
        {{10, 2, 5, 3}, true},
        {{3, 1, 7, 11}, false},
        {{-2, 0, 10, -19, 4, 6, -8}, false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.checkIfExist(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
