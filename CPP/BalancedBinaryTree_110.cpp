// 110. Balanced Binary Tree
// Difficulty: Easy

// Given a binary tree, determine if it is height-balanced.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true

// Constraints:
//     The number of nodes in the tree is in the range [0, 5000].
//     -10^4 <= Node.val <= 10^4

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>

class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        if (std::abs(depth(root->left) - depth(root->right)) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

  private:
    int depth(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(depth(node->left), depth(node->right));
    }
};

int main(int argc, char *argv[]) {}
