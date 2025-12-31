/*
Product of array except self (handle zeros).
Time Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cntZeros = 0, zeroIdx, mul = 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                cntZeros++;
                zeroIdx = i;
            } else {
                mul *= nums[i];
            }
        }

        if (cntZeros > 1) return vector(nums.size(), 0);

        if (cntZeros == 1) {
            vector<int> ans(nums.size(), 0);
            ans[zeroIdx] = mul;
            return ans;
        }

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = mul / nums[i];
        }

        return nums;
    }
};
