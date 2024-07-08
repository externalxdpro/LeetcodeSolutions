// 897. Increasing Order Search Tree
// Difficulty: Easy

// Given the root of a binary search tree, rearrange the tree in in-order so
// that the leftmost node in the tree is now the root of the tree, and every
// node has no left child and only one right child.

// Example 1:
// Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

// Example 2:
// Input: root = [5,1,7]
// Output: [1,null,5,null,7]

// Constraints:
//     The number of nodes in the given tree will be in the range [1, 100].
//     0 <= Node.val <= 1000

#include "_BinaryTree.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  public:
    TreeNode *increasingBST(TreeNode *root) {
        std::vector<TreeNode *> nodes;

        traverse(root, nodes);

        for (auto node : nodes) {
            std::cout << node->val << std::endl;
        }

        for (int i = 0; i < nodes.size() - 1; i++) {
            TreeNode *node = nodes[i];
            node->left     = nullptr;
            node->right    = nodes[i + 1];
        }
        nodes.back()->left  = nullptr;
        nodes.back()->right = nullptr;

        return nodes.front();
    }

  private:
    void traverse(TreeNode *node, std::vector<TreeNode *> &nodes) {
        if (node == nullptr) {
            return;
        }

        traverse(node->left, nodes);
        nodes.push_back(node);
        traverse(node->right, nodes);
    }
};

int main(int argc, char *argv[]) {}
