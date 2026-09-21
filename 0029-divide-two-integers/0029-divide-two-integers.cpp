// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648)
            if (divisor == 1)
                return -2147483648;
            else if (divisor == -1)
                return 2147483647;
        if (divisor == 1) return dividend; else if (divisor == -1) return - dividend;
        int sign = 1;
        if ((dividend > 0) && (divisor < 0)) {
            sign = -1;
            dividend = -dividend;
        } else if ((dividend <= 0) && (divisor > 0)) {
            sign = -1;
            divisor = -divisor;
        } else if ((dividend >= 0) && (divisor > 0)) {
            dividend = -dividend;
            divisor = -divisor;
        };
        int res = 0;
        while (dividend <= divisor) {
            res++;
            dividend -= divisor;
        }
        if (sign == 1)
            return res;
        else
            return -res;
    };
};