#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Hash set + detect starts of sequences; expand forward to get max streak.
// Time: O(n) average, Space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict(nums.begin(), nums.end());
        int ans = 0;

        for (int num : dict) {
            // start of a sequence
            if (!dict.count(num - 1)) {
                int len = 1;

                while (dict.count(num + 1)) {
                    num++;
                    len++;
                }
                ans = max(ans, len);
            }
        }

        return ans;
    }
};
