#include <vector>
#include <queue>
using namespace std;

/*
 * Binary Tree Level Order Traversal
 *
 * BFS using queue
 *
 * Time:  O(n)
 * Space: O(n)
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
