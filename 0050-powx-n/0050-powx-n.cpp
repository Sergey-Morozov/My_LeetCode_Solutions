// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        if (n == INT_MIN) {
            res /= x;
            n++;
        }
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        while (n > 0) {
            if (n % 2 == 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
};