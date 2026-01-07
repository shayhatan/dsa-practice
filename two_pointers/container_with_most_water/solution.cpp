#include <vector>
#include <algorithm>
using namespace std;

/*
 Two pointers from both ends.
 Move the pointer with the smaller height to potentially increase min height.
 Time: O(n), Space: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0, l = 0, r = h.size() - 1;

        while(l < r) {
            int area = (r - l) * min(h[r], h[l]);
            ans = max(area, ans);
            h[r] > h[l] ? ++l : --r;
        }

        return ans;
    }
};
