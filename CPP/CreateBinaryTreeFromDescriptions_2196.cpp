// 2196. Create Binary Tree From Descriptions
// Difficulty: Medium

// You are given a 2D integer array descriptions where descriptions[i] =
// [parenti, childi, isLefti] indicates that parenti is the parent of childi in
// a binary tree of unique values. Furthermore,
//     If isLefti == 1, then childi is the left child of parenti.
//     If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.
// The test cases will be generated such that the binary tree is valid.

// Example 1:
// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.

// Example 2:
// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.

// Constraints:
//     1 <= descriptions.length <= 10^4
//     descriptions[i].length == 3
//     1 <= parenti, childi <= 10^5
//     0 <= isLefti <= 1
//     The binary tree described by descriptions is valid.

#include "_BinaryTree.hpp"

#include <fmt/ranges.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions) {
        std::unordered_map<int, TreeNode *> nodes;
        std::unordered_set<int>             children;

        for (std::vector<int> &d : descriptions) {
            int p = d[0], c = d[1], l = d[2];

            children.insert(c);

            if (!nodes[p]) {
                nodes[p] = new TreeNode(p);
            }
            if (!nodes[c]) {
                nodes[c] = new TreeNode(c);
            }

            if (l) {
                nodes[p]->left = nodes[c];
            } else {
                nodes[p]->right = nodes[c];
            }
        }

        for (int i : children) {
            nodes.erase(i);
        }

        return nodes.begin()->second;
    }
};

int main(int argc, char *argv[]) { return 0; }
