// 2593. Find Score of an Array After Marking All Elements
// Difficulty: Medium

// You are given an array nums consisting of positive integers.

// Starting with score = 0, apply the following algorithm:

//     Choose the smallest integer of the array that is not marked. If there is
//     a tie, choose the one with the smallest index. Add the value of the
//     chosen integer to score. Mark the chosen element and its two adjacent
//     elements if they exist. Repeat until all the array elements are marked.

// Return the score you get after applying the above algorithm.

// Example 1:

// Input: nums = [2,1,3,4,5,2]
// Output: 7
// Explanation: We mark the elements as follows:
// - 1 is the smallest unmarked element, so we mark it and its two adjacent
// elements: [2,1,3,4,5,2].
// - 2 is the smallest unmarked element, so we mark it and its left adjacent
// element: [2,1,3,4,5,2].
// - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
// Our score is 1 + 2 + 4 = 7.

// Example 2:

// Input: nums = [2,3,5,1,3,2]
// Output: 5
// Explanation: We mark the elements as follows:
// - 1 is the smallest unmarked element, so we mark it and its two adjacent
// elements: [2,3,5,1,3,2].
// - 2 is the smallest unmarked element, since there are two of them, we choose
// the left-most one, so we mark the one at index 0 and its right adjacent
// element: [2,3,5,1,3,2].
// - 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
// Our score is 1 + 2 + 2 = 5.

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 106

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    long long findScore(const std::vector<int> &nums) {
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, std::greater<>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.emplace(nums[i], i);
        }

        long long               score = 0;
        std::unordered_set<int> marked;
        while (!pq.empty()) {
            auto [val, i] = pq.top();
            if (marked.contains(i)) {
                pq.pop();
                continue;
            }
            marked.insert({i, i - 1, i + 1});
            score += val;
            pq.pop();
        }

        return score;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 1, 3, 4, 5, 2}, 7},
        {{2, 3, 5, 1, 3, 2}, 5},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findScore(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
