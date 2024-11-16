// 3254. Find the Power of K-Size Subarrays I
// Difficulty: Medium

// You are given an array of integers nums of length n and a positive integer k.

// The power of an array is defined as:

//     Its maximum element if all of its elements are consecutive and sorted in
//     ascending order. -1 otherwise.

// You need to find the power of all
// subarrays
// of nums of size k.

// Return an integer array results of size n - k + 1, where results[i] is the
// power of nums[i..(i + k - 1)].

// Example 1:

// Input: nums = [1,2,3,4,3,2,5], k = 3

// Output: [3,4,-1,-1,-1]

// Explanation:

// There are 5 subarrays of nums of size 3:

//     [1, 2, 3] with the maximum element 3.
//     [2, 3, 4] with the maximum element 4.
//     [3, 4, 3] whose elements are not consecutive.
//     [4, 3, 2] whose elements are not sorted.
//     [3, 2, 5] whose elements are not consecutive.

// Example 2:

// Input: nums = [2,2,2,2,2], k = 4

// Output: [-1,-1]

// Example 3:

// Input: nums = [3,2,3,2,3,2], k = 2

// Output: [-1,3,-1,3,-1]

// Constraints:

//     1 <= n == nums.length <= 500
//     1 <= nums[i] <= 105
//     1 <= k <= n

#include <algorithm>
#include <deque>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> resultsArray(std::vector<int> &nums, int k) {
        std::vector<int> result(nums.size() - k + 1, -1);
        std::deque<int>  curr;
        for (int i = 0; i < nums.size(); i++) {
            if (!curr.empty() && curr.front() < i - k + 1) {
                curr.pop_front();
            }
            if (!curr.empty() && nums[i] != nums[i - 1] + 1) {
                curr.clear();
            }
            curr.push_back(i);
            if (i >= k - 1) {
                if (curr.size() == k) {
                    result[i - k + 1] = nums[curr.back()];
                } else {
                    result[i - k + 1] = -1;
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>
        tests = {
            {{{1, 2, 3, 4, 3, 2, 5}, 3}, {3, 4, -1, -1, -1}},
            {{{2, 2, 2, 2, 2}, 4}, {-1, -1}},
            {{{3, 2, 3, 2, 3, 2}, 2}, {-1, 3, -1, 3, -1}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.resultsArray(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
