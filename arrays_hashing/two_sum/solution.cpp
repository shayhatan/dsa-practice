#include <vector>
#include <unordered_map>

using namespace std;

// Use a hash map to store values and their indices.
// For each element, check if its complement exists.
//
// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];

            if (m.find(diff) != m.end())
                return {m[diff], i};

            m[nums[i]] = i;
        }

        return {};
    }
};
