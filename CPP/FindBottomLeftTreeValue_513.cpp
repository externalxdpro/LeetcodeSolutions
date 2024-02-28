// Difficulty: Medium
// Given the root of a binary tree, return the leftmost value in the last row of
// the tree.

// Example 1:
// Input: root = [2,1,3]
// Output: 1

// Example 2:
// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7

// Constraints:
//     The number of nodes in the tree is in the range [1, 104].
//     -2^31 <= Node.val <= 2^31 - 1

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <optional>
#include <vector>

class Solution {
  public:
    int findBottomLeftValue(TreeNode *root) { return dfs(root, 0).second; }

  private:
    std::pair<int, int> dfs(TreeNode *node, int height,
                            long lastVal = LONG_MAX) {
        if (node == nullptr) {
            return {height, lastVal};
        }
        return std::max(dfs(node->left, height + 1, node->val),
                        dfs(node->right, height + 1, node->val),
                        [](auto a, auto b) { return a.first < b.first; });
    }
};

int main(int argc, char *argv[]) { return 0; }
