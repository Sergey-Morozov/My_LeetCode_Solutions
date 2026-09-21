// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int oddr = 0;
        int oddl = 0;
        int evenl = 0;
        int evenr = 0;
        int n = nums.size();
        if (n == 1)
            return 1;
        for (int i = 0; i < n - 1; i += 2) {
            evenr += nums[i];
            oddr += nums[i + 1];
        }
        if (n % 2 != 0)
            evenr += nums[n - 1];
        int res = 0;
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            if (i % 2 == 0) {
                if (evenl + oddr == oddl + evenr - t)
                    res++;
                evenl += t;
                evenr -= t;
            } else {
                if (evenl + oddr - t == oddl + evenr)
                    res++;
                oddr -= t;
                oddl += t;
            }
        }
        return res;
    }
};