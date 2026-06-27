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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int len = 0;
        ListNode *curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        ListNode temp(0, head);
        ListNode *head1, *head2, *tail;
        for (int i = 1; i < len; i *= 2) {
            curr = temp.next;
            tail = &temp;
            while (curr != nullptr) {
                head1 = curr;
                head2 = split(head1, i);
                curr = split(head2, i);
                tail = merge(head1, head2, tail);
            }
        }
        return temp.next;
    }

  private:
    ListNode *split(ListNode *head, int n) {
        for (int i = 1; head != nullptr && i < n; i++) {
            head = head->next;
        }

        if (head == nullptr) {
            return nullptr;
        }
        ListNode *head2 = head->next;
        head->next = nullptr;
        return head2;
    }

    ListNode *merge(ListNode *head1, ListNode *head2, ListNode *head) {
        ListNode *tail = head;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }

        tail->next = (head1 != nullptr ? head1 : head2);
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        return tail;
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
