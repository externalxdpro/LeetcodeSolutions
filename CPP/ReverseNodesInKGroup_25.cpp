#include "_LinkedList.hpp"
#include <fmt/ranges.h>
#include <vector>

ListNode *reverseKGroup(ListNode *head, int k) {
    if (head->next == nullptr || k == 1) {
        return head;
    }

    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head;
    int       len  = 0;
    while (curr != nullptr) {
        len++;
        curr = curr->next;
    }

    curr      = head;
    int index = 0;
    while (curr != nullptr) {
        if (len - index < k) {
            break;
        }

        for (int i = 2; i < k; i++) {
        }
        next       = next->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }
    return head;
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 3, 4, 5}, 2},
        {{1, 2, 3, 4, 5}, 3},
    };

    for (auto test : tests) {
        ListNode *head = createLinkedList(test.first);
        printLinkedList(reverseKGroup(head, test.second));
    }

    return 0;
}
