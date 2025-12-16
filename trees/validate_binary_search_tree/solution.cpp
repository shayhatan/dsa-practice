#include <climits>
using namespace std;

/*
 * Validate Binary Search Tree
 *
 * DFS Inorder
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
    bool inOrder(TreeNode* root, long long& prev) {
        if (!root) return true;

        if (!inOrder(root->left, prev)) return false;

        if (root->val <= prev) return false;
        prev = root->val;

        if (!inOrder(root->right, prev)) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return inOrder(root, prev);
    }
};
