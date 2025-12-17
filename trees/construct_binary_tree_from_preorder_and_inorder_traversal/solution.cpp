#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Recursive construction.
 * At each call:
 * - take next root from preorder using a shared index
 * - locate root position in inorder to split left/right subtrees
 * - recursively build left subtree, then right subtree
 *
 * Time:  O(n)
 * Space: O(n)   // hash map + recursion stack
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
private:
    TreeNode* build(vector<int>& preorder, int& preIndex,
                    int left, int right,
                    unordered_map<int,int>& idx) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = idx[rootVal];

        root->left  = build(preorder, preIndex, left, mid - 1, idx);
        root->right = build(preorder, preIndex, mid + 1, right, idx);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        unordered_map<int,int> idx;
        for (int i = 0; i < (int)inorder.size(); ++i)
            idx[inorder[i]] = i;

        int preIndex = 0;
        return build(preorder, preIndex, 0, (int)inorder.size() - 1, idx);
    }
};
