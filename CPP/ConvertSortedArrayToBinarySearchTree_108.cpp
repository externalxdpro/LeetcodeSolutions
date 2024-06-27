// 108. Convert Sorted Array to Binary Search Tree
// Difficulty: Easy

// Given an integer array nums where the elements are sorted in ascending order,
// convert it to a height-balanced binary search tree.

// Example 1:
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:
// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

// Constraints:
//     1 <= nums.length <= 10^4
//     -10^4 <= nums[i] <= 10^4
//     nums is sorted in a strictly increasing order.

#include "_BinaryTree.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums) {
        return construct(nums, 0, nums.size() - 1);
    }

  private:
    TreeNode *construct(std::vector<int> &nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int       m    = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left     = construct(nums, l, m - 1);
        root->right    = construct(nums, m + 1, r);

        return root;
    }
};

int main(int argc, char *argv[]) { return 0; }
