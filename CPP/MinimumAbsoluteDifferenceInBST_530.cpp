// 530. Minimum Absolute Difference in BST
// Difficulty: Easy

// Given the root of a Binary Search Tree (BST), return the minimum absolute
// difference between the values of any two different nodes in the tree.

// Example 1:
// Input: root = [4,2,6,1,3]
// Output: 1

// Example 2:
// Input: root = [1,0,48,null,null,12,49]
// Output: 1

// Constraints:
//     The number of nodes in the tree is in the range [2, 10^4].
//     0 <= Node.val <= 10^5

// Note: This question is the same as 783:
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <vector>

class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        std::vector<int> nodes;
        int              result = std::numeric_limits<int>::max();

        inorder(root, nodes);
        for (int i = 1; i < nodes.size(); i++) {
            result = std::min(result, nodes[i] - nodes[i - 1]);
        }
        return result;
    }

  private:
    void inorder(TreeNode *node, std::vector<int> &nodes) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, nodes);
        nodes.push_back(node->val);
        inorder(node->right, nodes);
    }
};

int main(int argc, char *argv[]) {}
