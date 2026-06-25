// 147. Insertion Sort List
// Difficulty: Medium

// Given the head of a singly linked list, sort the list using insertion sort,
// and return the sorted list's head.

// The steps of the insertion sort algorithm:

// Insertion sort iterates, consuming one input element each repetition and
// growing a sorted output list. At each iteration, insertion sort removes one
// element from the input data, finds the location it belongs within the sorted
// list and inserts it there. It repeats until no input elements remain. The
// following is a graphical example of the insertion sort algorithm. The
// partially sorted list (black) initially contains only the first element in
// the list. One element (red) is removed from the input data and inserted
// in-place into the sorted list with each iteration.

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// Constraints:

// The number of nodes in the list is in the range [1, 5000].
// -5000 <= Node.val <= 5000

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

#include "_LinkedList.hpp"

class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *tempHead = new ListNode(0, head);
        ListNode *newHead = new ListNode(0);
        ListNode *prev = tempHead;
        while (prev->next != nullptr) {
            ListNode *check = newHead;
            while (check->next != nullptr &&
                   check->next->val < prev->next->val) {
                check = check->next;
            }
            ListNode *curr = prev->next;
            delNode(prev);
            addNode(check, curr);
        }
        head = newHead->next;
        delete tempHead;
        delete newHead;
        return head;
    }

  private:
    void delNode(ListNode *prev) {
        ListNode *next = prev->next->next;
        ListNode *curr = prev->next;
        prev->next = next;
        curr->next = nullptr;
    }

    void addNode(ListNode *prev, ListNode *node) {
        ListNode *next = prev->next;
        prev->next = node;
        node->next = next;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{4, 2, 1, 3}, {1, 2, 3, 4}},
        {{-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5}},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = toVector(solution.insertionSortList(toLinkedList(test)));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
