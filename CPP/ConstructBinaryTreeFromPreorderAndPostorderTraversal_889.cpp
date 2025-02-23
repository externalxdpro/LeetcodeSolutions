// 889. Construct Binary Tree from Preorder and Postorder Traversal
// Difficulty: Medium

// Given two integer arrays, preorder and postorder where preorder is the
// preorder traversal of a binary tree of distinct values and postorder is the
// postorder traversal of the same tree, reconstruct and return the binary tree.

// If there exist multiple answers, you can return any of them.

// Example 1:

// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]

// Example 2:

// Input: preorder = [1], postorder = [1]
// Output: [1]

// Constraints:

//     1 <= preorder.length <= 30
//     1 <= preorder[i] <= preorder.length
//     All the values of preorder are unique.
//     postorder.length == preorder.length
//     1 <= postorder[i] <= postorder.length
//     All the values of postorder are unique.
//     It is guaranteed that preorder and postorder are the preorder traversal
//     and postorder traversal of the same binary tree.

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    TreeNode *constructFromPrePost(std::vector<int> &preorder,
                                   std::vector<int> &postorder) {
        return construct(preorder, postorder, 0, preorder.size() - 1, 0);
    }

  private:
    TreeNode *construct(std::vector<int> &preorder, std::vector<int> &postorder,
                        int preL, int preR, int postL) {
        if (preL > preR) {
            return nullptr;
        }
        if (preL == preR) {
            return new TreeNode(preorder[preL]);
        }
        int left    = preorder[preL + 1];
        int numLeft = 1;
        while (postorder[postL + numLeft - 1] != left) {
            numLeft++;
        }

        auto root = new TreeNode(preorder[preL]);
        root->left =
            construct(preorder, postorder, preL + 1, preL + numLeft, postL);
        root->right = construct(preorder, postorder, preL + numLeft + 1, preR,
                                postL + numLeft);
        return root;
    }
};

int main(int argc, char *argv[]) {}
