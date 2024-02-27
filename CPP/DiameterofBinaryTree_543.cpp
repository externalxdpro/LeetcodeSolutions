// Difficulty: Easy
// Given the root of a binary tree, return the length of the diameter of the
// tree.
// The diameter of a binary tree is the length of the longest path between any
// two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges
// between them.

// Example 1:
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

// Example 2:
// Input: root = [1,2]
// Output: 1

// Constraints:
//     The number of nodes in the tree is in the range [1, 10^4].
//     -100 <= Node.val <= 100

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int dRoot = height(root->left) + height(root->right);
        int left  = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);

        return std::max({dRoot, left, right});
    }

  private:
    int height(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return std::max(height(node->left), height(node->right)) + 1;
    }
};

int main(int argc, char *argv[]) { return 0; }
