// Three Sum using sort + two pointers
// Time Complexity: O(n^2), Space Complexity: O(1) extra (excluding output)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void skip(int& l, int& r, vector<int>& nums) {
        int vl = nums[l];
        int vr = nums[r];
        while (l < r && vl == nums[l]) ++l;
        while (l < r && vr == nums[r]) --r;
    }

    void twoSum(vector<int>& nums, int startIdx, int target, vector<vector<int>>& ans) {
        int l = startIdx, r = nums.size() - 1;

        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum == target) {
                ans.push_back({-target, nums[l], nums[r]});
                skip(l, r, nums);
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            twoSum(nums, i + 1, -nums[i], ans);
        }
        return ans;
    }
};
