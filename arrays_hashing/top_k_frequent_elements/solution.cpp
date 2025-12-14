#include <vector>
#include <unordered_map>

using namespace std;

// Bucket by frequency (1..n) and collect from highest to lowest.
// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<vector<int>> bucket(n + 1);
        vector<int> ans;

        for (int x : nums) {
            m[x]++;
        }

        for (auto [x, freq] : m) {
            bucket[freq].push_back(x);
        }

        for (int freq = n; freq >= 1; --freq) {
            for (int val : bucket[freq]) {
                ans.push_back(val);
                if ((int)ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};
