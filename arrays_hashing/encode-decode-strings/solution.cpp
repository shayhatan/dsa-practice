/*
Length-prefix string encoding/decoding.
Time Complexity: O(total characters)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string encodeStr;
        for (string s : strs) {
            encodeStr += to_string(s.size()) + '#' + s;
        }
        return encodeStr;
    }

    vector<string> decode(string s) {
        vector<string> decodeStrs;

        for (int i = 0; i < s.size(); ++i) {
            string lenString = "";
            while (s[i] != '#') {
                lenString += s[i++];
            }

            int len = stoi(lenString);
            decodeStrs.push_back(s.substr(++i, len));
            i += len - 1;
        }

        return decodeStrs;
    }
};
