// 109. Convert Sorted List to Binary Search Tree
// Difficulty: Medium

// Given the head of a singly linked list where elements are sorted in ascending
// order, convert it to a height-balanced binary search tree.

// Example 1:
// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the
// shown height balanced BST.

// Example 2:
// Input: head = []
// Output: []

// Constraints:
//     The number of nodes in head is in the range [0, 2 * 10^4].
//     -10^5 <= Node.val <= 10^5

#include "_BinaryTree.hpp"
#include "_LinkedList.hpp"

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    TreeNode *sortedListToBST(ListNode *head) {
        std::vector<int> nodes;
        while (head != nullptr) {
            nodes.push_back(head->val);
            head = head->next;
        }
        return construct(nodes, 0, nodes.size() - 1);
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

int main(int argc, char *argv[]) {}
