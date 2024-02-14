// Difficulty: Hard
// You are given an array of k linked-lists lists, each linked-list is sorted in
// ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []

// Constraints:
//     k == lists.length
//     0 <= k <= 10^4
//     0 <= lists[i].length <= 500
//     -10^4 <= lists[i][j] <= 10^4
//     lists[i] is sorted in ascending order.
//     The sum of lists[i].length will not exceed 10^4.

#include "_LinkedList.hpp"
#include <algorithm>
#include <iostream>
#include <ranges>

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    if (lists.size() == 0 || std::ranges::find_if(lists, [](ListNode *i) {
                                 return i != nullptr;
                             }) == lists.end()) {
        return nullptr;
    }

    std::vector<ListNode *> currNodes = lists;
    ListNode *root;
    ListNode *tail;

    int smallestIndex = 0;
    for (int i = 1; i < currNodes.size(); i++) {
        if (currNodes[i] == nullptr) {
            continue;
        }

        if (currNodes[smallestIndex] == nullptr ||
            currNodes[i]->val < currNodes[smallestIndex]->val) {
            smallestIndex = i;
        }
    }
    root = currNodes[smallestIndex];
    tail = currNodes[smallestIndex];
    currNodes[smallestIndex] = currNodes[smallestIndex]->next;

    while (std::ranges::find_if(currNodes, [](ListNode *i) {
               return i != nullptr;
           }) != currNodes.end()) {
        smallestIndex = 0;
        for (int i = 1; i < currNodes.size(); i++) {
            if (currNodes[i] == nullptr) {
                continue;
            }

            if (currNodes[smallestIndex] == nullptr ||
                currNodes[i]->val < currNodes[smallestIndex]->val) {
                smallestIndex = i;
            }
        }
        tail->next = currNodes[smallestIndex];
        tail = tail->next;
        currNodes[smallestIndex] = currNodes[smallestIndex]->next;
    }

    return root;
}

// How is this faster i hate leetcode
// ListNode *mergeKLists(vector<ListNode *> &lists) {
//     std::vector<int> arr;

//     for (auto root : lists) {
//         while (root != nullptr) {
//             arr.push_back(root->val);
//             root = root->next;
//         }
//     }
//     std::ranges::sort(arr);

//     ListNode *result = new ListNode();
//     ListNode *node = result;
//     for (auto i : arr) {
//         node->next = new ListNode(i);
//         node = node->next;
//     }
//     result = result->next;

//     return result;
// }

int main() {
    std::vector<std::vector<int>> vectors = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6},
    };

    std::vector<ListNode *> lists;
    for (auto i : vectors | std::ranges::views::transform(
                                [](auto i) { return createLinkedList(i); })) {
        lists.push_back(i);
    }

    ListNode *result = mergeKLists(lists);
    printLinkedList(result);

    lists = {nullptr};
    printLinkedList(mergeKLists(lists));

    vectors = {{}, {1}};
    lists = {nullptr, createLinkedList(vectors[1])};
    printLinkedList(mergeKLists(lists));
}
