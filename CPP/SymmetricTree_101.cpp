// [101] Symmetric Tree
// Easy

// Given the root of a binary tree, check whether it is a mirror of itself
// (i.e., symmetric around its center).

// Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Example 2:
// Input: root = [1,2,2,null,3,null,3]
// Output: false

// Constraints:
//     The number of nodes in the tree is in the range [1, 1000].
//     -100 <= Node.val <= 100

// Follow up: Could you solve it both recursively and iteratively?

#include "_BinaryTree.hpp"

#include <fmt/ranges.h>

// Recursive
class Solution {
  public:
    bool isSymmetric(TreeNode *root) { return recurse(root, root); }

  private:
    bool recurse(TreeNode *l, TreeNode *r) {
        if (l == nullptr && r == nullptr) {
            return true;
        }
        if (l == nullptr || r == nullptr || l->val != r->val) {
            return false;
        }
        return recurse(l->left, r->right) && recurse(l->right, r->left);
    }
};

int main(int argc, char *argv[]) {}
