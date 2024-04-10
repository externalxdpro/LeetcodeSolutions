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
#include <queue>

// Iterative
class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        TreeNode              *l = root, *r = root;
        std::queue<TreeNode *> lq, rq;
        lq.push(l);
        rq.push(r);

        while (!lq.empty()) {
            l = lq.front(), r = rq.front();
            lq.pop();
            rq.pop();

            if (l == nullptr && r == nullptr) {
                continue;
            }
            if (l == nullptr || r == nullptr || l->val != r->val) {
                return false;
            }
            lq.push(l->left);
            rq.push(r->right);
            lq.push(l->right);
            rq.push(r->left);
        }

        return true;
    }
};

int main(int argc, char *argv[]) {}
