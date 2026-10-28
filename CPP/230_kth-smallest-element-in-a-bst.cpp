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
    int kthSmallest(TreeNode *root, int k) {
        std::stack<int> stack;
        dfs(root, stack);
        int result;
        while (k--) {
            result = stack.top();
            stack.pop();
        }
        return result;
    }

  private:
    void dfs(TreeNode *node, std::stack<int> &stack) {
        if (node == nullptr) {
            return;
        }

        dfs(node->right, stack);
        stack.push(node->val);
        dfs(node->left, stack);
    }
};

// code_end
