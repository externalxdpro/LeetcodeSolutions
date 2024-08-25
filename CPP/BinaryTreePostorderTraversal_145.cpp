// 145. Binary Tree Postorder Traversal
// Difficulty: Easy

// Given the root of a binary tree, return the postorder traversal of its nodes'
// values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [3,2,1]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]

// Constraints:
//     The number of the nodes in the tree is in the range [0, 100].
//     -100 <= Node.val <= 100

// Follow up: Recursive solution is trivial, could you do it iteratively?

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> result;

        while (root) {
            if (!root->right) {
                result.push_back(root->val);
                root = root->left;
            } else {
                TreeNode *next = root->right;
                while (next->left != nullptr && next->left != root) {
                    next = next->left;
                }
                if (next->left == nullptr) {
                    result.push_back(root->val);
                    next->left = root;
                    root       = root->right;
                } else {
                    next->left = nullptr;
                    root       = root->left;
                }
            }
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char *argv[]) {}
