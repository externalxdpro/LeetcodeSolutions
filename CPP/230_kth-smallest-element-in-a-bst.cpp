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
	int result = -1;
        dfs(root, k, result);
        return result;
    }

  private:
    void dfs(TreeNode *node, int &k, int &result) {
        if (node == nullptr) {
            return;
        }

        dfs(node->left, k, result);

	k--;
        if (k == 0) {
	    result = node->val;
	    return;
        }

        dfs(node->right, k, result);
    }
};

// code_end
