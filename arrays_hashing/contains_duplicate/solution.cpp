#include <vector>
#include <unordered_set>

using namespace std;

// Use a hash set to track seen values.
// If a value appears twice, return true.
//
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dict;

        for (int i : nums) {
            if (dict.find(i) != dict.end())
                return true;
            dict.insert(i);
        }

        return false;
    }
};
