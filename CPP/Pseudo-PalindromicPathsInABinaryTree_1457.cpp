#include "_BinaryTree.hpp"
#include <algorithm>
#include <iostream>
#include <unordered_map>

class Solution {
  public:
    int pseudoPalindromicPaths(TreeNode *root) {
        std::unordered_map<int, int> path;
        return recurse(root, path);
    }

  private:
    int recurse(TreeNode *currNode, std::unordered_map<int, int> currPath) {
        currPath[currNode->val]++;

        if (!currNode->left && !currNode->right) {
            bool found = false;
            for (auto &[_, v] : currPath) {
                if (found && v % 2 != 0) {
                    return 0;
                }
                if (v % 2 != 0) {
                    found = true;
                }
            }
            return 1;
        } else if (!currNode->left) {
            return recurse(currNode->right, currPath);
        } else if (!currNode->right) {
            return recurse(currNode->left, currPath);
        }

        return recurse(currNode->left, currPath) +
               recurse(currNode->right, currPath);
    }
};
