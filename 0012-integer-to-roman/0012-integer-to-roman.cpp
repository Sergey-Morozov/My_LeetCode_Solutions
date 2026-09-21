// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        while (num >= 1000) {
            res += 'M';
            num -= 1000;
        };
        if (num >= 900) {
            res +="CM";
            num -= 900;
        };
        if (num >= 800) {
            res +="DCCC";
            num -= 800;
        };
        if (num >= 700) {
            res +="DCC";
            num -= 700;
        };
        if (num >= 600) {
            res +="DC";
            num -= 600;
        };
        if (num >= 500) {
            res +='D';
            num -= 500;
        };
        if (num >= 400) {
            res +="CD";
            num -= 400;
        };
        while (num >= 100) {
            res += 'C';
            num -= 100;
        };
        if (num >= 90) {
            res +="XC";
            num -= 90;
        };
        if (num >= 80) {
            res += "LXXX";
            num -= 80;
        };
        if (num >= 70) {
            res += "LXX";
            num -= 70;
        };
        if (num >= 60) {
            res += "LX";
            num -= 60;
        };
        if (num >= 50) {
            res += 'L';
            num -= 50;
        };
        if (num >= 40) {
            res += "XL";
            num -= 40;
        };
        while (num >= 10) {
            res += 'X';
            num -= 10;
        };
        if (num == 9) {
            res += "IX";
            return res;
        }
        else if (num == 8) {
            res += "VIII";
            return res;
        }
        else if (num == 7) {
            res += "VII";
            return res;
        }
        else if (num == 6) {
            res += "VI";
            return res;
        }
        else if (num == 5) {
            res += 'V';
            return res;
        }
        else if (num == 4) {
            res += "IV";
            return res;
        }
        while (num >= 1) {
            res += 'I';
            num -= 1;
        };
        return res;
    };
};