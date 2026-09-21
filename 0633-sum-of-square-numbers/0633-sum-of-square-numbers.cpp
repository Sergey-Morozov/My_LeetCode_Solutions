// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0)
            return true;
        long long int a = 0;
        long long int b = 0;
        while (b * b <= c)
            b++;
        while (b > a) {
            b--;
            while ((a + 1) * (a + 1) <= c - b * b)
                a++;
            if (a * a + b * b == c)
                return true;
        }
        return false;
    }
};