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

#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<TreeNode *> delNodes(TreeNode         *root,
                                     std::vector<int> &to_delete) {
        std::unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        std::vector<TreeNode *> result;

        root = dfs(root, toDelete, result);
        if (root) {
            result.push_back(root);
        }

        return result;
    }

  private:
    TreeNode *dfs(TreeNode *node, std::unordered_set<int> &toDelete,
                  std::vector<TreeNode *> &result) {
        if (node == nullptr) {
            return nullptr;
        }
        TreeNode *l = dfs(node->left, toDelete, result);
        TreeNode *r = dfs(node->right, toDelete, result);

        node->left  = l;
        node->right = r;

        if (toDelete.contains(node->val)) {
            if (node->left) {
                result.push_back(node->left);
            }
            if (node->right) {
                result.push_back(node->right);
            }
            delete node;
            return nullptr;
        }

        return node;
    }
};

int main(int argc, char *argv[]) { return 0; }
