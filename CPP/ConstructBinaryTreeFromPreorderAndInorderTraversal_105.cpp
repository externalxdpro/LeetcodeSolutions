// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Difficulty: Medium

// Given two integer arrays preorder and inorder where preorder is
// the preorder traversal of a binary tree and inorder is the inorder traversal
// of the same tree, construct and return the binary tree.

// Example 1:
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

// Constraints:
//     1 <= preorder.length <= 3000
//     inorder.length == preorder.length
//     -3000 <= preorder[i], inorder[i] <= 3000
//     preorder and inorder consist of unique values.
//     Each value of inorder also appears in preorder.
//     preorder is guaranteed to be the preorder traversal of the tree.
//     inorder is guaranteed to be the inorder traversal of the tree.

#include "_BinaryTree.hpp"

#include <algorithm>
#include <deque>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        std::deque<int> q(preorder.begin(), preorder.end());
        return recurse(q, inorder.begin(), inorder.end());
    }

  private:
    TreeNode *recurse(std::deque<int> &preorder, std::vector<int>::iterator l,
                      std::vector<int>::iterator r) {
        if (preorder.empty() || l == r) {
            return nullptr;
        }

        int val = preorder.front();
        preorder.pop_front();
        int  i      = std::find(l, r, val) - l;
        auto root   = new TreeNode(val);
        root->left  = recurse(preorder, l, l + i);
        root->right = recurse(preorder, l + i + 1, r);
        return root;
    }
};

int main(int argc, char *argv[]) {}
