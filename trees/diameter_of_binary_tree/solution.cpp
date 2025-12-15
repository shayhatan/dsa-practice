#include <algorithm>
using namespace std;

/*
 * Diameter of Binary Tree
 *
 * DFS.
 * At each node:
 * - compute left and right subtree depths
 * - update global diameter: leftDepth + rightDepth (edges)
 * - return depth to parent
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
    int best = 0;  // best diameter in edges

public:
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        best = max(best, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return best;
    }
};
