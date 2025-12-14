#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Build a frequency signature key for each string (26 counts).
// Use the key to group strings in a hash map.
//
// Time: O(n * k) where k is string length (counting chars)
// Space: O(n * k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        vector<vector<string>> ans;

        for (string s : strs) {
            vector<int> hist(26, 0);
            string key = "";

            for (char c : s) ++hist[c - 'a'];

            for (int i : hist) {
                key += '#';
                key += to_string(i);
            }

            res[key].push_back(s);
        }

        for (auto& [x, y] : res) {
            ans.push_back(y);
        }

        return ans;
    }
};
