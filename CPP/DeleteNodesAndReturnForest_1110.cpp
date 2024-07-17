// 1110. Delete Nodes And Return Forest
// Difficulty: Medium

// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest
// (a disjoint union of trees).
// Return the roots of the trees in the remaining forest. You may return the
// result in any order.

// Example 1:
// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]

// Example 2:
// Input: root = [1,2,4,null,3], to_delete = [3]
// Output: [[1,2,4]]

// Constraints:
//     The number of nodes in the given tree is at most 1000.
//     Each node has a distinct value between 1 and 1000.
//     to_delete.length <= 1000
//     to_delete contains distinct values between 1 and 1000.

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>
#include <set>
#include <vector>

class Solution {
  public:
    std::vector<TreeNode *> delNodes(TreeNode         *root,
                                     std::vector<int> &to_delete) {
        bool                    toDelete[1001];
        std::vector<TreeNode *> result;
        for (int i : to_delete) {
            toDelete[i] = true;
        }
        dfs(root, nullptr, true, toDelete, result);
        return result;
    }

  private:
    void dfs(TreeNode *node, TreeNode *parent, bool isLeft, bool toDelete[],
             std::vector<TreeNode *> &result) {
        if (node == nullptr) {
            return;
        }

        if (toDelete[node->val]) {
            if (parent) {
                if (isLeft) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
            dfs(node->left, nullptr, true, toDelete, result);
            dfs(node->right, nullptr, false, toDelete, result);
            delete node;
        } else {
            if (parent == nullptr) {
                result.push_back(node);
            }

            dfs(node->left, node, true, toDelete, result);
            dfs(node->right, node, false, toDelete, result);
        }
    }
};

int main(int argc, char *argv[]) { return 0; }
