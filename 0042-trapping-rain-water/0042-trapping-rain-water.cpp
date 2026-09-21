// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int trap(vector<int>& height) {
        auto p1 = height.begin();
        auto p2 = --height.end();
        int lmax = *p1, rmax = *p2, res = 0;
        while (p1 != p2) {
            if (lmax <= rmax) {
                res += (lmax - *p1);
                ++p1;
                if (*p1 > lmax)
                    lmax = *p1;
            } else {
                res += (rmax - *p2);
                --p2;
                if (*p2 > rmax)
                    rmax = *p2;
            }
        }
        return (res);
    }
};