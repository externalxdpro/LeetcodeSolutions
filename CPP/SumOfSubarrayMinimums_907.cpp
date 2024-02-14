// Difficulty: Medium
// Given an array of integers arr, find the sum of min(b), where b ranges over
// every (contiguous) subarray of arr. Since the answer may be large, return the
// answer modulo 109 + 7.

// Example 1:
// Input: arr = [3,1,2,4]
// Output: 17
// Explanation:
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
// [3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17.

// Example 2:
// Input: arr = [11,81,94,43,3]
// Output: 444

// Constraints:
//     1 <= arr.length <= 3 * 10^4
//     1 <= arr[i] <= 3 * 10^4

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <stack>
#include <vector>

// Too slow
// class Solution {
//   public:
//     int sumSubarrayMins(std::vector<int> &arr) {
//         long sum = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             for (int len = 1; len <= arr.size() - i; len++) {
//                 int min = INT_MAX;
//                 for (int j = i; j < i + len; j++) {
//                     if (arr[j] < min) {
//                         min = arr[j];
//                     }
//                 }
//                 sum += min;
//             }
//         }

//         return sum % 1000000007;
//     }
// };

// Monotonic stack
class Solution {
  public:
    int sumSubarrayMins(std::vector<int> &arr) {
        const int        MOD = 1000000007;
        std::vector<int> left(arr.size(), -1);
        std::vector<int> right(arr.size(), arr.size());
        std::stack<int>  stack;

        for (int i = 0; i < arr.size(); i++) {
            while (!stack.empty() && arr[stack.top()] >= arr[i]) {
                stack.pop();
            }
            if (!stack.empty()) {
                left[i] = stack.top();
            }
            stack.push(i);
        }

        stack = std::stack<int>();

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!stack.empty() && arr[stack.top()] > arr[i]) {
                stack.pop();
            }
            if (!stack.empty()) {
                right[i] = stack.top();
            }
            stack.push(i);
        }

        long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum +=
                static_cast<long>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> tests = {
        {3, 1, 2, 4},
        {11, 81, 94, 43, 3},
    };

    Solution solution;
    for (auto &test : tests) {
        fmt::print("{}: {}\n", test, solution.sumSubarrayMins(test));
    }

    return 0;
}
