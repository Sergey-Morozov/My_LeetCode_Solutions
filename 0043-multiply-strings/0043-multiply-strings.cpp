// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string multiply(string num1, string num2) {
        if ((num1 == "0") || (num2 == "0"))
            return "0";
        string res = "";
        int n = num1.length();
        int m = num2.length();
        int carry = 0;
        for (int i = 0; i < n + m + 2; i++) {
            for (int j = min(i, n - 1); j >= max(0, i - m + 1); j--) {
                carry += (num1[n - 1 - j] - '0') * (num2[m - 1 - i + j] - '0');
            }
            res += (carry % 10) + '0';
            carry /= 10;
        }
        while (res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};