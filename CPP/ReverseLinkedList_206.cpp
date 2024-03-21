// [206] Reverse Linked List
// Difficulty: Easy

// Given the head of a singly linked list, reverse the list, and return the
// reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

// Constraints:
//     The number of nodes in the list is the range [0, 5000].
//     -5000 <= Node.val <= 5000

// Follow up: A linked list can be reversed either iteratively or recursively.
// Could you implement both?

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

// Iterative
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *next = nullptr, *prev = nullptr;

        while (head != nullptr) {
            next       = head->next;
            head->next = prev;
            prev       = head;
            head       = next;
        }
        return prev;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
        {{1, 2}, {2, 1}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(solution.reverseList(toLinkedList(test)));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
