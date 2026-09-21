// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        struct rec {
            int day;
            int temp;
        };
        stack<rec> warms;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int t = temperatures[i];
            while (!warms.empty() && warms.top().temp <= t)
                warms.pop();
            if (!warms.empty())
                temperatures[i] = warms.top().day - i;
            else
                temperatures[i] = 0;
            warms.push({i, t});
        }
        return temperatures;
    }
};