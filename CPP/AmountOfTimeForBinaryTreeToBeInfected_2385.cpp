// Difficulty: Medium
// You are given the root of a binary tree with unique values, and an integer
// start. At minute 0, an infection starts from the node with value start. Each
// minute, a node becomes infected if:
//     The node is currently uninfected.
//     The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

// Example 1:
// Input: root = [1,5,3,null,4,10,6,9,2], start = 3
// Output: 4
// Explanation: The following nodes are infected during:
// - Minute 0: Node 3
// - Minute 1: Nodes 1, 10 and 6
// - Minute 2: Node 5
// - Minute 3: Node 4
// - Minute 4: Nodes 9 and 2
// It takes 4 minutes for the whole tree to be infected so we return 4.

// Example 2:
// Input: root = [1], start = 1
// Output: 0
// Explanation: At minute 0, the only node in the tree is infected so we return
// 0.

// Constraints:
//     The number of nodes in the tree is in the range [1, 105].
//     1 <= Node.val <= 10^5
//     Each node has a unique value.
//     A node with a value of start exists in the tree.

#include "_BinaryTree.hpp"
#include <fmt/ranges.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>

void convert(TreeNode *curr, int parent,
             std::unordered_map<int, std::unordered_set<int>> &map) {
    if (!curr) {
        return;
    }

    std::unordered_set<int> &adjSet = map[curr->val];
    if (parent != 0) {
        adjSet.insert(parent);
    }
    if (curr->left) {
        adjSet.insert(curr->left->val);
    }
    if (curr->right) {
        adjSet.insert(curr->right->val);
    }

    convert(curr->left, curr->val, map);
    convert(curr->right, curr->val, map);
}

int amountOfTime(TreeNode *root, int start) {
    std::unordered_map<int, std::unordered_set<int>> map;
    convert(root, 0, map);
    std::queue<int> nodes;
    nodes.push(start);
    int min = 0;
    std::unordered_set<int> visited;
    visited.insert(start);

    while (!nodes.empty()) {
        int levelSize = nodes.size();
        while (levelSize > 0) {
            int curr = nodes.front();
            nodes.pop();

            for (int num : map[curr]) {
                if (!visited.contains(num)) {
                    visited.insert(num);
                    nodes.push(num);
                }
            }
            levelSize--;
        }
        min++;
    }

    return min - 1;
}
