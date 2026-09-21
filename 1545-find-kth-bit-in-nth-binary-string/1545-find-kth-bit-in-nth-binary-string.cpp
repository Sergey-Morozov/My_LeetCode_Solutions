// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1)
            return '0';
        int p = 1;
        bool inv = false;
        while (p <= k) {
            p <<= 1;
        }
        for (;;) {
            p >>= 1;
            if (p == k)
                return inv ? '0' : '1';
            else if (p < k) {
                inv = !inv;
                k = 2 * p - k;
                if (k == 1)
                    return inv ? '1' : '0';
            }
        }
    }
};