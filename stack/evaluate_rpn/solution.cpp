#include <stack>
#include <vector>
#include <string>
using namespace std;

/*
Stack — evaluate Reverse Polish Notation.
Time Complexity: O(n)
*/

class Solution {
    bool isOperator(const string& c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }

    int applyOp(stack<int>& stk, const string& c) {
        int b = stk.top(); stk.pop();
        int a = stk.top(); stk.pop();
        if (c == "+") return a + b;
        if (c == "-") return a - b;
        if (c == "*") return a * b;
        return a / b; // "/"
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& s : tokens)
            isOperator(s) ? stk.push(applyOp(stk, s))
                          : stk.push(stoi(s));

        return stk.top();
    }
};
