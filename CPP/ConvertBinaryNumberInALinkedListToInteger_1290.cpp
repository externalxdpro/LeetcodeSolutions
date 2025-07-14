// 1290. Convert Binary Number in a Linked List to Integer
// Difficulty: Easy

// Given head which is a reference node to a singly-linked list. The value of
// each node in the linked list is either 0 or 1. The linked list holds the
// binary representation of a number.

// Return the decimal value of the number in the linked list.

// The most significant bit is at the head of the linked list.

// Example 1:

// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10

// Example 2:

// Input: head = [0]
// Output: 0

// Constraints:

//     The Linked List is not empty.
//     Number of nodes will not exceed 30.
//     Each node's value is either 0 or 1.

#include "_LinkedList.hpp"

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int getDecimalValue(ListNode *head) {
        int num = 0;
        while (head != nullptr) {
            num = num * 2 + head->val;
            head = head->next;
        }
        return num;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 0, 1}, 5},
        {{0}, 0},
        {{1, 1, 0}, 6},
        {{1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 18880},
        {{1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 685569},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.getDecimalValue(toLinkedList(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
