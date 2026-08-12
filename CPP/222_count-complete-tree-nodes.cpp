#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// code_start

class Solution {
  public:
    int countNodes(TreeNode *root) {
        int h = height(root);
        if (h < 0) {
            return 0;
        }
        if (height(root->right) == h - 1) {
            return (1 << h) + countNodes(root->right);
        } else {
            return (1 << (h - 1)) + countNodes(root->left);
        }
    }

  private:
    int height(TreeNode *root) {
        if (root == nullptr) {
            return -1;
        }
        return 1 + height(root->left);
    }
};

// code_end
