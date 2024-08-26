// 103. Binary Tree Zigzag Level Order Traversal
// Difficulty: Medium

// Given the root of a binary tree, return the zigzag level order traversal of
// its nodes' values. (i.e., from left to right, then right to left for the next
// level and alternate between).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []

// Constraints:
//     The number of nodes in the tree is in the range [0, 2000].
//     -100 <= Node.val <= 100

#include "_BinaryTree.hpp"

#include <deque>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> result;
        std::deque<TreeNode *>        q{root};
        bool                          right = false;
        while (!q.empty()) {
            result.emplace_back();
            int n = q.size();
            while (n--) {
                if (right) {
                    result.back().push_back(q.back()->val);
                    if (q.back()->right != nullptr) {
                        q.push_front(q.back()->right);
                    }
                    if (q.back()->left != nullptr) {
                        q.push_front(q.back()->left);
                    }
                    q.pop_back();
                } else {
                    result.back().push_back(q.front()->val);
                    if (q.front()->left != nullptr) {
                        q.push_back(q.front()->left);
                    }
                    if (q.front()->right != nullptr) {
                        q.push_back(q.front()->right);
                    }
                    q.pop_front();
                }
            }
            right = !right;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {}
