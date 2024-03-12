// Difficulty: Medium
// Given the head of a linked list, we repeatedly delete consecutive sequences
// of nodes that sum to 0 until there are no such sequences.
// After doing so, return the head of the final linked list.  You may return any
// such answer.
// (Note that in the examples below, all sequences are serializations of
// ListNode objects.)

// Example 1:
// Input: head = [1,2,-3,3,1]
// Output: [3,1]
// Note: The answer [1,2,1] would also be accepted.

// Example 2:
// Input: head = [1,2,3,-3,4]
// Output: [1,2,4]

// Example 3:
// Input: head = [1,2,3,-3,-2]
// Output: [1]

// Constraints:
//     The given linked list will contain between 1 and 1000 nodes.
//     Each node in the linked list has -1000 <= node.val <= 1000.

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
  public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        auto it1 = head;
        int  sum = 0;
        while (it1 != nullptr) {
            sum += it1->val;
            if (sum == 0) {
                head = it1->next;
                it1  = head;
            } else {
                it1 = it1->next;
            }
        }

        it1 = head;
        while (it1 != nullptr) {
            auto it2 = it1->next;
            sum      = 0;
            while (it2 != nullptr) {
                sum += it2->val;
                if (sum == 0) {
                    it1->next = it2->next;
                    break;
                }
                it2 = it2->next;
            }
            if (sum == 0) {
                if (it2 == nullptr) {
                    break;
                }
                it1 = head;
            } else {
                it1 = it1->next;
            }
        }

        return head;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1, 2, -3, 3, 1}, {3, 1}},
        {{1, 2, 3, -3, 4}, {1, 2, 4}},
        {{1, 2, 3, -3, -2}, {1}},
        {{1, -1}, {}},
        {{0, 0}, {}},
        {{2, 2, -2, 1, -1, -1}, {2, -1}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            toVector(solution.removeZeroSumSublists(toLinkedList(test)));

        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
