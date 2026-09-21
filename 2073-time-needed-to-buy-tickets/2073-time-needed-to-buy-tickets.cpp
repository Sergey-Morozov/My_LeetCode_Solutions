// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int need = tickets[k], res = need;
        for (int i = 0; i < k; i++)
            res += min(need, tickets[i]);
        for (int i = k + 1; i < tickets.size(); i++)
            res += min(need - 1, tickets[i]);
        return res;
    }
};