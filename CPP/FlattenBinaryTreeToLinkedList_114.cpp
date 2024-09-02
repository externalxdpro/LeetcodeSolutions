// 114. Flatten Binary Tree to Linked List
// Difficulty: Medium

// Given the root of a binary tree, flatten the tree into a "linked list":
//     The "linked list" should use the same TreeNode class where the right
//     child pointer points to the next node in the list and the left child
//     pointer is always null. The "linked list" should be in the same order as
//     a pre-order traversal of the binary tree.

// Example 1:
// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [0]
// Output: [0]

// Constraints:
//     The number of nodes in the tree is in the range [0, 2000].
//     -100 <= Node.val <= 100

// Follow up: Can you flatten the tree in-place (with O(1) extra space)?

#include "_BinaryTree.hpp"

#include <stack>

class Solution {
  public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        std::stack<TreeNode *> stack;
        if (root->left != nullptr) {
            if (root->right != nullptr) {
                stack.push(root->right);
            }
            root->right = root->left;
            root->left  = nullptr;
        }
        flatten(root->right);
        TreeNode *curr = root;
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        while (!stack.empty()) {
            curr->right = stack.top();
            flatten(stack.top());
            stack.pop();
        }
    }
};

int main(int argc, char *argv[]) {}
