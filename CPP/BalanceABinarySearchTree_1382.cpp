// 1382. Balance a Binary Search Tree
// Difficulty: Medium

// Given the root of a binary search tree, return a balanced binary search tree
// with the same node values. If there is more than one answer, return any of
// them.
// A binary search tree is balanced if the depth of the two subtrees of every
// node never differs by more than 1.

// Example 1:
// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also
// correct.

// Example 2:
// Input: root = [2,1,3]
// Output: [2,1,3]

// Constraints:
//     The number of nodes in the tree is in the range [1, 10^4].
//     1 <= Node.val <= 10^5

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>
#include <vector>

class Solution {
  public:
    TreeNode *balanceBST(TreeNode *root) {
        std::vector<int> nodes;
        traverse(root, nodes);

        return construct(nodes, 0, nodes.size() - 1);
    }

  private:
    void traverse(TreeNode *node, std::vector<int> &nodes) {
        if (!node) {
            return;
        }

        traverse(node->left, nodes);
        nodes.push_back(node->val);
        traverse(node->right, nodes);
    }

    TreeNode *construct(std::vector<int> &nodes, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int       m    = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nodes[m]);
        std::cout << m << std::endl;

        root->left  = construct(nodes, l, m - 1);
        root->right = construct(nodes, m + 1, r);

        return root;
    }
};

int main(int argc, char *argv[]) { return 0; }
