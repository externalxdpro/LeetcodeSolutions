// Difficulty: Easy
// Given the root node of a binary search tree and two integers low and high,
// return the sum of values of all nodes with a value in the inclusive range
// [low, high].

// Example 1:
// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

// Example 2:
// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23
// Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

// Constraints:
//     The number of nodes in the tree is in the range [1, 2 * 104].
//     1 <= Node.val <= 10^5
//     1 <= low <= high <= 10^5
//     All Node.val are unique.

#include "_BinaryTree.hpp"
#include <fmt/ranges.h>
#include <stack>
#include <vector>

int rangeSumBST(TreeNode *root, int low, int high) {
    int sum = 0;
    std::stack<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        TreeNode *top = nodes.top();
        nodes.pop();

        if (top->left != nullptr) {
            nodes.push(top->left);
        }
        if (top->right != nullptr) {
            nodes.push(top->right);
        }
        if (top->val >= low && top->val <= high) {
            sum += top->val;
        }
    }

    return sum;
}

int main(int argc, char *argv[]) { return 0; }
