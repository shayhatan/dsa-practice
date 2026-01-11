#include <vector>
#include <algorithm>
using namespace std;

/*
 Two pointers approach:
 Maintain leftMax and rightMax, move the pointer with the smaller bound,
 and accumulate trapped water greedily.
 Time: O(n), Space: O(1)
*/

class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int leftMax = h[l], rightMax = h[r];
        int ans = 0;

        while (l < r) {
            int currMin = min(leftMax, rightMax);
            if (leftMax > rightMax) {
                if (currMin > h[--r]) {
                    ans += currMin - h[r];
                } else {
                    rightMax = h[r];
                }
            } else {
                if (currMin > h[++l]) {
                    ans += currMin - h[l];
                } else {
                    leftMax = h[l];
                }
            }
        }

        return ans;
    }
};
