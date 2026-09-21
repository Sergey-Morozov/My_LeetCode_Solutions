// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int magicalString(int n) {
        if (n <= 3)
            return 1;
        string s = "122";
        int p = 1;
        char curr = '1';
        int i = 3;
        int res = 1;
        while (i < n) {
            ++p;
            if (s[p] == '1') {
                s += curr;
                ++i;
                if (curr == '1')
                    ++res;
            } else {
                s += curr;
                if (curr == '1')
                    ++res;
                ++i;
                if (i == n)
                    break;
                s += curr;
                if (curr == '1')
                    ++res;
                ++i;
            }
            curr = 3 - (curr - '0') + '0';
        }
        return res;
    }
};