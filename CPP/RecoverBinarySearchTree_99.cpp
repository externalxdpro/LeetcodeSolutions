// 99. Recover Binary Search Tree
// Difficulty: Medium

// You are given the root of a binary search tree (BST), where the values of
// exactly two nodes of the tree were swapped by mistake. Recover the tree
// without changing its structure.

// Example 1:
// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
// makes the BST valid.

// Example 2:
// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
// and 3 makes the BST valid.

// Constraints:
//     The number of nodes in the tree is in the range [2, 1000].
//     -2^31 <= Node.val <= 2^31 - 1

// Follow up: A solution using O(n) space is pretty straight-forward. Could you
// devise a constant O(1) space solution?

#include "_BinaryTree.hpp"

#include <fmt/ranges.h>
#include <iostream>
#include <vector>

class Solution {
  public:
    void recoverTree(TreeNode *root) {
        std::vector<TreeNode *> nodes;
        recurse(root, nodes);

        for (int i = nodes.size() - 1; i > 0; i--) {
            if (nodes[i]->val < nodes[i - 1]->val) {
                int j = i - 1;
                while (j >= 0 && nodes[i]->val < nodes[j]->val) {
                    j--;
                }

                std::swap(nodes[i]->val, nodes[j + 1]->val);
                break;
            }
        }
    }

  private:
    void recurse(TreeNode *node, std::vector<TreeNode *> &nodes) {
        if (node == nullptr) {
            return;
        }
        recurse(node->left, nodes);
        nodes.push_back(node);
        recurse(node->right, nodes);
    }
};

int main(int argc, char *argv[]) {}
