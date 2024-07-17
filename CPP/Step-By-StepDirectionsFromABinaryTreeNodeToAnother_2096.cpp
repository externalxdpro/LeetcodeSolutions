// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// Difficulty: Medium

// You are given the root of a binary tree with n nodes. Each node is uniquely
// assigned a value from 1 to n. You are also given an integer startValue
// representing the value of the start node s, and a different integer destValue
// representing the value of the destination node t.
// Find the shortest path starting from node s and ending at node t. Generate
// step-by-step directions of such path as a string consisting of only the
// uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific
// direction:
//     'L' means to go from a node to its left child node.
//     'R' means to go from a node to its right child node.
//     'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node
// t.

// Example 1:
// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

// Example 2:
// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.

// Constraints:
//     The number of nodes in the tree is n.
//     2 <= n <= 10^5
//     1 <= Node.val <= n
//     All the values in the tree are unique.
//     1 <= startValue, destValue <= n
//     startValue != destValue

#include "_BinaryTree.hpp"

#include <fmt/ranges.h>

class Solution {
  public:
    std::string getDirections(TreeNode *root, int startValue, int destValue) {
        root = common(root, startValue, destValue);
        std::string result;

        dfs(root, startValue, result, 1);
        dfs(root, destValue, result);

        return result;
    }

  private:
    bool dfs(TreeNode *root, int x, std::string &path, bool rev = false) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == x) {
            return true;
        }

        path += rev ? 'U' : 'L';
        if (dfs(root->left, x, path, rev)) {
            return true;
        }
        path.pop_back();

        path += rev ? 'U' : 'R';
        if (dfs(root->right, x, path, rev)) {
            return true;
        }
        path.pop_back();

        return false;
    }

    TreeNode *common(TreeNode *root, int x, int y) {
        if (root == nullptr || root->val == x || root->val == y) {
            return root;
        }
        TreeNode *l = common(root->left, x, y), *r = common(root->right, x, y);
        if (l == nullptr) {
            return r;
        } else if (r == nullptr) {
            return l;
        }
        return root;
    }
};

int main(int argc, char *argv[]) { return 0; }
