// 148. Sort List
// Difficulty: Medium

// Given the head of a linked list, return the list after sorting it in
// ascending order.

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
// (i.e. constant space)?

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

#include "_LinkedList.hpp"

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->next == nullptr) {
            return head;
        }

        ListNode *head1 = head, *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        head1 = sortList(head1);
        head2 = sortList(head2);
        ListNode *merged = merge(head1, head2);
        return merged;
    }

  private:
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *tempHead = new ListNode(0);
        ListNode *tail = tempHead;

        while (head1 != nullptr || head2 != nullptr) {
            if (head2 == nullptr ||
                (head1 != nullptr && head1->val < head2->val)) {
                tail->next = head1;
                head1 = head1->next;
                tail->next->next = nullptr;
            } else {
                tail->next = head2;
                head2 = head2->next;
                tail->next->next = nullptr;
            }
            tail = tail->next;
        }

        ListNode *head = tempHead->next;
        delete tempHead;
        return head;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{4, 2, 1, 3}, {1, 2, 3, 4}},
        {{-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5}},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = toVector(solution.sortList(toLinkedList(test)));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
