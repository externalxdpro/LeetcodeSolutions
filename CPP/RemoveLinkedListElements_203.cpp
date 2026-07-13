// 203. Remove Linked List Elements
// Difficulty: Easy

// Given the head of a linked list and an integer val, remove all the nodes of
// the linked list that has Node.val == val, and return the new head.

// Example 1:

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:

// Input: head = [], val = 1
// Output: []
// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []

// Constraints:

// The number of nodes in the list is in the range [0, 104].
// 1 <= Node.val <= 50
// 0 <= val <= 50

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

#include "_LinkedList.hpp"

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode temp(-1, head);
        for (ListNode *ptr = &temp; ptr != nullptr; ptr = ptr->next) {
            while (ptr->next != nullptr && ptr->next->val == val) {
                delNode(ptr);
            }
        }
        return temp.next;
    }

  private:
    void delNode(ListNode *prev) {
        ListNode *curr = prev->next;
        ListNode *next = curr->next;
        curr->next = nullptr;
        prev->next = next;
        delete curr;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>
        tests = {
            {{{1, 2, 6, 3, 4, 5, 6}, 6}, {1, 2, 3, 4, 5}},
            {{{}, 1}, {}},
            {{{7, 7, 7, 7}, 7}, {}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = toVector(
            solution.removeElements(toLinkedList(test.first), test.second));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
