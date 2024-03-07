// Difficulty: Easy
// Given the head of a singly linked list, return the middle node of the linked
// list.
// If there are two middle nodes, return the second middle node.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we
// return the second one.

// Constraints:
//     The number of nodes in the list is in the range [1, 100].
//     1 <= Node.val <= 100

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 3, 4, 5}, 3},
        {{1, 2, 3, 4, 5, 6}, 4},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        ListNode *list   = createLinkedList(test);
        auto      result = solution.middleNode(list);
        printLinkedList(list);
        printLinkedList(result);
        fmt::print("{}\n", result->val == ans ? "✅" : "❌");
    }

    return 0;
}
