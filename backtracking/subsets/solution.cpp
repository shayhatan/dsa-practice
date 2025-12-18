#include <vector>
using namespace std;

/*
Time Complexity: O(2^n * n)
- There are 2^n subsets
- Each subset copy takes up to O(n)

Space Complexity:
- O(n) recursion stack
- O(2^n * n) for output

Approach:
Classic backtracking using a binary decision tree (include / exclude).
At each index, we decide whether to include nums[i] in the current subset.
*/

class Solution {
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        // include nums[i]
        curr.push_back(nums[i]);
        dfs(i + 1, nums);
        curr.pop_back();

        // exclude nums[i]
        dfs(i + 1, nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // good habits (optional)
        ans.clear();
        curr.clear();

        dfs(0, nums);
        return ans;
    }
};
