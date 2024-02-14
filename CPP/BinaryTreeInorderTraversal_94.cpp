// Difficulty: Easy
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]

// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 
// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversalRecursive(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr) return {};
    for (int i : inorderTraversalRecursive(root->left)) result.push_back(i);
    result.push_back(root->val);
    for (int i : inorderTraversalRecursive(root->right)) result.push_back(i);

    return result;
}

vector<int> inorderTraversalIterative(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> nodes;
    TreeNode* curr = root;

    while (curr != nullptr || !nodes.empty())
    {
        while (curr != nullptr)
        {
            nodes.push(curr);
            curr = curr->left;
        }

        curr = nodes.top();
        nodes.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }

    return result;
}

int main()
{
    TreeNode childChild(3);
    TreeNode child(2, &childChild, nullptr);
    TreeNode root(1, nullptr, &child);
    
    for (int i : inorderTraversalRecursive(&root))
        cout << i << " ";
    cout << endl;

    for (int i : inorderTraversalIterative(&root))
        cout << i << " ";
    cout << endl;
    return 0;
}