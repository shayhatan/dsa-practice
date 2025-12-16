#include <algorithm>
using namespace std;

/*
 * Lowest Common Ancestor in a Binary Search Tree
 *
 * BST Top-Down navigation
 *
 * Time:  O(h)
 * Space: O(1)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int high = q->val >= p->val ? q->val : p->val;
        int low  = q->val <  p->val ? q->val : p->val;

        while (root) {
            if (root->val > high) {
                root = root->left;
            } else if (root->val < low) {
                root = root->right;
            } else {
                return root;
            }
        }
        return root;
    }
};
