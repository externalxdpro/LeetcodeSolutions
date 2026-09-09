#include "_BinaryTree.hpp"
#include <bits/stdc++.h>
using namespace std;

// code_start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        invert(root);
        return root;
    }

  private:
    void invert(TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        invert(node->left);
        invert(node->right);

        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

// code_end
