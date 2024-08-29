// 107. Binary Tree Level Order Traversal II
// Difficulty: Medium

// Given the root of a binary tree, return the bottom-up level order traversal
// of its nodes' values. (i.e., from left to right, level by level from leaf to
// root).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []

// Constraints:
//     The number of nodes in the tree is in the range [0, 2000].
//     -1000 <= Node.val <= 1000

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> result;
        std::queue<TreeNode *>        q{{root}};
        while (!q.empty()) {
            result.emplace_back();
            int n = q.size();
            while (n--) {
                result.back().push_back(q.front()->val);
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        std::ranges::reverse(result);
        return result;
    }
};

int main(int argc, char *argv[]) {}
