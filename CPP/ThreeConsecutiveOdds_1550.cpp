// 1550. Three Consecutive Odds
// Difficulty: Easy

// Given an integer array arr, return true if there are three consecutive odd
// numbers in the array. Otherwise, return false.

// Example 1:
// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.

// Example 2:
// Input: arr = [1,2,34,3,4,5,7,23,12]
// Output: true
// Explanation: [5,7,23] are three consecutive odds.

// Constraints:
//     1 <= arr.length <= 1000
//     1 <= arr[i] <= 1000

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool threeConsecutiveOdds(std::vector<int> &arr) {
        if (arr.size() < 3) {
            return false;
        }

        for (int i = 0; i < arr.size() - 2; i++) {
            int j = i + 1, k = i + 2;
            if (arr[i] % 2 == 1 && arr[j] % 2 == 1 && arr[k] % 2 == 1) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, bool>> tests = {
        {{2, 6, 4, 1}, false},
        {{1, 2, 34, 3, 4, 5, 7, 23, 12}, true},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.threeConsecutiveOdds(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
