// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> maker(int n) {
        vector<int> tmp{1};
        if (n > 1)
        {
            tmp = maker((n + 1) / 2);
            for (int i = 0; i < (n + 1) / 2; i++)
                tmp[i] = tmp[i] * 2 - 1;
            vector<int> tmp2 = maker(n / 2);
            for (int i = 0; i < n / 2; i++)
                tmp2[i] *= 2;
            tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
        }
        return tmp;
    }

    vector<int> beautifulArray(int n) { return maker(n); }
};