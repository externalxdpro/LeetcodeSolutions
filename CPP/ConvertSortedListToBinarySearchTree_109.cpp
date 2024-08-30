// 109. Convert Sorted List to Binary Search Tree
// Difficulty: Medium

// Given the head of a singly linked list where elements are sorted in ascending
// order, convert it to a height-balanced binary search tree.

// Example 1:
// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the
// shown height balanced BST.

// Example 2:
// Input: head = []
// Output: []

// Constraints:
//     The number of nodes in head is in the range [0, 2 * 10^4].
//     -10^5 <= Node.val <= 10^5

#include "_BinaryTree.hpp"
#include "_LinkedList.hpp"

class Solution {
  public:
    TreeNode *sortedListToBST(ListNode *head) {
        return construct(head, nullptr);
    }

  private:
    TreeNode *construct(ListNode *l, ListNode *r) {
        if (l == r) {
            return nullptr;
        }

        ListNode *m = l, *temp = l;
        while (temp != r && temp->next != r) {
            m    = m->next;
            temp = temp->next->next;
        }

        TreeNode *root = new TreeNode(m->val);
        root->left     = construct(l, m);
        root->right    = construct(m->next, r);
        return root;
    }
};

int main(int argc, char *argv[]) {}
