// 1161. Maximum Level Sum of a Binary Tree
// Difficulty: Medium

// Given the root of a binary tree, the level of its root is 1, the level of its
// children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at
// level x is maximal.

// Example 1:

// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation:
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.

// Example 2:

// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     -105 <= Node.val <= 105

#include <fmt/ranges.h>
#include <limits>
#include <queue>

#include "_BinaryTree.hpp"

class Solution {
  public:
    int maxLevelSum(TreeNode *root) {
        std::queue<TreeNode *> q{{root}};
        int                    max    = std::numeric_limits<int>::min();
        int                    result = 0;
        for (int i = 1; !q.empty(); i++) {
            int sum = 0;
            for (size_t n = q.size(); n > 0; n--) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                sum += node->val;
            }
            if (sum > max) {
                max    = sum;
                result = i;
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {}
