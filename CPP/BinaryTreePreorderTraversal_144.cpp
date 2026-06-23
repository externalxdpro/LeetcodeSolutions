// 144. Binary Tree Preorder Traversal
// Difficulty: Easy

// Given the root of a binary tree, return the preorder traversal of its nodes'
// values.

// Example 1:

// Input: root = [1,null,2,3]

// Output: [1,2,3]

// Explanation:

// Example 2:

// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

// Output: [1,2,4,5,6,7,3,8,9]

// Explanation:

// Example 3:

// Input: root = []

// Output: []

// Example 4:

// Input: root = [1]

// Output: [1]

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

#include "_BinaryTree.hpp"

class Solution {
  public:
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> result;
        recurse(root, result);
        return result;
    }

  private:
    void recurse(TreeNode *node, std::vector<int> &result) {
        if (node == nullptr) {
            return;
        }
        result.push_back(node->val);
        recurse(node->left, result);
        recurse(node->right, result);
    }
};

int main(int argc, char *argv[]) {}
