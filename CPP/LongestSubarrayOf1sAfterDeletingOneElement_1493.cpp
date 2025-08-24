// 1493. Longest Subarray of 1's After Deleting One Element
// Difficulty: Medium

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the
// resulting array. Return 0 if there is no such subarray.

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3
// numbers with value of 1's.

// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
// longest subarray with value of 1's is [1,1,1,1,1].

// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    struct element {
        bool isOne;
        int val;
    };

  public:
    int longestSubarray(std::vector<int> &nums) {
        std::vector<element> sections;
        int ones = 0, others = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (others != 0) {
                    sections.emplace_back(false, others);
                    others = 0;
                }
                ones++;
            } else {
                if (ones != 0) {
                    sections.emplace_back(true, ones);
                    ones = 0;
                }
                others++;
            }
        }
        if (ones != 0) {
            sections.emplace_back(true, ones);
        }
        if (others != 0) {
            sections.emplace_back(false, others);
        }
        if (sections.size() == 1 && sections[0].isOne) {
            return sections[0].val - 1;
        }

        int max = 0;
        for (int i = 1; i < sections.size() - 1; i++) {
            if (!sections[i].isOne && sections[i].val == 1) {
                max = std::max(max, sections[i - 1].val + sections[i + 1].val);
            }
        }
        for (auto &[isOne, val] : sections) {
            if (isOne) {
                max = std::max(max, val);
            }
        }
        return max;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 1, 0, 1}, 3},
        {{0, 1, 1, 1, 0, 1, 1, 0, 1}, 5},
        {{1, 1, 1}, 2},
        {{1, 0, 0, 0, 0}, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.longestSubarray(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
