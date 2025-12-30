#include <stack>
#include <algorithm>
using namespace std;

/*
Stack with O(1) minimum tracking.
Time Complexity: O(1) per operation
*/

class MinStack {
    stack<pair<int,int>> stk; // <value, current_min>
public:
    void push(int val) {
        if (stk.empty())
            stk.push({val, val});
        else
            stk.push({val, min(val, stk.top().second)});
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
};
