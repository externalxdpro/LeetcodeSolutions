// [83] Remove Duplicates from Sorted List
// Easy

// Given the head of a sorted linked list, delete all duplicates such that each
// element appears only once. Return the linked list sorted as well.

// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

// Constraints:
//     The number of nodes in the list is in the range [0, 300].
//     -100 <= Node.val <= 100
//     The list is guaranteed to be sorted in ascending order.

#include "_LinkedList.hpp"

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *a = head, *b = head;

        while (a != nullptr) {
            while (b != nullptr && a->val == b->val) {
                b = b->next;
            }

            a->next = b;
            a       = a->next;
        }

        return head;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1, 1, 2}, {1, 2}},
        {{1, 1, 2, 3, 3}, {1, 2, 3}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(solution.deleteDuplicates(toLinkedList(test)));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
