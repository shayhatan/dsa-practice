#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

/*
Stack — validate matching parentheses.
Time Complexity: O(n)
*/

class Solution {
    bool isOpen(char c) {
        return c == '(' || c == '[' || c == '{';
    }
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> m = {
            {'{','}'},
            {'[',']'},
            {'(',')'}
        };

        for (char c : s) {
            if (isOpen(c)) {
                stk.push(c);
            } else {
                if (stk.empty()) return false;
                if (m[stk.top()] != c) return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};
