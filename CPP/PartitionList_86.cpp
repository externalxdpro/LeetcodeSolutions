// 86. Partition List
// Difficulty: Medium

// Given the head of a linked list and a value x, partition it such that all
// nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the
// two partitions.

// Example 1:
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:
// Input: head = [2,1], x = 2
// Output: [1,2]

// Constraints:
//     The number of nodes in the list is in the range [0, 200].
//     -100 <= Node.val <= 100
//     -200 <= x <= 200

#include "_LinkedList.hpp"

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        std::vector<int> l, h;
        while (head != nullptr) {
            if (head->val < x) {
                l.push_back(head->val);
            } else {
                h.push_back(head->val);
            }
            head = head->next;
        }
        l.insert(l.end(), h.begin(), h.end());
        return toLinkedList(l);
    }

  private:
    ListNode *toLinkedList(const std::vector<int> &arr) {
        ListNode *root = nullptr, *ptr = nullptr;

        for (int i : arr) {
            auto *newNode = new ListNode(i);
            if (root == nullptr) {
                root = newNode;
            } else {
                if (ptr == nullptr) {
                    ptr = root;
                }
                ptr->next = newNode;
                ptr       = ptr->next;
            }
        }
        return root;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>
        tests = {
            {{{1, 4, 3, 2, 5, 2}, 3}, {1, 2, 2, 4, 3, 5}},
            {{{2, 1}, 2}, {1, 2}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            toVector(solution.partition(toLinkedList(test.first), test.second));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
