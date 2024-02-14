#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode *createLinkedList(const std::vector<int> &arr) {
    ListNode *root = nullptr;

    for (int i = 0; i < arr.size(); i++) {
        ListNode *newNode = new ListNode(arr[i]);
        ListNode *ptr;
        if (root == nullptr) {
            root = newNode;
        } else {
            ptr = root;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    return root;
}

inline void printLinkedList(ListNode *root) {
    while (root != nullptr) {
        std::cout << root->val << " -> ";
        root = root->next;
    }
    std::cout << "nullptr" << std::endl;
}
