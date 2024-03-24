// [143] Reorder List
// Difficulty: Medium

// You are given the head of a singly linked-list. The list can be represented
// as:
// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may
// be changed.

// Example 1:
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

// Constraints:
//     The number of nodes in the list is in the range [1, 5 * 10^4].
//     1 <= Node.val <= 1000

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    void reorderList(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *prev = nullptr, *curr = slow->next;
        slow->next = nullptr;
        while (curr != nullptr) {
            auto temp  = curr->next;
            curr->next = prev;
            prev       = curr;
            curr       = temp;
        }

        ListNode *l1 = head, *l2 = prev;
        while (l2 != nullptr) {
            ListNode *l1next = l1->next, *l2next = l2->next;

            l1->next = l2;
            l2->next = l1next;

            l1 = l1next;
            l2 = l2next;
        }
    }
};

int main(int argc, char *argv[]) { return 0; }
