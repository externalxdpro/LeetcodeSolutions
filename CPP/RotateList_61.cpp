// Difficulty: Medium
// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// Constraints:
//     The number of nodes in the list is in the range [0, 500].
//     -100 <= Node.val <= 100
//     0 <= k <= 2 * 10^9

#include "_LinkedList.hpp"
#include <iostream>

ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    int len = 0;
    ListNode *temp = head;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }

    k = k % len;
    if (k == 0) {
        return head;
    }

    temp = head;
    for (int i = 0; i < len - k - 1; i++) {
        temp = temp->next;
    }
    ListNode *end = temp;
    ListNode *newHead = temp->next;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    end->next = nullptr;
    temp->next = head;

    return newHead;
}

int main() {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 3, 4, 5}, 2},   {{0, 1, 2}, 4}, {{}, 1}, {{1}, 1},
        {{0, 1, 2}, 1'000'000}, {{1, 2}, 3}};

    for (auto [arr, k] : tests) {
        ListNode *head = createLinkedList(arr);
        head = rotateRight(head, k);
        printLinkedList(head);
    }

    return 0;
}
