// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int it = 0;
        while (s[it] == 'M') {
            res += 1000;
            it++;
        };
        if (s[it] == 'C') {
            if (s[it + 1] == 'M') {
                res += 900;
                it++;
                it++;
            } else if (s[it + 1] == 'D') {
                res += 400;
                it++;
                it++;
            };
        };
        if (s[it] == 'D') {
            res += 500;
            it++;
        };
        while (s[it] == 'C') {
            res += 100;
            it++;
        };
        if (s[it] == 'X') {
            if (s[it + 1] == 'C') {
                res += 90;
                it++;
                it++;
            } else if (s[it + 1] == 'L') {
                res += 40;
                it++;
                it++;
            };
        };
        if (s[it] == 'L') {
            res += 50;
            it++;
        };
        while (s[it] == 'X') {
            res += 10;
            it++;
        };
        if (s[it] == 'I') {
            if (s[it + 1] == 'X') {
                res += 9;
                return res;
            } else if (s[it + 1] == 'V') {
                res += 4;
                return res;
            };
        };
        if (s[it] == 'V') {
            res += 5;
            it++;
        };
        while (s[it] == 'I') {
            res += 1;
            it++;
        };
        return res;
    };
};