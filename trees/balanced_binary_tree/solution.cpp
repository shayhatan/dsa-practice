#include <algorithm>
using namespace std;

/*
 * Postorder DFS:
 * - compute height of left subtree
 * - compute height of right subtree
 * - validate balance at current node
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
    static constexpr int UNBALANCED = -1;

public:
    int getHeight(TreeNode* root) {
        if (!root) return 0;

        int left = getHeight(root->left);
        if (left == UNBALANCED) return UNBALANCED;

        int right = getHeight(root->right);
        if (right == UNBALANCED) return UNBALANCED;

        if (abs(left - right) > 1) return UNBALANCED;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != UNBALANCED;
    }
};
