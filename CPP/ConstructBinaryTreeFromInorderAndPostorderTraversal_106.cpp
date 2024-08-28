// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Difficulty: Medium

// Given two integer arrays inorder and postorder where inorder is the inorder
// traversal of a binary tree and postorder is the postorder traversal of the
// same tree, construct and return the binary tree.

// Example 1:
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: inorder = [-1], postorder = [-1]
// Output: [-1]

// Constraints:
//     1 <= inorder.length <= 3000
//     postorder.length == inorder.length
//     -3000 <= inorder[i], postorder[i] <= 3000
//     inorder and postorder consist of unique values.
//     Each value of postorder also appears in inorder.
//     inorder is guaranteed to be the inorder traversal of the tree.
//     postorder is guaranteed to be the postorder traversal of the tree.

#include "_BinaryTree.hpp"

#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    TreeNode *buildTree(std::vector<int> &inorder,
                        std::vector<int> &postorder) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return construct(inorder, 0, inorder.size() - 1, postorder, 0,
                         postorder.size() - 1, map);
    }

  private:
    TreeNode *construct(std::vector<int> &inorder, int inl, int inr,
                        std::vector<int> &postorder, int postl, int postr,
                        std::unordered_map<int, int> &map) {
        if (inl > inr || postl > postr) {
            return nullptr;
        }
        TreeNode *root     = new TreeNode(postorder[postr]);
        int       ri       = map[postorder[postr]];
        int       numsLeft = ri - inl;
        root->left         = construct(inorder, inl, ri - 1, postorder, postl,
                                       postl + numsLeft - 1, map);
        root->right        = construct(inorder, ri + 1, inr, postorder,
                                       postl + numsLeft, postr - 1, map);
        return root;
    }
};

int main(int argc, char *argv[]) {}
