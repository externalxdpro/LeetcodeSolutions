// 98. Validate Binary Search Tree
// Difficulty: Medium

// Given the root of a binary tree, determine if it is a valid binary search
// tree (BST).

// A valid BST is defined as follows:
//     The left subtree of a node contains only nodes with keys less than the
//     node's key. The right subtree of a node contains only nodes with keys
//     greater than the node's key. Both the left and right subtrees must also
//     be binary search trees.

// Example 1:
// Input: root = [2,1,3]
// Output: true

// Example 2:
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

// Constraints:
//     The number of nodes in the tree is in the range [1, 10^4].
//     -2^31 <= Node.val <= 2^31 - 1

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>

class Solution {
  public:
    bool isValidBST(TreeNode *root, long l = (long)INT_MIN - 1,
                    long h = (long)INT_MAX + 1) {
        return root == nullptr || (root->val > l && root->val < h &&
                                   isValidBST(root->left, l, root->val) &&
                                   isValidBST(root->right, root->val, h));
    }
};

int main(int argc, char *argv[]) {}
