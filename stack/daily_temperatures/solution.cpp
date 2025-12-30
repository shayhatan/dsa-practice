#include <vector>
#include <stack>
using namespace std;

/*
Monotonic stack — next warmer day.
Time Complexity: O(n)
*/

class Solution {
    void countDays(stack<pair<int,int>>& stk, vector<int>& res, pair<int,int> curr) {
        while (!stk.empty() && stk.top().first < curr.first) {
            int index = stk.top().second;
            res[index] = curr.second - index;
            stk.pop();
        }
        stk.push(curr);
    }

public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> stk; // <temp, index>
        vector<int> res(t.size(), 0);

        for (int i = 0; i < (int)t.size(); ++i)
            countDays(stk, res, {t[i], i});

        return res;
    }
};
