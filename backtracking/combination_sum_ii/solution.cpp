#include <vector>
#include <algorithm>
using namespace std;

/*
    Backtracking using a binary decision tree (include / exclude).
    Time Complexity: O(n * 2^n)
*/

class Solution {
    vector<vector<int>> ans;
    vector<int> curr;

    int getNextIndex(vector<int>& nums, int i) {
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        return i + 1;
    }

    void solve(vector<int>& nums, int x, int i) {
        if (x < 0) return;

        if (x == 0) {
            ans.push_back(curr);
            return;
        }

        if (i == nums.size()) return;

        // include nums[i]
        curr.push_back(nums[i]);
        solve(nums, x - nums[i], i + 1);
        curr.pop_back();

        // exclude nums[i] (skip duplicates)
        solve(nums, x, getNextIndex(nums, i));
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // good habits (optional)
        ans.clear();
        curr.clear();

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};
