// 2181. Merge Nodes in Between Zeros
// Difficulty: Medium

// You are given the head of a linked list, which contains a series of integers
// separated by 0's. The beginning and end of the linked list will have Node.val
// == 0.
// For every two consecutive 0's, merge all the nodes lying in between them into
// a single node whose value is the sum of all the merged nodes. The modified
// list should not contain any 0's.
// Return the head of the modified linked list.

// Example 1:
// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
// Explanation:
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 3 + 1 = 4.
// - The sum of the nodes marked in red: 4 + 5 + 2 = 11.

// Example 2:
// Input: head = [0,1,0,3,0,2,2,0]
// Output: [1,3,4]
// Explanation:
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 1 = 1.
// - The sum of the nodes marked in red: 3 = 3.
// - The sum of the nodes marked in yellow: 2 + 2 = 4.

// Constraints:
//     The number of nodes in the list is in the range [3, 2 * 10^5].
//     0 <= Node.val <= 1000
//     There are no two consecutive nodes with Node.val == 0.
//     The beginning and end of the linked list have Node.val == 0.

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *bbfr = head, *bfr = head, *curr = head->next;
        int       sum = 0;

        while (curr != nullptr) {
            if (curr->val == 0) {
                curr->val = sum;
                sum       = 0;

                bbfr->next = curr;
                bbfr       = bbfr->next;
            } else {
                sum += curr->val;
            }

            bfr  = bfr->next;
            curr = curr->next;
        }

        head = head->next;
        return head;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{0, 3, 1, 0, 4, 5, 2, 0}, {4, 11}},
        {{0, 1, 0, 3, 0, 2, 2, 0}, {1, 3, 4}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(solution.mergeNodes(toLinkedList(test)));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
