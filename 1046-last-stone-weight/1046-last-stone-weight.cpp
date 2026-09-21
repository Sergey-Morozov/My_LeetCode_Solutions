// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        map<int, int> weights;
        for (int i : stones)
            weights[i]++;
        while (weights.size() > 1) {
            auto it = --weights.end();
            it->second %= 2;
            if (it->second == 0)
                weights.erase(it);
            else {
                int w1 = it->first;
                weights.erase(it);
                it--;
                int w2 = it->first;
                if (it->second == 1)
                    weights.erase(it);
                else
                    (it->second)--;
                weights[w1 - w2]++;
            }
        }
        if (weights.size() == 0 || weights.begin()->second % 2 == 0)
            return 0;
        return (weights.begin()->first);
    }
};