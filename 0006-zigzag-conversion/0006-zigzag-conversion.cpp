// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string convert(string s, int numRows) {
        int l = s.length();
        if ((l < 2) || (numRows == 1))
            return s;
        string res = {};
        int step = (numRows - 1) * 2;
        int i = 0;
        while (i < l) {
            res += s[i];
            i += step;
        }
        for (int i = 1; i < numRows - 1; i++) {
            int j = i;
            int step1 = (numRows - i - 1) * 2;
            int step2 = step - step1;
            while (j < l) {
                res += s[j];
                j += step1;
                if (j >= l)
                    break;
                res += s[j];
                j += step2;
            }
        };
        i = numRows -1;
        while (i < l) {
            res += s[i];
            i += step;
        };
        return res;
    }
};