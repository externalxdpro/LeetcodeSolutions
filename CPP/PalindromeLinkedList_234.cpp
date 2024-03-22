// [234] Palindrome Linked List
// Difficulty: Easy

// Given the head of a singly linked list, return true if it is a
// palindrome
// or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

// Constraints:
//     The number of nodes in the list is in the range [1, 105].
//     0 <= Node.val <= 9

// Follow up: Could you do it in O(n) time and O(1) space?

#include "_LinkedList.hpp"

#include <algorithm>
#include <fmt/ranges.h>
#include <stack>
#include <vector>

class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        int  len  = 0;
        auto temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        std::stack<int> found;
        temp = head;
        for (int i = 0; i < len / 2; i++) {
            found.push(temp->val);
            temp = temp->next;
        }
        if (len % 2 == 1) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            if (found.top() != temp->val) {
                return false;
            }
            found.pop();
            temp = temp->next;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, bool>> tests = {
        {{1, 2, 2, 1}, true},
        {{1, 2}, false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.isPalindrome(toLinkedList(test));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
