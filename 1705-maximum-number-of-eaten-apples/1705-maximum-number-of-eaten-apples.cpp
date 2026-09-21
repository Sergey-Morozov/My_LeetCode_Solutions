// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int, int> m;
        int res = 0;
        for (int i = 0; i < apples.size(); i++) {
            while (!m.empty() && (m.begin()->first) < i)
                m.erase(m.begin());
            if (apples[i] > 0)
                m[i + days[i] - 1] += apples[i];
            if (!m.empty()) {
                res++;
                (m.begin()->second)--;
                if (m.begin()->second == 0)
                    m.erase(m.begin());
            }
        }
        int i = apples.size();
        while (!m.empty()) {
            while (!m.empty() && m.begin()->first < i)
                m.erase(m.begin());
            if (!m.empty()) {
                res++;
                (m.begin()->second)--;
                if (m.begin()->second == 0)
                    m.erase(m.begin());
            }
            i++;
        }
        return res;
    }
};