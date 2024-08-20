// 92. Reverse Linked List II
// Difficulty: Medium

// Given the head of a singly linked list and two integers left and right where
// left <= right, reverse the nodes of the list from position left to position
// right, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [5], left = 1, right = 1
// Output: [5]

// Constraints:
//     The number of nodes in the list is n.
//     1 <= n <= 500
//     -500 <= Node.val <= 500
//     1 <= left <= right <= n

// Follow up: Could you do it in one pass?

#include "_LinkedList.hpp"

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *l = head, *r = head;
        for (int i = 0; i < left - 2 && l->next != nullptr; i++) {
            l = l->next;
        }
        for (int i = 0; i < right - 1 && r != nullptr; i++) {
            r = r->next;
        }
        if (l != nullptr) {
            r = r->next;
            if (left == 1) {
                return reverse(l, r);
            } else {
                l->next = reverse(l->next, r);
            }
        }
        return head;
    }

  private:
    ListNode *reverse(ListNode *l, ListNode *r) {
        ListNode *next = nullptr, *prev = r;

        while (l != r) {
            next    = l->next;
            l->next = prev;
            prev    = l;
            l       = next;
        }
        return prev;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::tuple<std::vector<int>, int, int>, std::vector<int>>>
        tests = {
            {{{1, 2, 3, 4, 5}, 2, 4}, {1, 4, 3, 2, 5}},
            {{{5}, 1, 1}, {5}},
            {{{3, 5}, 1, 2}, {5, 3}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(
            solution.reverseBetween(toLinkedList(std::get<0>(test)),
                                    std::get<1>(test), std::get<2>(test)));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
