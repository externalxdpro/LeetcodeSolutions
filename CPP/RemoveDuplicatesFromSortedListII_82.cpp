// 82. Remove Duplicates from Sorted List II
// Difficulty: Medium

// Given the head of a sorted linked list, delete all nodes that have duplicate
// numbers, leaving only distinct numbers from the original list. Return the
// linked list sorted as well.

// Example 1:
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:
// Input: head = [1,1,1,2,3]
// Output: [2,3]

// Constraints:
//     The number of nodes in the list is in the range [0, 300].
//     -100 <= Node.val <= 100
//     The list is guaranteed to be sorted in ascending order.

#include "_LinkedList.hpp"

#include <array>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        std::array<int, 202> counts = {0};
        for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
            counts[curr->val + 100]++;
        }

        return recurse(head, nullptr, counts);
    }

  private:
    ListNode *recurse(ListNode *curr, ListNode *prev,
                      std::array<int, 202> &counts) {
        if (curr == nullptr) {
            return nullptr;
        }
        if (counts[curr->val + 100] > 1) {
            if (prev == nullptr) {
                ListNode *temp = recurse(curr->next, nullptr, counts);
                delete curr;
                return temp;
            }
            prev->next = curr->next;
            delete curr;
            return recurse(prev->next, prev, counts);
        }
        recurse(curr->next, curr, counts);
        return curr;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1, 2, 3, 3, 4, 4, 5}, {1, 2, 5}},
        {{1, 1, 1, 2, 3}, {2, 3}},
        {{1, 1, 1}, {}},
        {{1, 2, 3, 3, 4, 5, 5}, {1, 2, 4}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(solution.deleteDuplicates(toLinkedList(test)));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
