// 215. Kth Largest Element in an Array
// Difficulty: Medium

// Given an integer array nums and an integer k, return the kth largest element
// in the array.

// Note that it is the kth largest element in the sorted order, not the kth
// distinct element.

// Can you solve it without sorting?

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

// Constraints:

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::less<>> pq(nums.begin(),
                                                                   nums.end());
        for (int i = 1; i < k; i++) {
            pq.pop();
        }
        return pq.top();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{3, 2, 1, 5, 6, 4}, 2}, 5},
        {{{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4}, 4},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.findKthLargest(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
