// 3217. Delete Nodes From Linked List Present in Array
// Difficulty: Medium

// You are given an array of integers nums and the head of a linked list. Return
// the head of the modified linked list after removing all nodes from the linked
// list that have a value that exists in nums.

// Example 1:
// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]
// Explanation:
// Remove the nodes with values 1, 2, and 3.

// Example 2:
// Input: nums = [1], head = [1,2,1,2,1,2]
// Output: [2,2,2]
// Explanation:
// Remove the nodes with value 1.

// Example 3:
// Input: nums = [5], head = [1,2,3,4]
// Output: [1,2,3,4]
// Explanation:
// No node has value 5.

// Constraints:
//     1 <= nums.length <= 10^5
//     1 <= nums[i] <= 10^5
//     All elements in nums are unique.
//     The number of nodes in the given list is in the range [1, 10^5].
//     1 <= Node.val <= 10^5
//     The input is generated such that there is at least one node in the linked
//     list that has a value not present in nums.

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    ListNode *modifiedList(std::vector<int> &nums, ListNode *head) {
        std::unordered_set<int> exclude(nums.begin(), nums.end());
        while (head != nullptr && exclude.contains(head->val)) {
            head = head->next;
        }
        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (exclude.contains(curr->next->val)) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, std::vector<int>>,
                          std::vector<int>>>
        tests = {
            {{{1, 2, 3}, {1, 2, 3, 4, 5}}, {4, 5}},
            {{{1}, {1, 2, 1, 2, 1, 2}}, {2, 2, 2}},
            {{{5}, {1, 2, 3, 4, 5}}, {1, 2, 3, 4}},
            {{{1, 7, 6, 2, 4}, {3, 7, 1, 8, 1}}, {3, 8}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(
            solution.modifiedList(test.first, toLinkedList(test.second)));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
