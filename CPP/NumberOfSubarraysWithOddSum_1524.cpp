// 1524. Number of Sub-arrays With Odd Sum
// Difficulty: Medium

// Given an array of integers arr, return the number of subarrays with an odd
// sum.

// Since the answer can be very large, return it modulo 109 + 7.

// Example 1:

// Input: arr = [1,3,5]
// Output: 4
// Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
// All sub-arrays sum are [1,4,9,3,8,5].
// Odd sums are [1,9,3,5] so the answer is 4.

// Example 2:

// Input: arr = [2,4,6]
// Output: 0
// Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
// All sub-arrays sum are [2,6,12,4,10,6].
// All sub-arrays have even sum and the answer is 0.

// Example 3:

// Input: arr = [1,2,3,4,5,6,7]
// Output: 16

// Constraints:

//     1 <= arr.length <= 105
//     1 <= arr[i] <= 100

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int numOfSubarrays(std::vector<int> &arr) {
        std::vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int       odd = 0, even = 1;
        long long result = 0;
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] % 2 == 0) {
                result += odd;
                even++;
            } else {
                result += even;
                odd++;
            }
            result %= (long long)(1e9 + 7);
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 3, 5}, 4},
        {{2, 4, 6}, 0},
        {{1, 2, 3, 4, 5, 6, 7}, 16},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numOfSubarrays(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
