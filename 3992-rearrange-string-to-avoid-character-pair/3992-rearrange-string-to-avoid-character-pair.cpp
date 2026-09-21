// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int cx = 0;
        int cy = 0;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == x)
                cx++;
            else if (ch == y)
                cy++;
            else
                res += ch;
        };
        for (int i = 0; i < cy; i++)
            res += y;
        for (int i = 0; i < cx; i++)
            res += x;
        return res;
    }
};