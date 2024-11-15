// 1574. Shortest Subarray to be Removed to Make Array Sorted
// Difficulty: Medium

// Given an integer array arr, remove a subarray (can be empty) from arr such
// that the remaining elements in arr are non-decreasing.

// Return the length of the shortest subarray to remove.

// A subarray is a contiguous subsequence of the array.

// Example 1:

// Input: arr = [1,2,3,10,4,2,3,5]
// Output: 3
// Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The
// remaining elements after that will be [1,2,3,3,5] which are sorted. Another
// correct solution is to remove the subarray [3,10,4].

// Example 2:

// Input: arr = [5,4,3,2,1]
// Output: 4
// Explanation: Since the array is strictly decreasing, we can only keep a
// single element. Therefore we need to remove a subarray of length 4, either
// [5,4,3,2] or [4,3,2,1].

// Example 3:

// Input: arr = [1,2,3]
// Output: 0
// Explanation: The array is already non-decreasing. We do not need to remove
// any elements.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int findLengthOfShortestSubarray(const std::vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (r > 0 && arr[r] >= arr[r - 1]) {
            r--;
        }

        int min = r;
        while (l < r && (l == 0 || arr[l - 1] <= arr[l])) {
            while (r < arr.size() && arr[l] > arr[r]) {
                r++;
            }
            min = std::min(min, r - l - 1);
            l++;
        }
        return min;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 3, 10, 4, 2, 3, 5}, 3},
        {{5, 4, 3, 2, 1}, 4},
        {{1, 2, 3}, 0},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findLengthOfShortestSubarray(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
