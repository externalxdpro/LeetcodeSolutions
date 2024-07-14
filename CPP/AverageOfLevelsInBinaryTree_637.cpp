// 637. Average of Levels in Binary Tree
// Difficulty: Easy

// Given the root of a binary tree, return the average value of the nodes on
// each level in the form of an array. Answers within 10-5 of the actual answer
// will be accepted.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5,
// and on level 2 is 11. Hence return [3, 14.5, 11].

// Example 2:
// Input: root = [3,9,20,15,7]
// Output: [3.00000,14.50000,11.00000]

// Constraints:
//     The number of nodes in the tree is in the range [1, 10^4].
//     -2^31 <= Node.val <= 2^31 - 1

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<double> averageOfLevels(TreeNode *root) {
        std::vector<double>    result;
        std::queue<TreeNode *> nodes{{root}};

        while (!nodes.empty()) {
            std::vector<int> level;
            int              n = nodes.size();
            while (n--) {
                TreeNode *node = nodes.front();
                level.push_back(node->val);
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
                nodes.pop();
            }
            result.push_back(
                std::accumulate(level.begin(), level.end(), double{0}) /
                (double)level.size());
        }

        return result;
    }
};

int main(int argc, char *argv[]) { return 0; }
