#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

// Recursively invert left and right subtrees, then swap them.
//
// Time: O(n)
// Space: O(h)  (recursion stack, h = tree height)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* leftSub = invertTree(root->left);
        TreeNode* rightSub = invertTree(root->right);

        root->left = rightSub;
        root->right = leftSub;

        return root;
    }
};
