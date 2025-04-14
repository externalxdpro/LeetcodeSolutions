// 1534. Count Good Triplets
// Difficulty: Easy

// Given an array of integers arr, and three integers a, b and c. You need to
// find the number of good triplets.

// A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are
// true:

//     0 <= i < j < k < arr.length
//     |arr[i] - arr[j]| <= a
//     |arr[j] - arr[k]| <= b
//     |arr[i] - arr[k]| <= c

// Where |x| denotes the absolute value of x.

// Return the number of good triplets.

// Example 1:

// Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
// Output: 4
// Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].

// Example 2:

// Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
// Output: 0
// Explanation: No triplet satisfies all conditions.

// Constraints:

//     3 <= arr.length <= 100
//     0 <= arr[i] <= 1000
//     0 <= a, b, c <= 1000

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int countGoodTriplets(std::vector<int> &arr, int a, int b, int c) {
        int result = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                for (int k = j + 1; k < arr.size(); k++) {
                    if (std::abs(arr[i] - arr[j]) <= a &&
                        std::abs(arr[j] - arr[k]) <= b &&
                        std::abs(arr[i] - arr[k]) <= c) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int, int>, int>>
        tests = {
            {{{3, 0, 1, 1, 9, 7}, 7, 2, 3}, 4},
            {{{1, 1, 2, 2, 3}, 0, 0, 1}, 0},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.countGoodTriplets(std::get<0>(test), std::get<1>(test),
                                       std::get<2>(test), std::get<3>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
