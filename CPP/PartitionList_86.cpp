// 86. Partition List
// Difficulty: Medium

// Given the head of a linked list and a value x, partition it such that all
// nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the
// two partitions.

// Example 1:
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:
// Input: head = [2,1], x = 2
// Output: [1,2]

// Constraints:
//     The number of nodes in the list is in the range [0, 200].
//     -100 <= Node.val <= 100
//     -200 <= x <= 200

#include "_LinkedList.hpp"

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *lhead = nullptr, *hhead = nullptr;
        ListNode *l = nullptr, *h = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                if (lhead == nullptr) {
                    lhead = curr;
                    l     = curr;
                } else {
                    l->next = curr;
                    l       = l->next;
                }
                curr    = curr->next;
                l->next = nullptr;
            } else {
                if (hhead == nullptr) {
                    hhead = curr;
                    h     = curr;
                } else {
                    h->next = curr;
                    h       = h->next;
                }
                curr    = curr->next;
                h->next = nullptr;
            }
        }
        if (lhead == nullptr) {
            return hhead;
        } else {
            l->next = hhead;
            return lhead;
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>
        tests = {
            {{{1, 4, 3, 2, 5, 2}, 3}, {1, 2, 2, 4, 3, 5}},
            {{{2, 1}, 2}, {1, 2}},
            {{{}, 0}, {}},
            {{{1}, 0}, {1}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            toVector(solution.partition(toLinkedList(test.first), test.second));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
