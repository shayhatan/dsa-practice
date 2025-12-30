#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
Greedy + stack from right to left.
Time Complexity: O(n log n)
*/

class Solution {
    double timeToTarget(int distance, int speed) {
        return double(distance) / double(speed);
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> cars(n);
        stack<double> stk;

        for (int i = 0; i < n; ++i)
            cars[i] = {position[i], speed[i]};

        sort(cars.begin(), cars.end()); // sort by position ascending

        for (int i = n - 1; i >= 0; --i) {
            double t = timeToTarget(target - cars[i].first, cars[i].second);
            if (stk.empty() || stk.top() < t)
                stk.push(t);
        }

        return (int)stk.size();
    }
};
