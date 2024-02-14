// Difficulty: Medium
// Given a linked list, swap every two adjacent nodes and return its head. You
// must solve the problem without modifying the values in the list's nodes
// (i.e., only nodes themselves may be changed.)

// Example 1:
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:
// Input: head = []
// Output: []

// Example 3:
// Input: head = [1]
// Output: [1]

// Constraints:
//     The number of nodes in the list is in the range [0, 100].
//     0 <= Node.val <= 100

#include "_LinkedList.hpp"
#include <format>
#include <iostream>

int listLen(ListNode *root) {
    int len = 0;

    while (root != nullptr) {
        len++;
        root = root->next;
    }

    return len;
}

ListNode *swapPairs(ListNode *head) {
    int len = listLen(head);

    if (len == 0 || len == 1) {
        return head;
    }

    ListNode *p1 = head;
    ListNode *p2 = head->next;
    ListNode *p3;

    p1->next = p2->next;
    p2->next = p1;
    head = p2;

    if (p1->next == nullptr)
        return head;
    p2 = p1->next;
    if (p2->next == nullptr)
        return head;
    p3 = p2->next;

    while (true) {

        p2->next = p3->next;
        p3->next = p2;
        p1->next = p3;

        p1 = p3;
        if (p2->next == nullptr)
            break;

        p3 = p2->next;

        if (p3->next == nullptr)
            break;

        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }

    return head;
}

int main() {
    std::vector<std::vector<int>> tests = {
        {1, 2, 3, 4}, {1, 2, 3, 4, 5}, {}, {1}, {1, 2},
    };

    for (auto test : tests) {
        printLinkedList(swapPairs(createLinkedList(test)));
    }

    return 0;
}
