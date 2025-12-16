#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
 * Count Good Nodes in Binary Tree
 *
 * BFS + state (path max)
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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        int ans = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                auto [curr, pathMax] = q.front();
                q.pop();

                if (curr->val >= pathMax) ++ans;
                pathMax = max(pathMax, curr->val);

                if (curr->left)  q.push({curr->left, pathMax});
                if (curr->right) q.push({curr->right, pathMax});
            }
        }

        return ans;
    }
};
