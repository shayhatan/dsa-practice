#include <vector>
#include <queue>
using namespace std;

/*
 * Binary Tree Right Side View
 *
 * BFS (Level Order)
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while (!q.empty()) {
            int levelSize = q.size();
            int mostRight;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);

                mostRight = curr->val;
            }

            ans.push_back(mostRight);
        }

        return ans;
    }
};
