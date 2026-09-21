// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int res = 0;
        for (int i = 0; i < minutes; i++)
            if (grumpy[i])
                sum += customers[i];
            else
                res += customers[i];
        int maxsum = sum;
        for (int i = 0; i < customers.size() - minutes; i++) {
            if (grumpy[i])
                sum -= customers[i];
            if (grumpy[i + minutes])
                sum += customers[i + minutes];
            else
                res += customers[i + minutes];
            maxsum = max(sum, maxsum);
        }
        return res + maxsum;
    }
};