// 2. Add Two Numbers
// Difficulty: Medium

// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list.
// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Constraints:
//     The number of nodes in each linked list is in the range [1, 100].
//     0 <= Node.val <= 9
//     It is guaranteed that the list represents a number that does not have
//     leading zeros.

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(), *curr = head;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            curr->val += sum;
            if (curr->val >= 10) {
                curr->next = new ListNode(curr->val / 10);
                curr->val %= 10;
            } else {
                curr->next = new ListNode();
            }
            if (l1 != nullptr || l2 != nullptr) {
                curr = curr->next;
            }
        }
        if (curr->next->val == 0) {
            curr->next = nullptr;
        }

        return head;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<int>>>
        tests = {
            {{{2, 4, 3}, {5, 6, 4}}, {7, 0, 8}},
            {{{0}, {0}}, {0}},
            {{{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}}, {8, 9, 9, 9, 0, 0, 0, 1}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(solution.addTwoNumbers(toLinkedList(test[0]),
                                                      toLinkedList(test[1])));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
