// 1530. Number of Good Leaf Nodes Pairs
// Difficulty: Medium

// You are given the root of a binary tree and an integer distance. A pair of
// two different leaf nodes of a binary tree is said to be good if the length of
// the shortest path between them is less than or equal to distance.
// Return the number of good leaf node pairs in the tree.

// Example 1:
// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the
// shortest path between them is 3. This is the only good pair.

// Example 2:
// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The
// pair [4,6] is not good because the length of ther shortest path between them
// is 4.

// Example 3:
// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
// Output: 1
// Explanation: The only good pair is [2,5].

// Constraints:
//     The number of nodes in the tree is in the range [1, 2^10].
//     1 <= Node.val <= 100
//     1 <= distance <= 10

#include "_BinaryTree.hpp"

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int countPairs(const TreeNode *root, const int distance) {
        int result = 0;
        dfs(root, distance, result);

        return result;
    }

  private:
    std::vector<int> dfs(const TreeNode *node, const int distance,
                         int &result) {
        if (node == nullptr) {
            return {};
        }
        if (node->left == nullptr && node->right == nullptr) {
            return {1};
        }

        const std::vector<int> &left  = dfs(node->left, distance, result);
        const std::vector<int> &right = dfs(node->right, distance, result);

        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) {
                    result++;
                }
            }
        }

        std::vector<int> res;
        for (int l : left) {
            if (l + 1 <= distance) {
                res.push_back(l + 1);
            }
        }
        for (int r : right) {
            if (r + 1 <= distance) {
                res.push_back(r + 1);
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) { return 0; }
