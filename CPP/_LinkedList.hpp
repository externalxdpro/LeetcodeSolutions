#include <iostream>
#include <vector>

struct ListNode {
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode *toLinkedList(const std::vector<int> &arr) {
    ListNode *root = nullptr, *ptr = nullptr;

    for (int i : arr) {
        auto *newNode = new ListNode(i);
        if (root == nullptr) {
            root = newNode;
        } else {
            if (ptr == nullptr) {
                ptr = root;
            }
            ptr->next = newNode;
            ptr       = ptr->next;
        }
    }
    return root;
}

inline std::vector<int> toVector(ListNode *root) {
    std::vector<int> result;

    while (root != nullptr) {
        result.push_back(root->val);
        root = root->next;
    }

    return result;
}

inline void printLinkedList(ListNode *root) {
    while (root != nullptr) {
        std::cout << root->val << " -> ";
        root = root->next;
    }
    std::cout << "nullptr" << std::endl;
}
