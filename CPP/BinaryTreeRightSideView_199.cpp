// 199. Binary Tree Right Side View
// Difficulty: Medium

// Given the root of a binary tree, imagine yourself standing on the right side
// of it, return the values of the nodes you can see ordered from top to bottom.

// Example 1:

// Input: root = [1,2,3,null,5,null,4]

// Output: [1,3,4]

// Explanation:

// Example 2:

// Input: root = [1,2,3,4,null,null,null,5]

// Output: [1,3,4,5]

// Explanation:

// Example 3:

// Input: root = [1,null,3]

// Output: [1,3]

// Example 4:

// Input: root = []

// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>
#include <queue>
#include <vector>

#include "_BinaryTree.hpp"

class Solution {
  public:
    std::vector<int> rightSideView(TreeNode *root) {
        std::vector<int> result;
        recurse(root, 0, result);
        return result;
    }

  private:
    void recurse(TreeNode *node, int level, std::vector<int> &result) {
        if (node == nullptr) {
            return;
        }
        if (level == result.size()) {
            result.push_back(node->val);
        }

        recurse(node->right, level + 1, result);
        recurse(node->left, level + 1, result);
    }
};

int main(int argc, char *argv[]) {}
