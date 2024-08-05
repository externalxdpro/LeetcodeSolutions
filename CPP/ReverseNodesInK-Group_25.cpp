// 25. Reverse Nodes in k-Group
// Difficulty: Hard

// Given the head of a linked list, reverse the nodes of the list k at a time,
// and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked
// list. If the number of nodes is not a multiple of k then left-out nodes, in
// the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may
// be changed.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Constraints:
//     The number of nodes in the list is n.
//     1 <= k <= n <= 5000
//     0 <= Node.val <= 1000

// Follow-up: Can you solve the problem in O(1) extra memory space?

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        std::vector<int> nodes;
        while (head != nullptr) {
            nodes.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i <= nodes.size() - k; i += k) {
            std::reverse(nodes.begin() + i, nodes.begin() + i + k);
        }
        return toLinkedList(nodes);
    }

  private:
    ListNode *toLinkedList(const std::vector<int> &arr) {
        ListNode *root = nullptr;

        for (int i : arr) {
            auto     *newNode = new ListNode(i);
            ListNode *ptr     = nullptr;
            if (root == nullptr) {
                root = newNode;
            } else {
                ptr = root;
                while (ptr->next != nullptr) {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
            }
        }
        return root;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>
        tests = {
            {{{1, 2, 3, 4, 5}, 2}, {2, 1, 4, 3, 5}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(
            solution.reverseKGroup(toLinkedList(test.first), test.second));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
