// [1669] Merge In Between Linked Lists
// Difficulty: Medium

// You are given two linked lists: list1 and list2 of sizes n and m
// respectively.
// Remove list1's nodes from the ath node to the bth node, and put list2 in
// their place.
// The blue edges and nodes in the following figure indicate the result:
// Build the result list and return its head.

// Example 1:
// Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 =
// [1000000,1000001,1000002] Output: [10,1,13,1000000,1000001,1000002,5]
// Explanation: We remove the nodes 3 and 4 and put the entire list2 in their
// place. The blue edges and nodes in the above figure indicate the result.

// Example 2:
// Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 =
// [1000000,1000001,1000002,1000003,1000004] Output:
// [0,1,1000000,1000001,1000002,1000003,1000004,6] Explanation: The blue edges
// and nodes in the above figure indicate the result.

// Constraints:
//     3 <= list1.length <= 10^4
//     1 <= a <= b < list1.length - 1
//     1 <= list2.length <= 10^4

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        auto root = list1;

        for (int i = 0; i < a - 1; i++) {
            root = root->next;
        }
        auto start = root;
        for (int i = 0; i < b - a + 2; i++) {
            root = root->next;
        }
        auto end   = root;
        root       = start;
        root->next = list2;
        while (root->next != nullptr) {
            root = root->next;
        }
        root->next = end;

        return list1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::tuple<std::vector<int>, int, int, std::vector<int>>,
                  std::vector<int>>>
        tests = {
            {{{10, 1, 13, 6, 9, 5}, 3, 4, {1000000, 1000001, 1000002}},
             {10, 1, 13, 1000000, 1000001, 1000002, 5}},
            {{{0, 1, 2, 3, 4, 5, 6},
              2,
              5,
              {1000000, 1000001, 1000002, 1000003, 1000004}},
             {0, 1, 1000000, 1000001, 1000002, 1000003, 1000004, 6}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = toVector(solution.mergeInBetween(
            toLinkedList(std::get<0>(test)), std::get<1>(test),
            std::get<2>(test), toLinkedList(std::get<3>(test))));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
