// 538. Convert BST to Greater Tree
// Difficulty: Medium

// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree
// such that every key of the original BST is changed to the original key plus
// the sum of all keys greater than the original key in BST.
// As a reminder, a binary search tree is a tree that satisfies these
// constraints:
//     The left subtree of a node contains only nodes with keys less than the
//     node's key. The right subtree of a node contains only nodes with keys
//     greater than the node's key. Both the left and right subtrees must also
//     be binary search trees.

// Example 1:
// Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

// Example 2:
// Input: root = [0,null,1]
// Output: [1,null,1]

// Constraints:
//     The number of nodes in the tree is in the range [0, 10^4].
//     -10^4 <= Node.val <= 10^4
//     All the values in the tree are unique.
//     root is guaranteed to be a valid binary search tree.

// Note: This question is the same as 1038:
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    TreeNode *convertBST(TreeNode *root) {
        std::vector<TreeNode *> nodes;
        traverse(root, nodes);

        for (int i = 1; i < nodes.size(); i++) {
            nodes[i]->val += nodes[i - 1]->val;
        }

        return root;
    }

  private:
    void traverse(TreeNode *node, std::vector<TreeNode *> &nodes) {
        if (node == nullptr) {
            return;
        }
        traverse(node->right, nodes);
        nodes.push_back(node);
        traverse(node->left, nodes);
    }
};

int main(int argc, char *argv[]) { return 0; }
