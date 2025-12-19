#include <vector>
using namespace std;

/*
    Backtracking using a binary decision tree (include / exclude).
    Time Complexity: O(2^(target))
*/

class Solution {
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(vector<int>& nums, int x, int i) {
        if (x < 0) return;

        if (x == 0) {
            ans.push_back(curr);
            return;
        }

        if (i == nums.size()) return;

        curr.push_back(nums[i]);
        solve(nums, x - nums[i], i);
        curr.pop_back();

        solve(nums, x, i + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // good habits (optional)
        ans.clear();
        curr.clear();

        solve(nums, target, 0);
        return ans;
    }
};
