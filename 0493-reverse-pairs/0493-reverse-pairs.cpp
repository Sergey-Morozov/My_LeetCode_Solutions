// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int q = 1;
        vector<int> buff(n);
        int res = 0;
        while (q < n) {
            for (int i = 0; i <= n / (2 * q); i++) {
                int p1 = i * 2 * q;
                int p2 = p1 + q;
                int p3 = p1;
                int p4 = p1;
                int m = i * 2 * q + q;
                while (p3 < min(m + q, n)) {
                    if (p2 < min(m + q, n) && (p1 == m || nums[p2] < nums[p1])) {
                        buff[p3] = nums[p2];
                        if (nums[p2] < 1073741824) {
                            if (nums[p2] >= -1073741824)
                                while (nums[p4] <= nums[p2] * 2 &&
                                       p4 < m)
                                    p4++;
                        } else
                            p4 = m;
                        res += m - p4;
                        p2++;
                        p3++;
                    } else {
                        buff[p3] = nums[p1];
                        p1++;
                        p3++;
                    }
                }
            }
            swap(nums, buff);
            q <<= 1;
        }
        return res;
    }
};