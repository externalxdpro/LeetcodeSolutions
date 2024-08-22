// 95. Unique Binary Search Trees II
// Difficulty: Medium

// Given an integer n, return all the structurally unique BST's (binary search
// trees), which has exactly n nodes of unique values from 1 to n. Return the
// answer in any order.

// Example 1:
// Input: n = 3
// Output:
// [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

// Example 2:
// Input: n = 1
// Output: [[1]]

// Constraints:
//     1 <= n <= 8

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <vector>

class Solution {
  public:
    std::vector<TreeNode *> generateTrees(int n) {
        std::map<std::pair<int, int>, std::vector<TreeNode *>> dp;
        return recurse(1, n, dp);
    }

    std::vector<TreeNode *>
    recurse(int l, int r,
            std::map<std::pair<int, int>, std::vector<TreeNode *>> &dp) {
        if (l > r) {
            return {nullptr};
        }
        if (!dp[{l, r}].empty()) {
            return dp[{l, r}];
        }

        std::vector<TreeNode *> result;
        for (int i = l; i <= r; i++) {
            auto lTree = recurse(l, i - 1, dp), rTree = recurse(i + 1, r, dp);

            for (auto left : lTree) {
                for (auto right : rTree) {
                    result.push_back(new TreeNode(i, left, right));
                }
            }
        }

        return dp[{l, r}] = result;
    }
};

int main(int argc, char *argv[]) {}
