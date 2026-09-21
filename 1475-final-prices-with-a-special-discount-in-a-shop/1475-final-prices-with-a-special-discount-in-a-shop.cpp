// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size() - 1;
        if (n == 0)
            return prices;
        stack<int> thresholds;
        thresholds.push(prices[n]);
        for (int i = n - 1; i >= 0; i--) {
            int p = prices[i];
            while ((!thresholds.empty()) && (p < thresholds.top()))
                thresholds.pop();
            if (!thresholds.empty())
                prices[i] -= thresholds.top();
            thresholds.push(p);
        }
        return prices;
    }
};