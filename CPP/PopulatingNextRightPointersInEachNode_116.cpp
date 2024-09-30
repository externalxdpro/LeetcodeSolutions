// 116. Populating Next Right Pointers in Each Node
// Difficulty: Medium

// You are given a perfect binary tree where all leaves are on the same level,
// and every parent has two children. The binary tree has the following
// definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }

// Populate each next pointer to point to its next right node. If there is no
// next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Example 1:

// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function
// should populate each next pointer to point to its next right node, just like
// in Figure B. The serialized output is in level order as connected by the next
// pointers, with '#' signifying the end of each level.

// Example 2:

// Input: root = []
// Output: []

// Constraints:

//     The number of nodes in the tree is in the range [0, 212 - 1].
//     -1000 <= Node.val <= 1000

// Follow-up:

//     You may only use constant extra space.
//     The recursive approach is fine. You may assume implicit stack space does
//     not count as extra space for this problem.

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Node {
  public:
    int   val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
    Node *connect(Node *root) {
        if (root == nullptr) {
            return root;
        }

        std::vector<std::vector<Node *>> nodes;
        std::queue<Node *>               q{{root}};
        while (!q.empty()) {
            nodes.emplace_back();
            int n = q.size();
            while (n--) {
                nodes.back().push_back(q.front());
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        for (const std::vector<Node *> &level : nodes) {
            for (int i = 0; i < level.size() - 1; i++) {
                level[i]->next = level[i + 1];
            }
        }

        return root;
    }
};

int main(int argc, char *argv[]) {}
