// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int count = 0;
        for (char i : s)
            if (i != '-') count++;
        int buff = count % k;
        if (buff == 0)
            buff = k;
        for (char i : s) {
            if (i == '-')
                continue;
            if (buff == 0) {
                res += '-';
                buff = k;
            }
            if (i >= 'a' && i <= 'z')
                res += i - 'a' + 'A';
            else
                res += i;
            buff--;
        }
        return res;
    }
};