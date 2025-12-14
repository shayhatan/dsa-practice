#include <string>
#include <vector>

using namespace std;

// Compare character frequency histograms for both strings.
// If all counts match, the strings are anagrams.
//
// Time: O(n)
// Space: O(1)  (fixed alphabet size)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> hist1(26, 0);
        vector<int> hist2(26, 0);

        for (char c : s) ++hist1[c - 'a'];
        for (char c : t) ++hist2[c - 'a'];

        for (int i = 0; i < 26; ++i) {
            if (hist1[i] != hist2[i]) return false;
        }

        return true;
    }
};
