#include <utility>
using namespace std;

/*
 * Kth Smallest Element in a BST
 *
 * DFS Inorder traversal (BST yields sorted order)
 *
 * Time:  O(n)
 * Space: O(h)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void inOrder(TreeNode* root, pair<int, int>& ans, int k) {
        if (!root) return;

        inOrder(root->left, ans, k);

        ++ans.first;
        if (ans.first == k) {
            ans.second = root->val;
            return;
        }

        inOrder(root->right, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        pair<int, int> ans{0, -1}; // <count, value>
        inOrder(root, ans, k);
        return ans.second;
    }
};
