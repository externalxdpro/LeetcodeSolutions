// Difficulty: Easy
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing
// together the nodes of the first two lists. Return the head of the merged
// linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

// Constraints:
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#include <iostream>
#include <string>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *list, std::string seperator = " ")
{
    std::cout << list->val;
    while (list->next != nullptr)
    {
        list = list->next;
        std::cout << seperator << list->val;
    }
    std::cout << "\n";
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}

int main()
{
    ListNode c1(4), b1(2, &c1), a1(1, &b1);
    ListNode c2(4), b2(3, &c2), a2(1, &b2);
    printList(mergeTwoLists(&a1, &a2), ", ");
}

